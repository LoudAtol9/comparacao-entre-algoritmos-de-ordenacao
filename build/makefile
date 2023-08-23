
PROJDIR := ..
SOURCEDIR := $(PROJDIR)/source
BUILDDIR := $(PROJDIR)/build
MAINDIR := $(SOURCEDIR)/sorts/benchmark

OBJECTS = $(SOURCEDIR)/sorts/*.c $(SOURCEDIR)/sorts/test/*.c $(SOURCEDIR)/utils/*.c $(MAINDIR)/*.c

RESULT = benchmark.exe

COMPILER = gcc

all:
	$(COMPILER) -g $(OBJECTS) -o $(RESULT)

