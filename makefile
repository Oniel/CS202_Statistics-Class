#Oniel Toledo   Assignment_10 makefile   CS202
#Make file for main.cpp and statisticsPkg.h class file.
#Because the class will be a template there will be no 
#implementation file object file to be created. The 
#executable will use main.o which will get object from
#statisticsPkg which contains class info and definition

#current compiler: g++
cc = g++
#object files, only one main.o
OBJS = main.o
#the header file is the only dependency since the 
#functions are all templates
DEPS1 = statisticsPkg.h

all: main
#main is the target OBJS are the depency list
main: $(OBJS)
	$(cc) -o main $(OBJS)
main.o: main.cpp $(DEPS1)
	$(cc) -c -g main.cpp
clean:
	rm $(OBJS)	
