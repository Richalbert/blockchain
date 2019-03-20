#
# fichier makefile 
#
# http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
#
# cible: dependances
#	commande
#
# $@ : The file name of the target of the rule
# $^ : The names of all the prerequisites, with spaces between them
# $< : The name of the first prerequisite
#

CC = g++
CFLAGS = -W -Wall -std=c++11 -pedantic
LDFLAGS =
EXEC = main
SRC = $(wildcard *.cpp)		# * est le wildcard
HFILE = $(wildcard *.h)	
OBJ = $(SRC:.cpp=.o)		# on remplace les cpp par des o

#all: $(EXEC)
#
#main depend de tous les .o
#main: $(OBJ)
#	$(CC) -o $@ $^ $(LDFLAGS)
#
# les .o dependent de ...
# compile sans l edition de lien
#main.o: $(SRC)
#	$(CC) -o $@ -c $< $(CFLAGS)
#
#%.o: %.cpp
#	$(CC) -o $@ -c $< $(CFLAGS)

all: main

main: main.o Block.o
	g++ -o main main.o Block.o -W -Wall -std=c++11 -pedantic 

main.o: main.cpp
	g++ -o main.o -c main.cpp -W -Wall -std=c++11 -pedantic 
	

Block.o: Block.cpp
	g++ -o Block.o -c Block.cpp -W -Wall -std=c++11 -pedantic 


.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -f $(EXEC) *.txt
