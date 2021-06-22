main : main.o func.o
	g++ -o main main.o func.o

main.o : main.cpp func.cpp
	g++ -c main.cpp

func.o : main.cpp func.cpp
	g++ -c func.cpp

clean : 
	rm main main.o func.o