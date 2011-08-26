#
# Makefile for restclient-cpp
#

# set compiler and linker
CC = gcc
LD = gcc

# binaries and folders
BINDIR = bin
LIBDIR = lib
TEST = $(BINDIR)/test
LIBNAME = chinstrap.so
LIB = $(LIBDIR)/$(LIBNAME)
STATIC = $(LIBDIR)/chinstrap.a

# set library and include paths
INCLUDE =  -I. -I/usr/local/include
TESTLIBS = -lcheck -lyajl
LIBS =

# set compiler and linker flags
CCFLAGS = -fPIC -O3 -W -Wall
LDFLAGS = -W -Wall -L/usr/local/lib

# source files
SRCS =  src/scanner.c src/lexer.c src/parser.c

# test source files
TESTSRCS = $(SRCS)
TESTSRCS += $(wildcard tests/test_chinstrap.c)

# dependencies
# object files
OBJS = $(SRCS:.c=.o)
TESTOBJS = $(TESTSRCS:.c=.o)

# linking rule
$(TEST): $(TESTOBJS) $(BINDIR)
	$(LD) $(LDFLAGS) $(TESTOBJS) -o $(TEST) $(TESTLIBS)

# dynamic lib rule
$(LIB): $(OBJS) $(LIBDIR)
	$(LD) $(LDFLAGS) -shared -soname,$(LIBNAME) -o $(LIB) $(OBJS) $(LIBS)

# static lib rule
$(STATIC): $(OBJS) $(LIBDIR)
	ar rcs $(STATIC) $(OBJS)

# compile rule
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDE) -c $<  -o $@

$(BINDIR):
	@mkdir -p $(BINDIR)

$(LIBDIR):
	@mkdir -p $(LIBDIR)

# tasks
.PHONY:  clean

clean:
	@rm -rf tests/*.o
	@rm -rf src/*.o
	@rm -rf bin
	@rm -rf lib

test: $(TEST)
	@echo Running tests...
	@./bin/test

dynamiclibrary: $(LIB)

staticlibrary: $(STATIC)
