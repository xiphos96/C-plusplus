#ifndef _MAP_FILE_SECTION_H
#define _MAP_FILE_SECTION_H
#include <minwindef.h>
#include <string>
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

#ifndef MAPFILEDLL_API
#ifdef MAPFILEDLL_EXPORTS
#define MAPFILEDLL_API __declspec(dllexport)
#else
#define MAPFILEDLL_API __declspec(dllimport)
#endif
#endif

class MapFileAddress;

class MapFileSection
{
public:
	MAPFILEDLL_API MapFileSection(std::string &p_name);

	MAPFILEDLL_API MapFileSection();

	MAPFILEDLL_API ~MapFileSection();

	MAPFILEDLL_API void setName(std::string	&p_name)
	{
		name = p_name;
	}

	MAPFILEDLL_API void getName(std::string	&p_name)
	{
		p_name = name;
	}

	MAPFILEDLL_API void setClassName(std::string	&p_name)
	{
		className = p_name;
	}

	MAPFILEDLL_API void getClassName(std::string	&p_name)
	{
		p_name = className;
	}

	MAPFILEDLL_API void setAddress(MapFileAddress	*a)
	{
		address = a;
	}

	MAPFILEDLL_API MapFileAddress *getAddress()
	{
		return address;
	}

	MAPFILEDLL_API void setLength(DWORD	l)
	{
		length = l;
	}

	MAPFILEDLL_API DWORD getLength()
	{
		return length;
	}

private:
	std::string			name;
	MapFileAddress	*address;
	std::string			className;
	DWORD			length;
};

#endif
