## @file Makefile
## @author Tina Eghdam Zamiri
## @date Aug 03, 2022
## @brief Makefile for compiling traffic model

CXX = g++
CXXFLAGS = -std=c++14

## build:	compile the code into an executable
build:	functions.o
	${CXX} ${CXXFLAGS} -o $@ $^

## functions.o:    compile functions.cpp into an object file.
functions.o: functions.cpp funcions.h
	${CXX} ${CXXFLAGS} -c -o $@ $^


## clean: Remove auto-generated files.
.PHONY: clean
clean:
	rm *.o

PHONY: help
help:	Makefile
	@sed -n 's/^##//p' $<

