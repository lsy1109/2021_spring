main : CustomClass.o Object.o main.o
	g++ -o main  CustomClass.o Object.o main.o -std=c++11 

%.o: %.cpp
	g++ -c -o $@ $<

CustomClass.o:CustomClass.h
	g++ -c CustomClass.h -o CustomClass.o

Object.o:Object.h CustomClass.h
	g++ -c Object.h CustomClass.h -o Object.o

clean: 
	rm main CustomClass.o Object.o main.o