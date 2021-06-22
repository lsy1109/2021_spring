main : main.o Student.o StudentCollection.o
	g++ -o main main.o Student.o StudentCollection.o

Student.o : Student.cpp Student.h StudentCollection.h
	g++ -c Student.cpp

StudentCollection.o : StudentCollection.cpp Student.h StudentCollection.h
	g++ -c StudentCollection.cpp

main.o : main.cpp Student.h StudentCollection.h
	g++ -c main.cpp

clean : 
	rm main main.o Student.o StudentCollection.o