BCB = $(MAKEDIR)\..
BCC32 = bcc32
LINKER = ilink32

USERDEFINES = _DEBUG
INCLUDEPATH = $(BCB)\include;..\chapter14
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib
CFLAG1 = -Od -Vx -Ve -X- -r- -a8 -b- -k -y -v -vi- -tWC -tWM- -c
LFLAGS = -D"" -ap -Tpe -x -Gn -v
SYSOBJ = c0x32.obj
SYSLIB = import32.lib cw32.lib

all:		main1.exe main2.exe

main2.exe:	main2.obj Pic.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) main2.obj Pic.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!

main1.exe:	main1.obj Pic.obj
    $(BCB)\BIN\$(LINKER) @&&! +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ) main1.obj Pic.obj, +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!


test:		all
	main1.exe
	main2.exe



# Say "make -fchapter00.bor clobber" to get rid of files created by nmake
clobber:
	del *.obj
	del *.exe
	del *.tds

# To convert a .cpp file to a .obj file, run the compiler with these options:
.cpp.obj:
	$(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n$(@D) {$< }

# To convert a collection of .obj files to a .exe file,
.obj.exe:
    $(BCB)\BIN\$(LINKER) @&&! +
	 $** +
    $(LFLAGS) -L$(LIBPATH) +
    $(SYSOBJ), +
    $&,, +
    $(SYSLIB), +
    $(DEFFILE), +
    $(ALLRES)
!