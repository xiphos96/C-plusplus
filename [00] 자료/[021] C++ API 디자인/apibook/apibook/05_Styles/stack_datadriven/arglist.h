///
/// \file   arglist.h
/// \author Martin Reddy
/// \brief  A container for flexibly-typed scalar values.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///
/// Thanks to Max Chatfield for noting that the ArgList::Add()
/// function needed a "const char *" overloaded version to avoid the
/// compiler choosing the "bool" version when using a static string.
///
/// Also note that if you're using C++17, you could simply use
/// the new std::any type, e.g.,
///
///   using Arg = std::any;
///   using ArgList = std::map<std::string, Arg>;
///

#ifndef ARGLIST_H
#define ARGLIST_H

#include <map>
#include <string>

namespace apibook {

class Arg
{
public:
    // constructor, destructor, copy constructor, and assignment
    Arg();
    ~Arg();
    Arg(const Arg &);
    Arg &operator=(const Arg &other);

    // constructors to initialize with a value
    explicit Arg(bool value);
    explicit Arg(int value);
    explicit Arg(double value);
    explicit Arg(const std::string &value);

    // set the arg to be empty/undefined/nullptr
    void Clear();

    // change the current value
    void Set(bool value);
    void Set(int value);
    void Set(double value);
    void Set(const std::string &value);

    // test the type of the current value
    bool Empty() const;
    bool ContainsBool() const;
    bool ContainsInt() const;
    bool ContainsDouble() const;
    bool ContainsString() const;

    // can the current value be returned as another type
    bool CanCovertToBool() const;
    bool CanCovertToInt() const;
    bool CanCovertToDouble() const;
    bool CanCovertToString() const;

    // return the current value as a specific type
    bool ToBool() const;
    int ToInt() const;
    double ToDouble() const;
    std::string ToString() const;

public:
    class Base;

private:
    Base *mImpl;
};

typedef std::map<std::string, Arg> ArgDict;

class ArgList
{
public:
    ArgList();

    Arg Get(const std::string &name) const;
    size_t Size() const;
    ArgList &Add(const std::string &name, bool value);
    ArgList &Add(const std::string &name, int value);
    ArgList &Add(const std::string &name, double value);
    ArgList &Add(const std::string &name, const char *value);
    ArgList &Add(const std::string &name, const std::string &value);

private:
    std::map<std::string, Arg> mMap;
};

}  // namespace apibook

#endif
