#ifndef PE_FILE_HEADER
#define PE_FILE_HEADER

#include "minwindef.h"

#pragma pack (push, 1)

#define MY_IMAGE_DOS_SIGNATURE                 0x5A4D      // MZ
#define MY_IMAGE_OS2_SIGNATURE                 0x454E      // NE
#define MY_IMAGE_OS2_SIGNATURE_LE              0x454C      // LE
#define MY_IMAGE_VXD_SIGNATURE                 0x454C      // LE
#define MY_IMAGE_NT_SIGNATURE                  0x00004550  // PE00

typedef struct _MY_IMAGE_DOS_HEADER {    // DOS .EXE header
    WORD   e_magic;                     // Magic number
    WORD   e_cblp;                      // Bytes on last page of file
    WORD   e_cp;                        // Pages in file
    WORD   e_crlc;                      // Relocations
    WORD   e_cparhdr;                   // Size of header in paragraphs
    WORD   e_minalloc;                  // Minimum extra paragraphs needed
    WORD   e_maxalloc;                  // Maximum extra paragraphs needed
    WORD   e_ss;                        // Initial (relative) SS value
    WORD   e_sp;                        // Initial SP value
    WORD   e_csum;                      // Checksum
    WORD   e_ip;                        // Initial IP value
    WORD   e_cs;                        // Initial (relative) CS value
    WORD   e_lfarlc;                    // File address of relocation table
    WORD   e_ovno;                      // Overlay number
    WORD   e_res[4];                    // Reserved words
    WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
    WORD   e_oeminfo;                   // OEM information; e_oemid specific
    WORD   e_res2[10];                  // Reserved words
    LONG   e_lfanew;                    // File address of new exe header
  } MY_IMAGE_DOS_HEADER, *PMY_IMAGE_DOS_HEADER;


typedef struct _MY_IMAGE_FILE_HEADER {
    DWORD   Signature;
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} MY_IMAGE_FILE_HEADER, *PMY_IMAGE_FILE_HEADER;

#define MY_IMAGE_SIZEOF_FILE_HEADER             20

#define MY_IMAGE_FILE_RELOCS_STRIPPED           0x0001  // Relocation info stripped from file.
#define MY_IMAGE_FILE_EXECUTABLE_IMAGE          0x0002  // File is executable  (i.e. no unresolved externel references).
#define MY_IMAGE_FILE_LINE_NUMS_STRIPPED        0x0004  // Line nunbers stripped from file.
#define MY_IMAGE_FILE_LOCAL_SYMS_STRIPPED       0x0008  // Local symbols stripped from file.
#define MY_IMAGE_FILE_BYTES_REVERSED_LO         0x0080  // Bytes of machine word are reversed.
#define MY_IMAGE_FILE_32BIT_MACHINE             0x0100  // 32 bit word machine.
#define MY_IMAGE_FILE_DEBUG_STRIPPED            0x0200  // Debugging info stripped from file in .DBG file
#define MY_IMAGE_FILE_SYSTEM                    0x1000  // System File.
#define MY_IMAGE_FILE_DLL                       0x2000  // File is a DLL.
#define MY_IMAGE_FILE_BYTES_REVERSED_HI         0x8000  // Bytes of machine word are reversed.

#define MY_IMAGE_FILE_MACHINE_UNKNOWN           0
#define MY_IMAGE_FILE_MACHINE_I386              0x14c   // Intel 386.
#define MY_IMAGE_FILE_MACHINE_R3000             0x162   // MIPS little-endian, 0x160 big-endian
#define MY_IMAGE_FILE_MACHINE_R4000             0x166   // MIPS little-endian
#define MY_IMAGE_FILE_MACHINE_R10000            0x168   // MIPS little-endian
#define MY_IMAGE_FILE_MACHINE_ALPHA             0x184   // Alpha_AXP
#define MY_IMAGE_FILE_MACHINE_POWERPC           0x1F0   // IBM PowerPC Little-Endian

//
// Directory format.
//

typedef struct _MY_IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} MY_IMAGE_DATA_DIRECTORY, *PMY_IMAGE_DATA_DIRECTORY;

#define MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES    16

//
// Optional header format.
//

typedef struct _MY_IMAGE_OPTIONAL_HEADER {
    //
    // Standard fields.
    //
    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
    DWORD   BaseOfData;

    //
    // NT additional fields.
    //

    DWORD   ImageBase;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    MajorOperatingSystemVersion;
    WORD    MinorOperatingSystemVersion;
    WORD    MajorImageVersion;
    WORD    MinorImageVersion;
    WORD    MajorSubsystemVersion;
    WORD    MinorSubsystemVersion;
    DWORD   Reserved1;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   NumberOfRvaAndSizes;
    
    DWORD  dd_Export_dwVAddr     ;   // Export Directory Virtual Address
    DWORD  dd_Export_dwSize      ;   // Export Directory Size
    DWORD  dd_Import_dwVAddr     ;   // Import Directory Virtual Address
    DWORD  dd_Import_dwSize      ;   // Import Directory Size
    DWORD  dd_Resource_dwVAddr   ;   // Resource Directory Virtual Address
    DWORD  dd_Resource_dwSize    ;   // Resource Directory Size
    DWORD  dd_Exception_dwVAddr  ;   // Exception Directory Virtual Address
    DWORD  dd_Exception_dwSize   ;   // Exception Directory Size
    DWORD  dd_Security_dwVAddr   ;   // Security Directory Virtual Address
    DWORD  dd_Security_dwSize    ;   // Security Directory Size
    DWORD  dd_Basereloc_dwVAddr  ;   // Base Relocation Table Virtual Address
    DWORD  dd_Basereloc_dwSize   ;   // Base Relocation Table Size
    DWORD  dd_Debug_dwVAddr      ;   // Debug Directory Virtual Address
    DWORD  dd_Debug_dwSize       ;   // Debug Directory Size
    DWORD  dd_Copyright_dwVAddr  ;   // Description String Virtual Address
    DWORD  dd_Copyright_dwSize   ;   // Description String Size
    DWORD  dd_Globalptr_dwVAddr  ;   // Machine Value (MIPS GP) Virtual Address
    DWORD  dd_Globalptr_dwSize   ;   // Machine Value (MIPS GP) Size
    DWORD  dd_Tls_dwVAddr        ;   // TLS Directory Virtual Address
    DWORD  dd_Tls_dwSize         ;   // TLS Directory Size
    DWORD  dd_Load_config_dwVAddr;   // Load Configuration Directory Virtual Address
    DWORD  dd_Load_config_dwSize ;   // Load Configuration Directory Size
    DWORD  dd_Bound_import_dwVAddr;  // Bound Import Directory in headers Virtual Address
    DWORD  dd_Bound_import_dwSize;   // Bound Import Directory in headers Size
    DWORD  dd_Iat_dwVAddr        ;   // Import Address Table Virtual Address
    DWORD  dd_Iat_dwSize         ;   // Import Address Table Size
    DWORD  dd_Rsv[6];

} MY_IMAGE_OPTIONAL_HEADER, *PMY_IMAGE_OPTIONAL_HEADER;

