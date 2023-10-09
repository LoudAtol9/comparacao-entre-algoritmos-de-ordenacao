
PROJDIR := ..
SOURCEDIR := $(PROJDIR)/source
BUILDDIR := $(PROJDIR)/build

SORTS = $(SOURCEDIR)/sorts
UTILS = $(SOURCEDIR)/utils/*.c 

POSFIX = _sort.exe

COMPILER = gcc

all:
	$(COMPILER) -g $(UTILS) $(SORTS)/bubble_sort.c -o bubble$(POSFIX)
	$(COMPILER) -g $(UTILS) $(SORTS)/insertion_sort.c -o insertion$(POSFIX)
	$(COMPILER) -g $(UTILS) $(SORTS)/selection_sort.c -o selection$(POSFIX)
	$(COMPILER) -g $(UTILS) $(SORTS)/heap_sort.c -o heap$(POSFIX)
	$(COMPILER) -g $(UTILS) $(SORTS)/merge_sort.c -o merge$(POSFIX)
	$(COMPILER) -g $(UTILS) $(SORTS)/quick_sort.c -o quick$(POSFIX)

