//----------------------------------------
// Copyright (c) 2001 Object Media Limited
// (Un-Published Material)
//
// Object Media Limited
// 24 Windmill Walk
// Sutton
// Ely 
// Cambs
// CB6 2NH
// United Kingdom
//
// snail@objmedia.demon.co.uk
//
//----------------------------------------
// Author:  Stephen Kellett
// Date:    16/Sept/2001
//
// Purpose: 
//----------------------------------------

//----------------------------------------
// License:
//
// You may use this source code in any product, commercial, shareware, or freeware. 
//
// You MUST not impose a GNU style license on this software. If it is going to be 
// free for the use of all, it must not have a GNU, or similar style license imposed 
// on it. That is, you may take this source code and embed as part of a commercial 
// product without the requirement to then disclose the source code you added to 
// create your proprietry product. 
//
// You can give away the source code and/or the binary executable.
//
// You can sell for profit the binary executable.
//
// You can not sell the source code that accompanies this license. You may charge a reasonable fee for
// copying the source code.
//
// You can not include this source code in a magazine, CD, or other storage media that is distributed
// on a for-profit basis without the written (on paper) permission of Object Media Limited. Source code 
// and software developer centred websites such as www.codeproject.com may host the source code, but may
// not sell the source code on a CD.
//
// You MUST keep this license in the source code, and keep the copyright notice at the top of 
// this file that identifies Object Media Limited as the original author of this source code.
//----------------------------------------

#include "MapFileAddress.h"
#include "MapFileLineNumber.h"
#include "MapFileLineNumberFile.h"
#include "stringdef.h"
#include "sprintf.h"
//-NAME---------------------------------
//.DESCRIPTION..........................
//.PARAMETERS...........................
//.RETURN.CODES.........................
//--------------------------------------

MapFileLineNumberFile::MapFileLineNumberFile(std::string	&p_name)
{
	setName(p_name);
}

//-NAME---------------------------------
//.DESCRIPTION..........................
//.PARAMETERS...........................
//.RETURN.CODES.........................
//--------------------------------------

MapFileLineNumberFile::MapFileLineNumberFile()
{
}

//-NAME---------------------------------
//.DESCRIPTION..........................
//.PARAMETERS...........................
//.RETURN.CODES.........................
//--------------------------------------

MapFileLineNumberFile::~MapFileLineNumberFile()
{
	int					i, n;
	MapFileLineNumber	*fln;

	n = lineNumbers.size();
	for(i = 0; i < n; i++)
	{
		fln = (MapFileLineNumber *)lineNumbers[i];
		delete fln;
	}

	lineNumbers.clear();
}

//-NAME---------------------------------
//.DESCRIPTION..........................
//.PARAMETERS...........................
//.RETURN.CODES.........................
//--------------------------------------

int MapFileLineNumberFile::addLineNumber(std::string	&lineNumber,
	std::string	&sectionAddress)
{
	int					ln;
	MapFileAddress		*addr;
	MapFileLineNumber	*fln;

	ln = (int)strtoul(lineNumber.c_str(), NULL, 10);		// line numbers are base 10, 0 is not valid

	addr = new MapFileAddress(sectionAddress.c_str());
	fln = new MapFileLineNumber(ln, addr);

	lineNumbers.push_back(fln);

	return TRUE;
}
