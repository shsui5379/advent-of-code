CXXFLAGS=-g

part1: part1.o inputUtils.o
	g++ -o part1 part1.o inputUtils.o

part2: part2.o inputUtils.o
	g++ -o part2 part2.o inputUtils.o


part1.o: part1.cpp ../commons/cpp/inputUtils.h

part2.o: part2.cpp ../commons/cpp/inputUtils.h


inputUtils.o: ../commons/cpp/inputUtils.cpp ../commons/cpp/inputUtils.h
	g++ -c ../commons/cpp/inputUtils.cpp


clean:
	rm -f *.o