typedef struct _MY_IMAGE_ROM_OPTIONAL_HEADER {
    WORD   Magic;
    BYTE   MajorLinkerVersion;
    BYTE   MinorLinkerVersion;
    DWORD  SizeOfCode;
    DWORD  SizeOfInitializedData;
    DWORD  SizeOfUninitializedData;
    DWORD  AddressOfEntryPoint;
    DWORD  BaseOfCode;
    DWORD  BaseOfData;
    DWORD  BaseOfBss;
    DWORD  GprMask;
    DWORD  CprMask[4];
    DWORD  GpValue;
} MY_IMAGE_ROM_OPTIONAL_HEADER, *PMY_IMAGE_ROM_OPTIONAL_HEADER;

#define MY_IMAGE_SIZEOF_ROM_OPTIONAL_HEADER      56
#define MY_IMAGE_SIZEOF_STD_OPTIONAL_HEADER      28
#define MY_IMAGE_SIZEOF_NT_OPTIONAL_HEADER      224

#define MY_IMAGE_NT_OPTIONAL_HDR_MAGIC        0x10b
#define MY_IMAGE_ROM_OPTIONAL_HDR_MAGIC       0x107

///////////////////////////////////////////////////////////////////////////
/**/ typedef struct _MY_IMAGE_PE_HEADER {									 //
/**/     MY_IMAGE_FILE_HEADER FileHeader;									 //
/**/     MY_IMAGE_OPTIONAL_HEADER OptionalHeader;							 //
/**/ } MY_IMAGE_PE_HEADER, *PMY_IMAGE_PE_HEADER;			    				 //
///////////////////////////////////////////////////////////////////////////
typedef struct _MY_IMAGE_ROM_HEADERS {
    MY_IMAGE_FILE_HEADER FileHeader;
    MY_IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
} MY_IMAGE_ROM_HEADERS, *PMY_IMAGE_ROM_HEADERS;

#define MY_IMAGE_FIRST_SECTION( ntheader ) ((PMY_IMAGE_SECTION_HEADER)        \
    ((DWORD)ntheader +                                                  \
     FIELD_OFFSET( MY_IMAGE_PE_HEADER, OptionalHeader ) +                 \
     ((PMY_IMAGE_PE_HEADER)(ntheader))->FileHeader.SizeOfOptionalHeader   \
    ))


// Subsystem Values

#define MY_IMAGE_SUBSYSTEM_UNKNOWN              0   // Unknown subsystem.
#define MY_IMAGE_SUBSYSTEM_NATIVE               1   // Image doesn't require a subsystem.
#define MY_IMAGE_SUBSYSTEM_WINDOWS_GUI          2   // Image runs in the Windows GUI subsystem.
#define MY_IMAGE_SUBSYSTEM_WINDOWS_CUI          3   // Image runs in the Windows character subsystem.
#define MY_IMAGE_SUBSYSTEM_OS2_CUI              5   // image runs in the OS/2 character subsystem.
#define MY_IMAGE_SUBSYSTEM_POSIX_CUI            7   // image run  in the Posix character subsystem.


// Directory Entries

#define MY_IMAGE_DIRECTORY_ENTRY_EXPORT         0   // Export Directory
#define MY_IMAGE_DIRECTORY_ENTRY_IMPORT         1   // Import Directory
#define MY_IMAGE_DIRECTORY_ENTRY_RESOURCE       2   // Resource Directory
#define MY_IMAGE_DIRECTORY_ENTRY_EXCEPTION      3   // Exception Directory
#define MY_IMAGE_DIRECTORY_ENTRY_SECURITY       4   // Security Directory
#define MY_IMAGE_DIRECTORY_ENTRY_BASERELOC      5   // Base Relocation Table
#define MY_IMAGE_DIRECTORY_ENTRY_DEBUG          6   // Debug Directory
#define MY_IMAGE_DIRECTORY_ENTRY_COPYRIGHT      7   // Description String
#define MY_IMAGE_DIRECTORY_ENTRY_GLOBALPTR      8   // Machine Value (MIPS GP)
#define MY_IMAGE_DIRECTORY_ENTRY_TLS            9   // TLS Directory
#define MY_IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG   10   // Load Configuration Directory
#define MY_IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT  11   // Bound Import Directory in headers
#define MY_IMAGE_DIRECTORY_ENTRY_IAT           12   // Import Address Table

//
// Section header format.
//

#define MY_IMAGE_SIZEOF_SHORT_NAME              8

typedef struct _MY_IMAGE_SECTION_HEADER {
    BYTE    Name[MY_IMAGE_SIZEOF_SHORT_NAME];
    //union {
    //        DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    //} Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    NumberOfRelocations;
    WORD    NumberOfLinenumbers;
    DWORD   Characteristics;
} MY_IMAGE_SECTION_HEADER, *PMY_IMAGE_SECTION_HEADER;

#define MY_IMAGE_SIZEOF_SECTION_HEADER          40

//
// Section characteristics.
//

//      MY_IMAGE_SCN_TYPE_REG                   0x00000000  // Reserved.
//      MY_IMAGE_SCN_TYPE_DSECT                 0x00000001  // Reserved.
//      MY_IMAGE_SCN_TYPE_NOLOAD                0x00000002  // Reserved.
//      MY_IMAGE_SCN_TYPE_GROUP                 0x00000004  // Reserved.
#define MY_IMAGE_SCN_TYPE_NO_PAD                0x00000008  // Reserved.
//      MY_IMAGE_SCN_TYPE_COPY                  0x00000010  // Reserved.

#define MY_IMAGE_SCN_CNT_CODE                   0x00000020  // Section contains code.
#define MY_IMAGE_SCN_CNT_INITIALIZED_DATA       0x00000040  // Section contains initialized data.
#define MY_IMAGE_SCN_CNT_UNINITIALIZED_DATA     0x00000080  // Section contains uninitialized data.

