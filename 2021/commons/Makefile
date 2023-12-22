tests: tests.o inputProcessing.o
	g++ -o tests tests.o inputProcessing.o

tests.o: tests.cpp inputProcessing.h

inputProcessing.o: inputProcessing.cpp inputProcessing.h

clean:
	rm -f *.o