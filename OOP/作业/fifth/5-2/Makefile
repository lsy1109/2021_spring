main : main.o
	g++ -o main main.o -std=c++11 

%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main main.o