#define MY_IMAGE_SCN_LNK_OTHER                  0x00000100  // Reserved.
#define MY_IMAGE_SCN_LNK_INFO                   0x00000200  // Section contains comments or some other type of information.
//      MY_IMAGE_SCN_TYPE_OVER                  0x00000400  // Reserved.
#define MY_IMAGE_SCN_LNK_REMOVE                 0x00000800  // Section contents will not become part of image.
#define MY_IMAGE_SCN_LNK_COMDAT                 0x00001000  // Section contents comdat.
//                                           0x00002000  // Reserved.

//      MY_IMAGE_SCN_MEM_PROTECTED - Obsolete   0x00004000
#define MY_IMAGE_SCN_MEM_FARDATA                0x00008000
//      MY_IMAGE_SCN_MEM_SYSHEAP  - Obsolete    0x00010000
#define MY_IMAGE_SCN_MEM_PURGEABLE              0x00020000
#define MY_IMAGE_SCN_MEM_16BIT                  0x00020000
#define MY_IMAGE_SCN_MEM_LOCKED                 0x00040000
#define MY_IMAGE_SCN_MEM_PRELOAD                0x00080000

#define MY_IMAGE_SCN_ALIGN_1BYTES               0x00100000  //
#define MY_IMAGE_SCN_ALIGN_2BYTES               0x00200000  //
#define MY_IMAGE_SCN_ALIGN_4BYTES               0x00300000  //
#define MY_IMAGE_SCN_ALIGN_8BYTES               0x00400000  //
#define MY_IMAGE_SCN_ALIGN_16BYTES              0x00500000  // Default alignment if no others are specified.
#define MY_IMAGE_SCN_ALIGN_32BYTES              0x00600000  //
#define MY_IMAGE_SCN_ALIGN_64BYTES              0x00700000  //
// Unused                                    0x00800000

#define MY_IMAGE_SCN_LNK_NRELOC_OVFL            0x01000000  // Section contains extended relocations.
#define MY_IMAGE_SCN_MEM_DISCARDABLE            0x02000000  // Section can be discarded.
#define MY_IMAGE_SCN_MEM_NOT_CACHED             0x04000000  // Section is not cachable.
#define MY_IMAGE_SCN_MEM_NOT_PAGED              0x08000000  // Section is not pageable.
#define MY_IMAGE_SCN_MEM_SHARED                 0x10000000  // Section is shareable.
#define MY_IMAGE_SCN_MEM_EXECUTE                0x20000000  // Section is executable.
#define MY_IMAGE_SCN_MEM_READ                   0x40000000  // Section is readable.
#define MY_IMAGE_SCN_MEM_WRITE                  0x80000000  // Section is writeable.

//
// Symbol format.
//

typedef struct _MY_IMAGE_SYMBOL {
    union {
        BYTE    ShortName[8];
        struct {
            DWORD   Short;     // if 0, use LongName
            DWORD   Long;      // offset into string table
        } Name;
        PBYTE   LongName[2];
    } N;
    DWORD   Value;
    SHORT   SectionNumber;
    WORD    Type;
    BYTE    StorageClass;
    BYTE    NumberOfAuxSymbols;
} MY_IMAGE_SYMBOL;
typedef MY_IMAGE_SYMBOL UNALIGNED *PMY_IMAGE_SYMBOL;

#define MY_IMAGE_SIZEOF_SYMBOL                  18

//
// Section values.
//
// Symbols have a section number of the section in which they are
// defined. Otherwise, section numbers have the following meanings:
//

#define MY_IMAGE_SYM_UNDEFINED           (SHORT)0          // Symbol is undefined or is common.
#define MY_IMAGE_SYM_ABSOLUTE            (SHORT)-1         // Symbol is an absolute value.
#define MY_IMAGE_SYM_DEBUG               (SHORT)-2         // Symbol is a special debug item.

//
// Type (fundamental) values.
//

#define MY_IMAGE_SYM_TYPE_NULL                 0x0000  // no type.
#define MY_IMAGE_SYM_TYPE_VOID                 0x0001  //
#define MY_IMAGE_SYM_TYPE_CHAR                 0x0002  // type character.
#define MY_IMAGE_SYM_TYPE_SHORT                0x0003  // type short integer.
#define MY_IMAGE_SYM_TYPE_INT                  0x0004  //
#define MY_IMAGE_SYM_TYPE_LONG                 0x0005  //
#define MY_IMAGE_SYM_TYPE_FLOAT                0x0006  //
#define MY_IMAGE_SYM_TYPE_DOUBLE               0x0007  //
#define MY_IMAGE_SYM_TYPE_STRUCT               0x0008  //
#define MY_IMAGE_SYM_TYPE_UNION                0x0009  //
#define MY_IMAGE_SYM_TYPE_ENUM                 0x000A  // enumeration.
#define MY_IMAGE_SYM_TYPE_MOE                  0x000B  // member of enumeration.
#define MY_IMAGE_SYM_TYPE_BYTE                 0x000C  //
#define MY_IMAGE_SYM_TYPE_WORD                 0x000D  //
#define MY_IMAGE_SYM_TYPE_UINT                 0x000E  //
#define MY_IMAGE_SYM_TYPE_DWORD                0x000F  //
#define MY_IMAGE_SYM_TYPE_PCODE                0x8000  //

//
// Type (derived) values.
//

#define MY_IMAGE_SYM_DTYPE_NULL                0       // no derived type.
#define MY_IMAGE_SYM_DTYPE_POINTER             1       // pointer.
#define MY_IMAGE_SYM_DTYPE_FUNCTION            2       // function.
#define MY_IMAGE_SYM_DTYPE_ARRAY               3       // array.

//
// Storage classes.
//

#define MY_IMAGE_SYM_CLASS_END_OF_FUNCTION     (BYTE )-1
#define MY_IMAGE_SYM_CLASS_NULL                0x0000
#define MY_IMAGE_SYM_CLASS_AUTOMATIC           0x0001
#define MY_IMAGE_SYM_CLASS_EXTERNAL            0x0002
#define MY_IMAGE_SYM_CLASS_STATIC              0x0003
#define MY_IMAGE_SYM_CLASS_REGISTER            0x0004
#define MY_IMAGE_SYM_CLASS_EXTERNAL_DEF        0x0005
#define MY_IMAGE_SYM_CLASS_LABEL               0x0006
#define MY_IMAGE_SYM_CLASS_UNDEFINED_LABEL     0x0007
#define MY_IMAGE_SYM_CLASS_MEMBER_OF_STRUCT    0x0008
#define MY_IMAGE_SYM_CLASS_ARGUMENT            0x0009
#define MY_IMAGE_SYM_CLASS_STRUCT_TAG          0x000A
#define MY_IMAGE_SYM_CLASS_MEMBER_OF_UNION     0x000B
#define MY_IMAGE_SYM_CLASS_UNION_TAG           0x000C
#define MY_IMAGE_SYM_CLASS_TYPE_DEFINITION     0x000D
#define MY_IMAGE_SYM_CLASS_UNDEFINED_STATIC    0x000E
#define MY_IMAGE_SYM_CLASS_ENUM_TAG            0x000F
#define MY_IMAGE_SYM_CLASS_MEMBER_OF_ENUM      0x0010
#define MY_IMAGE_SYM_CLASS_REGISTER_PARAM      0x0011
#define MY_IMAGE_SYM_CLASS_BIT_FIELD           0x0012

