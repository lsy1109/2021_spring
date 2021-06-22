main : main.o car.o vehicle.o motor.o wheel.o engine.o
	g++ -o main *.o

wheel.o : wheel.cpp wheel.h
	g++ -c wheel.cpp

engine.o : engine.cpp engine.h
	g++ -c engine.cpp

car.o : car.cpp car.h 
	g++ -c car.cpp

vehicle.o : vehicle.cpp vehicle.h
	g++ -c vehicle.cpp

motor.o : motor.cpp motor.h
	g++ -c motor.cpp

main.o : main.cpp
	g++ -c main.cpp

clean : 
	rm main *.o