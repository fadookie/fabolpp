#fabolpp.o: fabolpp.cpp
#	g++ -c fabolpp.cpp

#bar.o: bar.c
#	gcc -c bar.c

#all: foo.o bar.o
#	gcc foo.o bar.o -app

all:
	g++ -g -c fabolpp.cpp
	g++ -g fabolpp.o -o fabolpp
#-g is debug mode

autorun:
	g++ -c fabolpp.cpp
	g++ fabolpp.o -o fabolpp
	echo -e "\n"
	./fabolpp
clean:
	rm fabolpp fabolpp.o

#A better makefile
#CC=g++
#CFLAGS='-Wall -g'
#OBJS=fabolpp.o

#app: $(OBJS)
#    $(CC) $(CFLAGS) $(OBJS) -o app

#all: app