#define MY_IMAGE_SYM_CLASS_FAR_EXTERNAL        0x0044  //

#define MY_IMAGE_SYM_CLASS_BLOCK               0x0064
#define MY_IMAGE_SYM_CLASS_FUNCTION            0x0065
#define MY_IMAGE_SYM_CLASS_END_OF_STRUCT       0x0066
#define MY_IMAGE_SYM_CLASS_FILE                0x0067
// new
#define MY_IMAGE_SYM_CLASS_SECTION             0x0068
#define MY_IMAGE_SYM_CLASS_WEAK_EXTERNAL       0x0069

// type packing constants

#define N_BTMASK                            0x000F
#define N_TMASK                             0x0030
#define N_TMASK1                            0x00C0
#define N_TMASK2                            0x00F0
#define N_BTSHFT                            4
#define N_TSHIFT                            2

// MACROS

// Basic Type of  x
#define BTYPE(x) ((x) & N_BTMASK)

// Is x a pointer?
#ifndef ISPTR
#define ISPTR(x) (((x) & N_TMASK) == (MY_IMAGE_SYM_DTYPE_POINTER << N_BTSHFT))
#endif

// Is x a function?
#ifndef ISFCN
#define ISFCN(x) (((x) & N_TMASK) == (MY_IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#endif

// Is x an array?

#ifndef ISARY
#define ISARY(x) (((x) & N_TMASK) == (MY_IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#endif

// Is x a structure, union, or enumeration TAG?
#ifndef ISTAG
#define ISTAG(x) ((x)==MY_IMAGE_SYM_CLASS_STRUCT_TAG || (x)==MY_IMAGE_SYM_CLASS_UNION_TAG || (x)==MY_IMAGE_SYM_CLASS_ENUM_TAG)
#endif

#ifndef INCREF
#define INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(MY_IMAGE_SYM_DTYPE_POINTER<<N_BTSHFT)|((x)&N_BTMASK))
#endif
#ifndef DECREF
#define DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#endif

//
// Auxiliary entry format.
//

// 내가 임의대로 만든 것.=================//
typedef struct {						  //
	long	lTagIndex;					  //
	long	lFuncSize;					  //
	long	lPtrToLineEnt;				  //
	long	lPtrToNextFunc;				  //
} MY_FUNC_AUX_SYMBOL;					  //
//========================================//

typedef union _MY_IMAGE_AUX_SYMBOL {
    struct {
        DWORD    TagIndex;                      // struct, union, or enum tag index
        union {
            struct {
                WORD    Linenumber;             // declaration line number
                WORD    Size;                   // size of struct, union, or enum
            } LnSz;
           DWORD    TotalSize;
        } Misc;
        union {
            struct {                            // if ISFCN, tag, or .bb
                DWORD    PointerToLinenumber;
                DWORD    PointerToNextFunction;
            } Function;
            struct {                            // if ISARY, up to 4 dimen.
                WORD     Dimension[4];
            } Array;
        } FcnAry;
        WORD    TvIndex;                        // tv index
    } Sym;
    struct {
        BYTE    Name[MY_IMAGE_SIZEOF_SYMBOL];
    } File;
    struct {
        DWORD   Length;                         // section length
        WORD    NumberOfRelocations;            // number of relocation entries
        WORD    NumberOfLinenumbers;            // number of line numbers
        DWORD   CheckSum;                       // checksum for communal
        SHORT   Number;                         // section number to associate with
        BYTE    Selection;                      // communal selection type
    } Section;
} MY_IMAGE_AUX_SYMBOL;
typedef MY_IMAGE_AUX_SYMBOL UNALIGNED *PMY_IMAGE_AUX_SYMBOL;

#define MY_IMAGE_SIZEOF_AUX_SYMBOL             18

//
// Communal selection types.
//

#define MY_IMAGE_COMDAT_SELECT_NODUPLICATES    1
#define MY_IMAGE_COMDAT_SELECT_ANY             2
#define MY_IMAGE_COMDAT_SELECT_SAME_SIZE       3
#define MY_IMAGE_COMDAT_SELECT_EXACT_MATCH     4
#define MY_IMAGE_COMDAT_SELECT_ASSOCIATIVE     5
#define MY_IMAGE_COMDAT_SELECT_LARGEST         6
#define MY_IMAGE_COMDAT_SELECT_NEWEST          7

#define MY_IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY  1
#define MY_IMAGE_WEAK_EXTERN_SEARCH_LIBRARY    2
#define MY_IMAGE_WEAK_EXTERN_SEARCH_ALIAS      3

//
// Relocation format.
//

typedef struct _MY_IMAGE_RELOCATION {
 //   union {
        DWORD   VirtualAddress;
//        DWORD   RelocCount;             // Set to the real count when MY_IMAGE_SCN_LNK_NRELOC_OVFL is set
//    };
    DWORD   SymbolTableIndex;
    WORD    Type;
} MY_IMAGE_RELOCATION;
typedef MY_IMAGE_RELOCATION UNALIGNED *PMY_IMAGE_RELOCATION;

#define MY_IMAGE_SIZEOF_RELOCATION         10

//
// I386 relocation types.
//

#define MY_IMAGE_REL_I386_ABSOLUTE         0x0000  // Reference is absolute, no relocation is necessary
#define MY_IMAGE_REL_I386_DIR16            0x0001  // Direct 16-bit reference to the symbols virtual address
#define MY_IMAGE_REL_I386_REL16            0x0002  // PC-relative 16-bit reference to the symbols virtual address
#define MY_IMAGE_REL_I386_DIR32            0x0006  // Direct 32-bit reference to the symbols virtual address
#define MY_IMAGE_REL_I386_DIR32NB          0x0007  // Direct 32-bit reference to the symbols virtual address, base not included
#define MY_IMAGE_REL_I386_SEG12            0x0009  // Direct 16-bit reference to the segment-selector bits of a 32-bit virtual address
#define MY_IMAGE_REL_I386_SECTION          0x000A
#define MY_IMAGE_REL_I386_SECREL           0x000B
#define MY_IMAGE_REL_I386_REL32            0x0014  // PC-relative 32-bit reference to the symbols virtual address

