// thumbnail.cpp
//
// Copyright (c) 2003 Philip Romanik, Amy Muntz
//
// Permission to use, copy, modify, distribute, and sell this software and
// its documentation for any purpose is hereby granted without fee, provided
// that (i) the above copyright notices and this permission notice appear in
// all copies of the software and related documentation, and (ii) the names
// of Philip Romanik and Amy Muntz may not be used in any advertising or
// publicity relating to the software without the specific, prior written
// permission of Philip Romanik and Amy Muntz.
//
// Use of this software and/or its documentation will be deemed to be
// acceptance of these terms.
//
// THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
// EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
// WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
//
// IN NO EVENT SHALL PHILIP ROMANIK OR AMY MUNTZ BE LIABLE FOR
// ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
// OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF
// LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
//
//  Simple stand-alone thumbnail generator program


#include "thumbnail.h"

#include <stdio.h>
#include <memory.h>

#include <iostream>
#include <iomanip>        // setw() manipulator


// Ruler
//       1         2         3         4         5         6    6
//345678901234567890123456789012345678901234567890123456789012345



/*****************
 *               *
 *  apThumbNail  *
 *               *
 *****************/

apThumbNail::apThumbNail () 
{}


apThumbNail::~apThumbNail () 
{}


void apThumbNail::createThumbNail (const char* inputFile,
                                   const char* outputFile,
				                           int factor)
{
  // Validate the arguments
  if (inputFile == 0 || outputFile == 0 ||
      factor <= 1)
    throw invalid ();

  // Read the source image
  readImage (inputFile);
  if (!image_.isValid())
    throw invalid ();

  // Create our internal thumbnail image
  thumbnail_ = apImage (image_.width()  / factor,
                        image_.height() / factor);

  unsigned char pixel;

  // Turn any rangeErrors from apImage into our invalid error
  try {
    for (int y=0; y<thumbnail_.height(); y++) {
      for (int x=0; x<thumbnail_.width(); x++) {
        // Convert to image_ coordinates to find the average
        pixel = averagePixels (x*factor, y*factor, factor);
        thumbnail_.setPixel (x, y, pixel);
      }
    }
  }
  catch (apImage::rangeError) {
    throw invalid ();
  }
  
  writeImage (outputFile);
}


unsigned char apThumbNail::averagePixels (int x0, int y0, 
                                          int factor)
{
  int sum = 0;

  // Average factor x factor pixels in the input image
  try {
    for (int y=0; y<factor; y++) {
      for (int x=0; x<factor; x++)
        sum += image_.getPixel (x+x0, y+y0);
    }
  }
  catch (apImage::rangeError) {
    throw invalid ();
  }

  // This cast is very safe
  return static_cast<unsigned char>(sum / (factor * factor));
}



void apThumbNail::readImage  (const char* /*inputFile*/)
{
  // We'll discuss this step later.  For now just assume that
  // the image is read from the file and placed in the image
  // as a two dimensional array of data. The following code
  // will create a synthetic 64x64 image.

  image_ = apImage (64, 64);

  try {
    for (int y=0; y<image_.height(); y++)
      for (int x=0; x<image_.width(); x++)
        image_.setPixel (x, y, (unsigned char)(y % 255));
  }
  catch (apImage::rangeError) {
    throw invalid ();
  }


}

void apThumbNail::writeImage  (const char* /*outputFile*/) const
{
  // We'll discuss this step later.  For now just assume that
  // the thumnail image is written to the file.  The following
  // code will display the image as hex values
  // We will also exercise our assignment operator;
  apImage output;
  output = thumbnail_;

  // Save formatting state of stream
  std::ios_base::fmtflags flags = std::cout.flags (std::cout.hex);
  int width = std::cout.width (2);

  for (int y=0; y<output.height(); y++) {
    for (int x=0; x<output.width(); x++)
      // (int) makes sure we are displayed as a number, not a char.
      std::cout << (int) output.getPixel (x, y) << " ";
    std::cout << std::endl;
  }

  std::cout.flags (flags);
  std::cout.width (width);
}
