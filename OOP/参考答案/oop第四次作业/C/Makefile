main:main.o Container.o
	g++ *.o -o main
main.o:main.cpp
	g++ -c main.cpp -o main.o
Container.o:Container.h Container.cpp
	g++ -c Container.cpp -o Container.o
clean:
	rm *.o main