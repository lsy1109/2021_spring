main : Calculator.o LevelStrategy.o main.o PerformStrategy.o
	g++ -o main Calculator.o LevelStrategy.o main.o PerformStrategy.o -std=c++11 

%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main Calculator.o LevelStrategy.o main.o PerformStrategy.o

