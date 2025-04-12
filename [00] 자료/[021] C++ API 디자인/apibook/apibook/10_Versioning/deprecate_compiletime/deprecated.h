///
/// \file   deprecate.h
/// \author Martin Reddy
/// \brief  Give compile warnings for deprecated functionality.
///
/// Copyright (c) 2010-2024, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See https://APIBook.com/ for the latest version.
///

#ifndef DEPRECATE_H
#define DEPRECATE_H

// cross-platform macro to mark a function or class as deprecated
#if __has_cpp_attribute(deprecated)
#define DEPRECATED [[deprecated]]
#elif defined(__GNUC__) || defined(__clang__)
#define DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED __declspec(deprecated)
#else
#define DEPRECATED
#pragma message("DEPRECATED is not defined for this compiler")
#endif

#endif
