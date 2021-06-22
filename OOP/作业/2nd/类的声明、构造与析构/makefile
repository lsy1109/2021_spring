main : main.o Example.o
	g++ -o main main.o Example.o
%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main main.o Example.o