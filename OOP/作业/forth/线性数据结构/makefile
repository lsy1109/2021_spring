main : IteratorBase.o LinearDataStruct.o Queue.o Stack.o main.o
	g++ -o main IteratorBase.o LinearDataStruct.o Queue.o Stack.o main.o -std=c++11 

%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main IteratorBase.o LinearDataStruct.o Queue.o Stack.o main.o
