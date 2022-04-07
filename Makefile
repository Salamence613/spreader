spreader.out : spreader.o spreaderRunner.o
	g++ -ansi -Wall -pg -g -o spreader.out spreader.o spreaderRunner.o

spreader.o : spreader.cpp spreader.h
	g++ -ansi -Wall -pg -g -c spreader.cpp

spreaderRunner.o : spreaderRunner.cpp CPUTimer.h spreaderRunner.h spreader.h
	g++ -ansi -Wall -pg -g -c spreaderRunner.cpp

clean :
	rm -f spreader.out spreader.o  spreaderRunner.o
