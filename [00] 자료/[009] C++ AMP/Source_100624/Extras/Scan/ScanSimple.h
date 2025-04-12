//===============================================================================
//
// Microsoft Press
// C++ AMP: Accelerated Massive Parallelism with Microsoft Visual C++
//
//===============================================================================
// Copyright (c) 2012 Ade Miller & Kate Gregory.  All rights reserved.
// This code released under the terms of the 
// Microsoft Public License (Ms-PL), http://ampbook.codeplex.com/license.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//===============================================================================

#pragma once

#include <amp.h>
#include <assert.h>

using namespace concurrency;

namespace Extras
{
    // http://www.csce.uark.edu/~mqhuang/courses/5013/f2011/lab/Lab-5-scan.pdf 

    // Exclusive scan, output element at i contains the sum of elements [0]...[i-1].

    template <typename InIt, typename OutIt>
    inline void PrescanAmpSimple(InIt first, InIt last, OutIt outFirst)
    {
        typedef InIt::value_type T;

        const int size = int(distance(first, last));
        concurrency::array<T, 1> in(size);
        concurrency::array<T, 1> out(size);
        copy(first, last, in);
        
		ScanAmpSimple(array_view<T, 1>(in), array_view<T, 1>(out));

		// Prescan is just an offset scan, so shift the results by one.
        copy(out.section(0, size - 1), outFirst + 1);
		*outFirst = T(0);
    }

    // Inclusive scan, output element at i contains the sum of elements [0]...[i].

    template <typename InIt, typename OutIt>
    inline void ScanAmpSimple(InIt first, InIt last, OutIt outFirst)
    {
        typedef InIt::value_type T;

        const int size = int(distance(first, last));
        concurrency::array<T, 1> in(size);
        concurrency::array<T, 1> out(size);
        copy(first, last, in);
        
        ScanAmpSimple(array_view<T, 1>(in), array_view<T, 1>(out));
        copy(out, outFirst);
    }

    template <typename T>
    void ScanAmpSimple(array_view<T, 1> input, array_view<T, 1> output)
    {
        assert(input.extent[0] == output.extent[0]);

        for (int offset = 1; offset < input.extent[0]; offset *= 2)
        {
            assert(input.extent[0] == output.extent[0]);
            assert(input.extent[0] % 2 == 0);
            output.discard_data();
            parallel_for_each(input.extent, [=](index<1> idx) restrict (amp)
            {
                if (idx[0] >= offset)
                    output[idx] = input[idx] + input[idx - offset];
                else
                    output[idx] = input[idx];
            });
            std::swap(input, output);
        }
    }
}
