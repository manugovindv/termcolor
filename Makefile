#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

# define the Cpp compiler to use
#use full path to use minGW compiler
CC = C:\MinGW\bin\g++.exe

# define any compile-time flags
CFLAGS = -Wall -Wextra -g


# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =


# define output directory
OUTPUT	:= build

# define source directory
SRC		:= src

# define include directory
INCLUDE	:= include

OBJECT	:= obj

# define lib directory
LIB		:= lib


COLOR	:= colo.exe

OUTPUTMAIN = $(OUTPUT)\$(COLOR)

MD	:= mkdir
# SHELL=cmd /C


all: build
	@echo Executing 'all' complete!
	

build: $(OBJECT) colors.o main.o
	$(CC) $(OBJECT)\colors.o $(OBJECT)\main.o -o $(OUTPUTMAIN)
	@echo Executing 'build' complete!

$(OBJECT):
	$(MD) $(OUTPUT)

colors.o: $(LIB)\colors.cpp $(INCLUDE)\colors.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(LIB)\colors.cpp -o $(OBJECT)\colors.o

main.o: $(SRC)\main.cpp colors.o
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)\main.cpp -o $(OBJECT)\main.o

clean:
	cmd /C "del /q /f $(OBJECT)\*.o"

run: all
	$(OUTPUTMAIN)
	@echo $(OUTPUTMAIN)
	@echo Executing 'run: all' complete!