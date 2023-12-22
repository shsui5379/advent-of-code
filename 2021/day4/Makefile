part1: part1.o BingoBoard.o inputProcessing.o
	g++ -o part1 part1.o BingoBoard.o inputProcessing.o

part2: part2.o BingoBoard.o inputProcessing.o
	g++ -o part2 part2.o BingoBoard.o inputProcessing.o


test1: test1.o BingoBoard.o
	g++ -o test1 test1.o BingoBoard.o


part1.o: part1.cpp BingoBoard.h

part2.o: part2.cpp BingoBoard.h

test1.o: test1.cpp BingoBoard.h


BingoBoard.o: BingoBoard.cpp BingoBoard.h BingoSpace.h

inputProcessing.o: ../commons/inputProcessing.cpp ../commons/inputProcessing.h
	g++ -c ../commons/inputProcessing.cpp


clean:
	rm -f *.o