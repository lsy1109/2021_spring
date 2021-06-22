main : main.o Parser.o
	g++ -o main main.o Parser.o

%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main main.o Parser.o