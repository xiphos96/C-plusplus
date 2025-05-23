#include <minwindef.h>
#include <minwinconst.h>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <winapi.h>
#include <systemcall_impl.h>
#include "GUIConsoleFramework.h"

extern "C" int main_impl(int argc, char** argv);

int main(int argc, char** argv)
{
	GUIConsoleFramework framework;
	framework.Run(argc, argv, main_impl);
}