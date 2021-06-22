main : main.o School.o Student.o
	g++ -o main main.o School.o Student.o -std=c++11 
%.o: %.cpp
	g++ -c -o $@ $<

clean: 
	rm main main.o Student.o School.o