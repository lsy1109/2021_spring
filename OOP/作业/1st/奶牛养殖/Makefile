main : main.o cow.o Farm.o
	g++ -o main main.o cow.o Farm.o

%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main main.o cow.o Farm.o