//
// MIPS relocation types.
//

#define MY_IMAGE_REL_MIPS_ABSOLUTE         0x0000  // Reference is absolute, no relocation is necessary
#define MY_IMAGE_REL_MIPS_REFHALF          0x0001
#define MY_IMAGE_REL_MIPS_REFWORD          0x0002
#define MY_IMAGE_REL_MIPS_JMPADDR          0x0003
#define MY_IMAGE_REL_MIPS_REFHI            0x0004
#define MY_IMAGE_REL_MIPS_REFLO            0x0005
#define MY_IMAGE_REL_MIPS_GPREL            0x0006
#define MY_IMAGE_REL_MIPS_LITERAL          0x0007
#define MY_IMAGE_REL_MIPS_SECTION          0x000A
#define MY_IMAGE_REL_MIPS_SECREL           0x000B
#define MY_IMAGE_REL_MIPS_SECRELLO         0x000C  // Low 16-bit section relative referemce (used for >32k TLS)
#define MY_IMAGE_REL_MIPS_SECRELHI         0x000D  // High 16-bit section relative reference (used for >32k TLS)
#define MY_IMAGE_REL_MIPS_REFWORDNB        0x0022
#define MY_IMAGE_REL_MIPS_PAIR             0x0025

//
// Alpha Relocation types.
//

#define MY_IMAGE_REL_ALPHA_ABSOLUTE        0x0000
#define MY_IMAGE_REL_ALPHA_REFLONG         0x0001
#define MY_IMAGE_REL_ALPHA_REFQUAD         0x0002
#define MY_IMAGE_REL_ALPHA_GPREL32         0x0003
#define MY_IMAGE_REL_ALPHA_LITERAL         0x0004
#define MY_IMAGE_REL_ALPHA_LITUSE          0x0005
#define MY_IMAGE_REL_ALPHA_GPDISP          0x0006
#define MY_IMAGE_REL_ALPHA_BRADDR          0x0007
#define MY_IMAGE_REL_ALPHA_HINT            0x0008
#define MY_IMAGE_REL_ALPHA_INLINE_REFLONG  0x0009
#define MY_IMAGE_REL_ALPHA_REFHI           0x000A
#define MY_IMAGE_REL_ALPHA_REFLO           0x000B
#define MY_IMAGE_REL_ALPHA_PAIR            0x000C
#define MY_IMAGE_REL_ALPHA_MATCH           0x000D
#define MY_IMAGE_REL_ALPHA_SECTION         0x000E
#define MY_IMAGE_REL_ALPHA_SECREL          0x000F
#define MY_IMAGE_REL_ALPHA_REFLONGNB       0x0010
#define MY_IMAGE_REL_ALPHA_SECRELLO        0x0011  // Low 16-bit section relative reference
#define MY_IMAGE_REL_ALPHA_SECRELHI        0x0012  // High 16-bit section relative reference

//
// IBM PowerPC relocation types.
//

#define MY_IMAGE_REL_PPC_ABSOLUTE          0x0000  // NOP
#define MY_IMAGE_REL_PPC_ADDR64            0x0001  // 64-bit address
#define MY_IMAGE_REL_PPC_ADDR32            0x0002  // 32-bit address
#define MY_IMAGE_REL_PPC_ADDR24            0x0003  // 26-bit address, shifted left 2 (branch absolute)
#define MY_IMAGE_REL_PPC_ADDR16            0x0004  // 16-bit address
#define MY_IMAGE_REL_PPC_ADDR14            0x0005  // 16-bit address, shifted left 2 (load doubleword)
#define MY_IMAGE_REL_PPC_REL24             0x0006  // 26-bit PC-relative offset, shifted left 2 (branch relative)
#define MY_IMAGE_REL_PPC_REL14             0x0007  // 16-bit PC-relative offset, shifted left 2 (br cond relative)
#define MY_IMAGE_REL_PPC_TOCREL16          0x0008  // 16-bit offset from TOC base
#define MY_IMAGE_REL_PPC_TOCREL14          0x0009  // 16-bit offset from TOC base, shifted left 2 (load doubleword)

#define MY_IMAGE_REL_PPC_ADDR32NB          0x000A  // 32-bit addr w/o image base
#define MY_IMAGE_REL_PPC_SECREL            0x000B  // va of containing section (as in an image sectionhdr)
#define MY_IMAGE_REL_PPC_SECTION           0x000C  // sectionheader number
#define MY_IMAGE_REL_PPC_IFGLUE            0x000D  // substitute TOC restore instruction iff symbol is glue code
#define MY_IMAGE_REL_PPC_IMGLUE            0x000E  // symbol is glue code; virtual address is TOC restore instruction
#define MY_IMAGE_REL_PPC_SECREL16          0x000F  // va of containing section (limited to 16 bits)
#define MY_IMAGE_REL_PPC_REFHI             0x0010
#define MY_IMAGE_REL_PPC_REFLO             0x0011
#define MY_IMAGE_REL_PPC_PAIR              0x0012

#define MY_IMAGE_REL_PPC_TYPEMASK          0x00FF  // mask to isolate above values in MY_IMAGE_RELOCATION.Type

// Flag bits in MY_IMAGE_RELOCATION.TYPE

#define MY_IMAGE_REL_PPC_NEG               0x0100  // subtract reloc value rather than adding it
#define MY_IMAGE_REL_PPC_BRTAKEN           0x0200  // fix branch prediction bit to predict branch taken
#define MY_IMAGE_REL_PPC_BRNTAKEN          0x0400  // fix branch prediction bit to predict branch not taken
#define MY_IMAGE_REL_PPC_TOCDEFN           0x0800  // toc slot defined in file (or, data in toc)

//
// Based relocation format.
//

typedef struct _MY_IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} MY_IMAGE_BASE_RELOCATION, *PMY_IMAGE_BASE_RELOCATION;

#define MY_IMAGE_SIZEOF_BASE_RELOCATION         8

//
// Based relocation types.
//

#define MY_IMAGE_REL_BASED_ABSOLUTE              0
#define MY_IMAGE_REL_BASED_HIGH                  1
#define MY_IMAGE_REL_BASED_LOW                   2
#define MY_IMAGE_REL_BASED_HIGHLOW               3
#define MY_IMAGE_REL_BASED_HIGHADJ               4
#define MY_IMAGE_REL_BASED_MIPS_JMPADDR          5

