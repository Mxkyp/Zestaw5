#Directory and system
.SUFFIXES: .c .cpp .o .x .h
DIR=$(notdir $(CURDIR))
SYSNAME =$(shell uname -s)


#Compiler & Linker
CO=g++
LD=$(CO)

#header files
HEADS1=canvas.h
HEADS2=figures.h

#file names 
NAME1=main
NAME2=canvas
NAME3=figures
NAME4=deltoid
NAME5=triangle
NAME6=rectangle

#C++ Source files
CPPFILE1=$(NAME1).cpp
CPPFILE2=$(NAME2).cpp
CPPFILE3=$(NAME3).cpp
CPPFILE4=$(NAME4).cpp
CPPFILE5=$(NAME5).cpp
CPPFILE6=$(NAME6).cpp

#1st file argv values
ARG1=text.txt

#output files:
TEXT1=obrazek.txt

#OBJECT FILES
OBJS1=$(NAME1).o

#EXECUTABLE FILES
EXEC1=$(NAME1).x
EXEC2=$(NAME1).x

#flags
#CFLAGS =-Wall -Wextra -std=c++20 -Wno-unused-variable -fmax-errors=1 -Wno-unused-parameter -fsanitize=address -D_GLIBCXX_DEBUG -Wpedantic -O  //development flags
#LFLAGS =-Wall -Wextra -std=c++20 -Wno-unused-variable -fmax-errors=1 -Wno-unused-parameter -fsanitize=address -D_GLIBCXX_DEBUG -Wpedantic -O
CFLAGS = -std=c++20 
LFLAGS = -std=c++20
#========================================

all: $(EXEC1) $(HEADS2) $(HEADS3) 

$(EXEC1): $(CPPFILE1) $(CPPFILE2) $(CPPFILE3) $(CPPFILE4) $(CPPFILE5) $(CPPFILE6) $(HEADS2) $(HEADS3)
	$(CO) -o $@ $^

#======================================
#Example startup options
run: $(EXEC1) $(HEADS3) $(HEADS2) $(ARG1)
	rm -r $(TEXT1) &
	sleep 1 &
	touch $(TEXT1)
	./$(EXEC1) $(ARG1)
#=====================================================
clean:
	rm *.x *.o $(TEXT1) 
ob:
	cat $(TEXT1)
tar: 
	(cd ../; tar -cvzf $(DIR).tar.gz --exclude .git --exclude "*.log" $(DIR))
