ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libltdl src

win32:
	make
	mkdir -p win/win32
	cp ./src/.lib/amoroso.dll ./win/win32
	cp ./src/.lib/amoroso.dll.a ./win/win32
	cp ./src/.lib/amoroso.la ./win/win32

win64:
	make
	mkdir -p win/win64
	cp ./src/.lib/amoroso.dll ./win/win64
	cp ./src/.lib/amoroso.dll.a ./win/win32
	cp ./src/.lib/amoroso.la ./win/win64