//
// Line number format.
//

typedef struct _MY_IMAGE_LINENUMBER {
    union {
        DWORD   SymbolTableIndex;               // Symbol table index of function name if Linenumber is 0.
        DWORD   VirtualAddress;                 // Virtual address of line number.
    } Type;
    WORD    Linenumber;                         // Line number.
} MY_IMAGE_LINENUMBER;
typedef MY_IMAGE_LINENUMBER UNALIGNED *PMY_IMAGE_LINENUMBER;

#define MY_IMAGE_SIZEOF_LINENUMBER              6

//
// Archive format.
//

#define MY_IMAGE_ARCHIVE_START_SIZE             8
#define MY_IMAGE_ARCHIVE_START                  "!<arch>\n"
#define MY_IMAGE_ARCHIVE_END                    "`\n"
#define MY_IMAGE_ARCHIVE_PAD                    "\n"
#define MY_IMAGE_ARCHIVE_LINKER_MEMBER          "/               "
#define MY_IMAGE_ARCHIVE_LONGNAMES_MEMBER       "//              "

typedef struct _MY_IMAGE_ARCHIVE_MEMBER_HEADER {
    BYTE     Name[16];                          // File member name - `/' terminated.
    BYTE     Date[12];                          // File member date - decimal.
    BYTE     UserID[6];                         // File member user id - decimal.
    BYTE     GroupID[6];                        // File member group id - decimal.
    BYTE     Mode[8];                           // File member mode - octal.
    BYTE     Size[10];                          // File member size - decimal.
    BYTE     EndHeader[2];                      // String to end header.
} MY_IMAGE_ARCHIVE_MEMBER_HEADER, *PMY_IMAGE_ARCHIVE_MEMBER_HEADER;

#define MY_IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR      60

//
// DLL support.
//

//
// Export Format
//

typedef struct _MY_IMAGE_EXPORT_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   Name;
    DWORD   Base;
    DWORD   NumberOfFunctions;
    DWORD   NumberOfNames;
    DWORD   *AddressOfFunctions;
    DWORD   *AddressOfNames;
    WORD    *AddressOfNameOrdinals;
} MY_IMAGE_EXPORT_DIRECTORY, *PMY_IMAGE_EXPORT_DIRECTORY;

//
// Import Format
//

typedef struct _MY_IMAGE_IMPORT_BY_NAME {
    WORD    Hint;
    BYTE    Name[1];
} MY_IMAGE_IMPORT_BY_NAME, *PMY_IMAGE_IMPORT_BY_NAME;

typedef struct _MY_IMAGE_THUNK_DATA {
    union {
        PBYTE  ForwarderString;
        PDWORD Function;
        DWORD Ordinal;
        PMY_IMAGE_IMPORT_BY_NAME AddressOfData;
    } u1;
} MY_IMAGE_THUNK_DATA, *PMY_IMAGE_THUNK_DATA;

#define MY_IMAGE_ORDINAL_FLAG 0x80000000
#define MY_IMAGE_SNAP_BY_ORDINAL(Ordinal) ((Ordinal & MY_IMAGE_ORDINAL_FLAG) != 0)
#define MY_IMAGE_ORDINAL(Ordinal) (Ordinal & 0xffff)

typedef struct _MY_IMAGE_IMPORT_DESCRIPTOR {
    DWORD   *pILTRVA;			// Import할 함수 이름이 저장된 주소 테이블
	DWORD   rsv;
    DWORD   dwTotalEnt;			// IAT의 Entry 개수
    char	*pNameRVA;			// 모듈명 RVA
	DWORD   *pIATRVA;			// Import할 함수 주소를 저장할 주소 테이블
} MY_IMAGE_IMPORT_DESCRIPTOR, *PMY_IMAGE_IMPORT_DESCRIPTOR;

/*
typedef struct _MY_IMAGE_IMPORT_DESCRIPTOR {
//    union {
        DWORD   Characteristics;                // 0 for terminating null import descriptor
//        PMY_IMAGE_THUNK_DATA OriginalFirstThunk;   // RVA to original unbound IAT
//    };
    DWORD   TimeDateStamp;                  // 0 if not bound,
                                            // -1 if bound, and real date\time stamp
                                            //     in MY_IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
                                            // O.W. date/time stamp of DLL bound to (Old BIND)

    DWORD   ForwarderChain;                 // -1 if no forwarders
    DWORD   Name;
//    PMY_IMAGE_THUNK_DATA FirstThunk;           // RVA to IAT (if bound this IAT has actual addresses)
	DWORD   FirstThunk;  // 여기다가 파일에서의 오프셋을 계산해서 임의대로 넣을 것이다.

} MY_IMAGE_IMPORT_DESCRIPTOR, *PMY_IMAGE_IMPORT_DESCRIPTOR;
*/

//
// New format import descriptors pointed to by DataDirectory[ MY_IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT ]
//

typedef struct _MY_IMAGE_BOUND_IMPORT_DESCRIPTOR {
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    NumberOfModuleForwarderRefs;
// Array of zero or more MY_IMAGE_BOUND_FORWARDER_REF follows
} MY_IMAGE_BOUND_IMPORT_DESCRIPTOR, *PMY_IMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef struct _MY_IMAGE_BOUND_FORWARDER_REF {
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    Reserved;
} MY_IMAGE_BOUND_FORWARDER_REF, *PMY_IMAGE_BOUND_FORWARDER_REF;


//
// Thread Local Storage
//
/*
typedef VOID
(NTAPI *PMY_IMAGE_TLS_CALLBACK) (
    PVOID DllHandle,
    DWORD Reason,
    PVOID Reserved
    );

typedef struct _MY_IMAGE_TLS_DIRECTORY {
    DWORD   StartAddressOfRawData;
    DWORD   EndAddressOfRawData;
    PDWORD  AddressOfIndex;
    PMY_IMAGE_TLS_CALLBACK *AddressOfCallBacks;
    DWORD   SizeOfZeroFill;
    DWORD   Characteristics;
} MY_IMAGE_TLS_DIRECTORY, *PMY_IMAGE_TLS_DIRECTORY;
*/

//
// Resource Format.
//

//
// Resource directory consists of two counts, following by a variable length
// array of directory entries.  The first count is the number of entries at
// beginning of the array that have actual names associated with each entry.
// The entries are in ascending order, case insensitive strings.  The second
// count is the number of entries that immediately follow the named entries.
// This second count identifies the number of entries that have 16-bit integer
// Ids as their name.  These entries are also sorted in ascending order.
//
// This structure allows fast lookup by either name or number, but for any
// given resource entry only one form of lookup is supported, not both.
// This is consistant with the syntax of the .RC file and the .RES file.
//

