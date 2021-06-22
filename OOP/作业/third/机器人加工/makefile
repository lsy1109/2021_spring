main : main.o Part.o Robot.o Alice.o Bob.o
	g++ -o main main.o Part.o Robot.o Alice.o Bob.o -std=c++11 

%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main main.o Part.o Robot.o Alice.o Bob.o
