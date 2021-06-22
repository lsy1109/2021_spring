main:Calculator.cpp LevelStrategy.cpp main.cpp PerformStrategy.cpp
	g++ Calculator.cpp LevelStrategy.cpp main.cpp PerformStrategy.cpp -o main
%.o: %.cpp
	g++ -c -o $@ $<
Calculator.o: Calculator.h Calculator.cpp LevelStrategy.h PerformStrategy.h
	g++ -g -c -std=c++11 -o Calculator.o Calculator.cpp
LevelStrategy.o: LevelStrategy.h LevelStrategy.cpp
	g++ -g -c -std=c++11 -o LevelStrategy.o
PerformStrategy.o: PerformStrategy.h PerformStrategy.cpp
	g++ -g -c -std=c++11 -o PerformStrategy.o
clean: 
	rm main *.o

