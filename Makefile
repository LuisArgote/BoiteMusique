### This file may be edited to adapt to your project ###

# Base name for the main program
PROGNAME = prog

# List of assembly source (.S) files
ASMS =

# List of assembly includes (optional)
ASMDEPS =

# List of C source files (.c)
SRCS = src/boot/startup.c src/boot/interrupts.c
SRCS += src/sys/clock.c src/sys/power.c src/sys/serial_io.c
SRCS += src/sys/init.c src/sys/syscalls.c

#Mes fonctions
SRCS +=  src/sys/notes.c src/sys/timer.c src/sys/musique.c


SRCS += src/main.c

# List of C header files (optional)
CDEPS = src/sys/clock.h src/sys/power.h src/sys/serial_io.h
CDEPS += src/sys/init.h src/sys/devices.h
CDEPS += src/sys/cm4.h src/sys/cmsis_gcc.h

#Mes fonctions
CDEPS +=  src/sys/notes.h src/sys/timer.h src/sys/musique.h

# List of additional includes (directories)
DIRFLAGS += 

# List of C++ source files (.cpp)
CPPSRCS =

# List of C++ deps (optional)
CPPDEPS =

# C source file where CRC info will be stored
CRCSRC =
#CRCSRC = src/boot/crc_info.c

# Name of linker program (change gcc to g++ if linking C++ files)
LINKER = gcc
#LINKER = g++

### Do not remove the line below ###
include stm32-rules.make
