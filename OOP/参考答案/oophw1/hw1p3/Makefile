main : main.o Student.o ClassSystem.o
	g++ -o main main.o Student.o ClassSystem.o

main.o : main.cpp Student.h ClassSystem.h
	g++ -c main.cpp

Student.o : Student.cpp Student.h
	g++ -c Student.cpp

ClassSystem.o : ClassSystem.cpp ClassSystem.h
	g++ -c ClassSystem.cpp

clean : 
	rm main.o main Student.o ClassSystem.o