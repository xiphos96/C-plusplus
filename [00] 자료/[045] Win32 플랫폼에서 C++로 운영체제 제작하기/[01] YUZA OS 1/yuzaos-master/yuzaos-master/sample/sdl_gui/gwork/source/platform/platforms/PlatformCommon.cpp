/*
 *  Gwork
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#include <Gwork/PlatformCommon.h>
#include <Gwork/Platform.h>
#include <Gwork/Utility.h>

#include <stdlib.h>
#include <eastl/map.h>
#include <ostringstream>

#include "DebugBreak.h"

using namespace Gwk;

//------------------------------------------------------------------------------

Gwk::Platform::RelativeToExecutablePaths::RelativeToExecutablePaths(String const& resourceDir)
:   m_resDir(Gwk::Platform::GetExecutableDir() + resourceDir)
{}

String Gwk::Platform::RelativeToExecutablePaths::GetPath(Type type, String const& filename)
{
    String filepath(m_resDir + filename);

    if (type == Type::Font)
    {
        // TODO: bit hacky this...
        if (filepath.find(".ttf") == eastl::string::npos)
            filepath += ".ttf";
    }

    return filepath;
}

//------------------------------------------------------------------------------

namespace Gwk { namespace Platform {
    extern void DefaultLogListener(Log::Level lvl, const char *message);
}}

static Log::LogListener g_logListener = &Gwk::Platform::DefaultLogListener;

void Log::Write(Level lvl, const char *format, ...)
{
    char buff[512];
    const char *logname[] = { "INFO", "WARNING", "ERROR", "FATAL" };
    int slen = Utility::snprintf(buff, sizeof(buff), "[%s] ", logname[(int)lvl]);

    va_list argList;
    va_start(argList, format);
    const int mlen = Utility::vsnprintf_gwk(buff + slen, sizeof(buff) - slen, format, argList);
    va_end(argList);

    if (slen+mlen < sizeof(buff)-2)
    {
        buff[slen+mlen] = '\n';
        buff[slen+mlen+1] = '\0';
    }
    g_logListener(lvl, buff);
}

Log::LogListener SetLogListener(Log::LogListener listener)
{
    auto old = g_logListener;
    g_logListener = listener;
    return old;
}

void Gwk::Debug::AssertFail(const char* strMsg)
{
    Log::Write(Log::Level::Fatal, "Assert: %s\n", strMsg);
    
    debug_break();  // break into debugger
}

//==============================================================================

#if GWK_ALLOC_STATS

static Platform::AllocStats g_stats;

const Platform::AllocStats& Platform::GetAllocStats()
{
    return g_stats;
}

//------------------------------------------------------------------------------

namespace {

// Based on: http://stackoverflow.com/a/439876/3233

// Custom allocator avoiding new
template<typename T>
struct MallocAllocator : std::allocator<T>
{
    typedef typename std::allocator<T>::pointer pointer;
    typedef typename std::allocator<T>::size_type size_type;

    template<typename U>
    struct rebind {
        typedef MallocAllocator<U> other;
    };

    MallocAllocator() {}

    template<typename U>
    MallocAllocator(MallocAllocator<U> const& u)
    :   std::allocator<T>(u) {}

    pointer allocate(size_type size, std::allocator<void>::const_pointer = 0)
    {
        void * p = std::malloc(size * sizeof(T));
        if(p == 0)
            throw std::bad_alloc();

        return static_cast<pointer>(p);
    }

    void deallocate(pointer p, size_type)
    {
        std::free(p);
    }
};

typedef std::map< void*, std::size_t, std::less<void*>,
                  MallocAllocator< std::pair<void* const, std::size_t> > > TrackerMemMap;

struct AllocReporter
{
    TrackerMemMap *track;

    AllocReporter(TrackerMemMap *track) : track(track) {}

    ~AllocReporter()
    {
        TrackerMemMap::const_iterator it = track->begin();
        while (it != track->end())
        {
            std::cerr << "TRACK: leaked at " << it->first << ", " << it->second << " bytes\n";
            ++it;
        }
    }
};

static TrackerMemMap* GetAllocTracker()
{
    // don't use normal new to avoid infinite recursion.
    static TrackerMemMap *track = new (std::malloc(sizeof *track)) TrackerMemMap;
    static AllocReporter printer(track);
    return track;
}

struct Mark
{
    const char * const name;
    Platform::AllocStats stats;
};

typedef std::vector<Mark, MallocAllocator<Mark>> MarksType;
MarksType g_marks;

} // namespace {

//----------------------------------------------------------------------------------

void Platform::AllocStatsAddMark(const char * const name)
{
    Mark m = { name, Platform::GetAllocStats() };
    g_marks.emplace_back(m);;
}

void Platform::AllocStatsDump(FILE *fh)
{
    fprintf(fh, "Mark,CumNumAllocs,CumAllocSize,CurrNumAllocs,CurrAllocSize\n");
    for (auto&& m : g_marks)
    {
        fprintf(fh, "%s,%ld,%ld,%ld,%ld\n", m.name,
                m.stats.cumulativeNumAllocs, m.stats.cumulativeAllocBytes,
                m.stats.currentNumAllocs, m.stats.currentAllocBytes);
    }
}

//------------------------------------------------------------------------------

// These are declared in Config.h, which should be included everywhere.

void* operator new(std::size_t size) throw(std::bad_alloc)
{
    // we are required to return non-null
    void *mem = std::malloc(size == 0 ? 1 : size);
    if (mem == 0)
        throw std::bad_alloc();

    ++g_stats.currentNumAllocs;
    ++g_stats.cumulativeNumAllocs;
    g_stats.currentAllocBytes += size;
    g_stats.cumulativeAllocBytes += size;
    (*GetAllocTracker())[mem] = size;

    return mem;
}

void operator delete(void *mem) throw()
{
    TrackerMemMap *trk = GetAllocTracker();
    auto it = trk->find(mem);

    if (it != trk->end())
    {
        const std::size_t size = it->second;

        --g_stats.currentNumAllocs;
        g_stats.currentAllocBytes -= size;

        trk->erase(it);
    }
    else
    {
        // this indicates a serious bug
        std::cerr << "bug: memory at " << mem << " wasn't allocated by us\n";
    }

    std::free(mem);
}

#endif // GWK_ALLOC_STATS