typedef struct _MY_IMAGE_RESOURCE_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    WORD    NumberOfNamedEntries;
    WORD    NumberOfIdEntries;
//  MY_IMAGE_RESOURCE_DIRECTORY_ENTRY DirectoryEntries[];
} MY_IMAGE_RESOURCE_DIRECTORY, *PMY_IMAGE_RESOURCE_DIRECTORY;

#define MY_IMAGE_RESOURCE_NAME_IS_STRING        0x80000000
#define MY_IMAGE_RESOURCE_DATA_IS_DIRECTORY     0x80000000

//
// Each directory contains the 32-bit Name of the entry and an offset,
// relative to the beginning of the resource directory of the data associated
// with this directory entry.  If the name of the entry is an actual text
// string instead of an integer Id, then the high order bit of the name field
// is set to one and the low order 31-bits are an offset, relative to the
// beginning of the resource directory of the string, which is of type
// MY_IMAGE_RESOURCE_DIRECTORY_STRING.  Otherwise the high bit is clear and the
// low-order 16-bits are the integer Id that identify this resource directory
// entry. If the directory entry is yet another resource directory (i.e. a
// subdirectory), then the high order bit of the offset field will be
// set to indicate this.  Otherwise the high bit is clear and the offset
// field points to a resource data entry.
//

typedef struct _MY_IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union {
        struct {
            DWORD NameOffset:31;
            DWORD NameIsString:1;
        };
        DWORD   Name;
        WORD    Id;
    };
    union {
        DWORD   OffsetToData;
        struct {
            DWORD   OffsetToDirectory:31;
            DWORD   DataIsDirectory:1;
        };
    };
} MY_IMAGE_RESOURCE_DIRECTORY_ENTRY, *PMY_IMAGE_RESOURCE_DIRECTORY_ENTRY;

//
// For resource directory entries that have actual string names, the Name
// field of the directory entry points to an object of the following type.
// All of these string objects are stored together after the last resource
// directory entry and before the first resource data object.  This minimizes
// the impact of these variable length objects on the alignment of the fixed
// size directory entry objects.
//

typedef struct _MY_IMAGE_RESOURCE_DIRECTORY_STRING {
    WORD    Length;
    CHAR    NameString[ 1 ];
} MY_IMAGE_RESOURCE_DIRECTORY_STRING, *PMY_IMAGE_RESOURCE_DIRECTORY_STRING;


typedef struct _MY_IMAGE_RESOURCE_DIR_STRING_U {
    WORD    Length;
    WCHAR   NameString[ 1 ];
} MY_IMAGE_RESOURCE_DIR_STRING_U, *PMY_IMAGE_RESOURCE_DIR_STRING_U;


//
// Each resource data entry describes a leaf node in the resource directory
// tree.  It contains an offset, relative to the beginning of the resource
// directory of the data for the resource, a size field that gives the number
// of bytes of data at that offset, a CodePage that should be used when
// decoding code point values within the resource data.  Typically for new
// applications the code page would be the unicode code page.
//

typedef struct _MY_IMAGE_RESOURCE_DATA_ENTRY {
    DWORD   OffsetToData;
    DWORD   Size;
    DWORD   CodePage;
    DWORD   Reserved;
} MY_IMAGE_RESOURCE_DATA_ENTRY, *PMY_IMAGE_RESOURCE_DATA_ENTRY;

//
// Load Configuration Directory Entry
//

typedef struct _MY_IMAGE_LOAD_CONFIG_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   GlobalFlagsClear;
    DWORD   GlobalFlagsSet;
    DWORD   CriticalSectionDefaultTimeout;
    DWORD   DeCommitFreeBlockThreshold;
    DWORD   DeCommitTotalFreeThreshold;
    PVOID   LockPrefixTable;
    DWORD   MaximumAllocationSize;
    DWORD   VirtualMemoryThreshold;
    DWORD   ProcessHeapFlags;
    DWORD   Reserved[ 4 ];
} MY_IMAGE_LOAD_CONFIG_DIRECTORY, *PMY_IMAGE_LOAD_CONFIG_DIRECTORY;


//
// Function table entry format for MIPS/ALPHA images.  Function table is
// pointed to by the MY_IMAGE_DIRECTORY_ENTRY_EXCEPTION directory entry.
// This definition duplicates ones in ntmips.h and ntalpha.h for use
// by portable image file mungers.
//

typedef struct _MY_IMAGE_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    PVOID ExceptionHandler;
    PVOID HandlerData;
    DWORD PrologEndAddress;
} MY_IMAGE_RUNTIME_FUNCTION_ENTRY, *PMY_IMAGE_RUNTIME_FUNCTION_ENTRY;

//
// Debug Format
//

typedef struct _MY_IMAGE_DEBUG_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   Type;
    DWORD   SizeOfData;
    DWORD   AddressOfRawData;
    DWORD   PointerToRawData;
} MY_IMAGE_DEBUG_DIRECTORY, *PMY_IMAGE_DEBUG_DIRECTORY;

#define MY_IMAGE_DEBUG_TYPE_UNKNOWN          0
#define MY_IMAGE_DEBUG_TYPE_COFF             1
#define MY_IMAGE_DEBUG_TYPE_CODEVIEW         2
#define MY_IMAGE_DEBUG_TYPE_FPO              3
#define MY_IMAGE_DEBUG_TYPE_MISC             4
#define MY_IMAGE_DEBUG_TYPE_EXCEPTION        5
#define MY_IMAGE_DEBUG_TYPE_FIXUP            6
#define MY_IMAGE_DEBUG_TYPE_OMAP_TO_SRC      7
#define MY_IMAGE_DEBUG_TYPE_OMAP_FROM_SRC    8

typedef struct _MY_IMAGE_COFF_SYMBOLS_HEADER {
    DWORD   NumberOfSymbols;
    DWORD   LvaToFirstSymbol;
    DWORD   NumberOfLinenumbers;
    DWORD   LvaToFirstLinenumber;
    DWORD   RvaToFirstByteOfCode;
    DWORD   RvaToLastByteOfCode;
    DWORD   RvaToFirstByteOfData;
    DWORD   RvaToLastByteOfData;
} MY_IMAGE_COFF_SYMBOLS_HEADER, *PMY_IMAGE_COFF_SYMBOLS_HEADER;

#define FRAME_FPO       0
#define FRAME_TRAP      1
#define FRAME_TSS       2
#define FRAME_NONFPO    3

