main : main.o product.o sum.o
	g++ -o main main.o product.o sum.o

main.o : main.cpp functions.h
	g++ $(FLAG) -c main.cpp

product.o : product.cpp functions.h
	g++ $(FLAG) -c product.cpp

sum.o : sum.cpp functions.h
	g++ $(FLAG) -c sum.cpp

clean :
	rm main main.o product.o sum.o