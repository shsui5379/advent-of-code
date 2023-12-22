part1: part1.o funcs-1.o stdinToStringVector.o
	g++ -o part1 part1.o funcs-1.o stdinToStringVector.o

part2: part2.o funcs-1.o stdinToStringVector.o funcs-2.o
	g++ -o part2 part2.o funcs-1.o stdinToStringVector.o funcs-2.o

tests1: funcstest-1.o funcs-1.o
	g++ -o tests1 funcstest-1.o funcs-1.o

tests2: tests2.o funcs-2.o funcs-1.o
	g++ -o tests2 tests2.o funcs-2.o funcs-1.o


part1.o: part1.cpp ../commons/stdinToStringVector.h funcs-1.h

part2.o: part2.cpp ../commons/stdinToStringVector.h funcs-1.h funcs-2.h

funcs-1.o: funcs-1.cpp funcs-1.h

funcstest-1.o: funcstest-1.cpp funcs-1.h

tests2.o: tests2.cpp funcs-1.h funcs-2.h

stdinToStringVector.o: ../commons/stdinToStringVector.cpp ../commons/stdinToStringVector.h
	g++ -c ../commons/stdinToStringVector.cpp


clean:
	rm -f *.o