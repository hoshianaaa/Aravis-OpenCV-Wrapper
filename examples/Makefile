# sample make file.

CC=g++
MAIN_C = main3.cpp
#ADDN=Camera.cpp

INCLUDES= -I/home/hoshina/aravis/src/ -I/home/hoshina/aravis/build/src/ -I/usr/include/glib-2.0/ -I/usr/lib/x86_64-linux-gnu/glib-2.0/include 

LINKAGES=-L/usr/lib -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/ -L/home/hoshina/aravis/src/libaravis-0.8.so	-laravis-0.8 -lglib-2.0 -lm -pthread -lgio-2.0 -lgobject-2.0 -lxml2 -lgthread-2.0 -lglib-2.0 -lz -lusb-1.0  -lpng 

PKGS=`pkg-config --cflags --libs opencv` 
PKGS2=`pkg-config --cflags --libs opencv4` 
PKGS3=`pkg-config --cflags --libs roscpp` 
PKGS4=`pkg-config --cflags --libs image_transport` 

all:
	$(CC) -o main $(MAIN_C) $(ADDN) $(INCLUDES) $(LINKAGES) $(PKGS) $(PKGS2) $(PKGS3) $(PKG4)