typedef struct _MY_FPO_DATA {
    DWORD       ulOffStart;             // offset 1st byte of function code
    DWORD       cbProcSize;             // # bytes in function
    DWORD       cdwLocals;              // # bytes in locals/4
    WORD        cdwParams;              // # bytes in params/4
    WORD        cbProlog : 8;           // # bytes in prolog
    WORD        cbRegs   : 3;           // # regs saved
    WORD        fHasSEH  : 1;           // TRUE if SEH in func
    WORD        fUseBP   : 1;           // TRUE if EBP has been allocated
    WORD        reserved : 1;           // reserved for future use
    WORD        cbFrame  : 2;           // frame type
} MY_FPO_DATA, *PMY_FPO_DATA;
#define SIZEOF_RMY_FPO_DATA 16


#define MY_IMAGE_DEBUG_MISC_EXENAME    1

typedef struct _MY_IMAGE_DEBUG_MISC {
    DWORD       DataType;               // type of misc data, see defines
    DWORD       Length;                 // total length of record, rounded to four
                                        // byte multiple.
    BOOLEAN     Unicode;                // TRUE if data is unicode string
    BYTE        Reserved[ 3 ];
    BYTE        Data[ 1 ];              // Actual data
} MY_IMAGE_DEBUG_MISC, *PMY_IMAGE_DEBUG_MISC;


//
// Function table extracted from MIPS/ALPHA images.  Does not contain
// information needed only for runtime support.  Just those fields for
// each entry needed by a debugger.
//

typedef struct _MY_IMAGE_FUNCTION_ENTRY {
    DWORD   StartingAddress;
    DWORD   EndingAddress;
    DWORD   EndOfPrologue;
} MY_IMAGE_FUNCTION_ENTRY, *PMY_IMAGE_FUNCTION_ENTRY;

//
// Debugging information can be stripped from an image file and placed
// in a separate .DBG file, whose file name part is the same as the
// image file name part (e.g. symbols for CMD.EXE could be stripped
// and placed in CMD.DBG).  This is indicated by the MY_IMAGE_FILE_DEBUG_STRIPPED
// flag in the Characteristics field of the file header.  The beginning of
// the .DBG file contains the following structure which captures certain
// information from the image file.  This allows a debug to proceed even if
// the original image file is not accessable.  This header is followed by
// zero of more MY_IMAGE_SECTION_HEADER structures, followed by zero or more
// MY_IMAGE_DEBUG_DIRECTORY structures.  The latter structures and those in
// the image file contain file offsets relative to the beginning of the
// .DBG file.
//
// If symbols have been stripped from an image, the MY_IMAGE_DEBUG_MISC structure
// is left in the image file, but not mapped.  This allows a debugger to
// compute the name of the .DBG file, from the name of the image in the
// MY_IMAGE_DEBUG_MISC structure.
//

#define MY_IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944

typedef struct _MY_IMAGE_SEPARATE_DEBUG_HEADER {
    WORD        Signature;
    WORD        Flags;
    WORD        Machine;
    WORD        Characteristics;
    DWORD       TimeDateStamp;
    DWORD       CheckSum;
    DWORD       ImageBase;
    DWORD       SizeOfImage;
    DWORD       NumberOfSections;
    DWORD       ExportedNamesSize;
    DWORD       DebugDirectorySize;
    DWORD       Reserved[ 3 ];          // Note: reserved[0] is actually the section alignment
} MY_IMAGE_SEPARATE_DEBUG_HEADER, *PMY_IMAGE_SEPARATE_DEBUG_HEADER;

/////////////////////////////////////////////////////////////////////////////////
#define BDF_MAX_PE_SECTION 16

typedef struct {
    char szName[9];					// 섹션이름 기본 8자 + 0
	int  nType;						// 섹션 타입(알려진 것이면 거기에 맞게 RawData를 처리해 준다.)
	LONG lBase;						// 섹션 베이스
	MY_IMAGE_SECTION_HEADER *pPtr;	// 섹션 정보를 가리키는 포인터
} SectStt;							// 각 섹션을 다루기 위한 구조체

#define MAX_EXPORT 256
typedef struct {
	char  szName[128];	// 함수의 이름 
	DWORD dwVAddr;		// 함수의 가상 어드레스
	WORD  wOrdinal;		// Ordinal Number
	LONG  lBase;		// 파일 선두기준으로 함수의 위치
	LONG  lSize;		// 함수부터 코드 섹션의 끝까지의 위치 또는 바로 다음 함수까지의 크기
} ExportStt;

typedef enum {
	BIMG_TYPE_COM = 1,		// 도스 COM파일
	BIMG_TYPE_DOS_EXE,		// 도스 EXE파일
	BIMG_TYPE_PE			// 32 bit PE파일

} BELLONA_IMAGE_TYPE_TAG;

// 각 섹션에 대한 타입
typedef enum {
	SECT_TEXT = 0,
	SECT_RDATA,
	SECT_DATA,
	SECT,IDATA,
	SECT_RELOC,
	END_OF_SECT
} SectionTypeTag;

typedef struct {
	int		nType;				// 파일의 종류가 어떤 종류인가.
	char	szFileName[260];	// 패스를 제외한 순수 파일명
	long	lFileSize;			// 읽어들인 이미지 크기
	long	lImageSize;			// 재배치한 후의 이미지 크기 (스택은 제외된다.)
	long	lMemSize;			// 할당한 메모리 크기  (이미지 크기 + 스택 크기)
	
	DWORD	dwNewImageBase;
	UCHAR	*pBase;				// 재배치해서 옮겨갈 베이스 주소
	UCHAR	*pBuff;				// 이미지를 읽어들인 버퍼 주소
	
	LONG	lPeBase;			// Pe Header의 Base Offset
	LONG	lIfBase;			// Image file HEader의 Base Offset
	LONG	lIoBase;			// Image Optional Header의 BAse Offset

	SectStt sect[BDF_MAX_PE_SECTION];  // 각 섹션 
	int		nRelocSect;				   // 재배치 섹션의 번호. 

	MY_IMAGE_DOS_HEADER 	 *pDosHd; // 도스 헤더 주소
	MY_IMAGE_PE_HEADER  	 *pPeHd;  // PE 파일 헤더 주소.	(IMAGE_FILE_HEADER와 IMAGE_OPTIONAL_HEADER루 구성된다.)
	MY_IMAGE_FILE_HEADER     *pIfHd ; // IMAGE_FILE_HEADER
	MY_IMAGE_OPTIONAL_HEADER *pIoHd;	// IMAGE_OPTIONAL_HEADER

} PeImgStt;
#pragma pack (pop)
#endif

