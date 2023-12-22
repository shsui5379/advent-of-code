part1: part1.o Floor.o inputProcessing.o
	g++ -o part1 part1.o Floor.o inputProcessing.o

 
test1: test1.o Floor.o
	g++ -o test1 test1.o Floor.o


part1.o: part1.cpp Floor.h ../commons/inputProcessing.h

test1.o: test1.cpp Floor.h

Floor.o: Floor.cpp Floor.h

inputProcessing.o: ../commons/inputProcessing.cpp ../commons/inputProcessing.h
	g++ -c ../commons/inputProcessing.cpp


clean:
	rm -f *.o