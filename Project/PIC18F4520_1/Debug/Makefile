###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = PIC18F4520
COMPILER = "MPLAB C18"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
CCFLAGS=-I="..\..\..\..\..\..\..\Program Files (x86)\Microchip\mplabc18\v3.47\h" -p18f4520
LDFLAGS=-u_CRUNTIME -l"..\..\..\..\..\..\..\Program Files (x86)\Microchip\mplabc18\v3.47\lib" -x -p18f4520

## Processing Tools
CC=mcc18.exe
ASM=c:/mcc18/mpasm/MPASMWIN.exe
LD=mplink.exe
LIB=mplib.exe
#  C:/Users/micha_5j3z6p3/Desktop/Proteus/Project/PIC18F4520_1/Debug/Debug.cof: TOOL=LD

# Build tree:
all:	Debug

Debug:	Debug.cof

Debug.cof:	
	$(LD) $(LDFLAGS) 18f4520_g.lkr -o"Debug.cof" %INFILES_QUOTED%

# tidy - delete all temporary files which are not involved in the target generation
tidy:

# cleanup - delete all generated files
clean:	tidy
