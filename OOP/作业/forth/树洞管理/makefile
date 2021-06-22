main : Container.o main.o
	g++ -o main Container.o main.o -std=c++11 

%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main Container.o main.o

