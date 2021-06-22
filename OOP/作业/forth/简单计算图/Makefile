main: main.o graph.o node.o operation.o mymap.o add.o mi.o
	g++ -std=c++11 -o main main.o graph.o node.o operation.o mymap.o add.o mi.o
main.o: main.cpp
	g++ -g -c -std=c++11 -o main.o main.cpp 
graph.o: graph.cpp graph.h mymap.h node.h operation.h
	g++ -g -c -std=c++11 -o graph.o graph.cpp 
node.o: node.cpp node.h
	g++ -g -c -std=c++11 -o node.o node.cpp 
operation.o: operation.cpp operation.h node.h
	g++ -g -c -std=c++11 -o operation.o operation.cpp 
mymap.o: mymap.cpp mymap.h 
	g++ -g -c -std=c++11 -o mymap.o mymap.cpp
add.o:add.cpp add.h
	g++ -g -c -std=c++11 -o add.o add.cpp
minus.o:mi.cpp mi.h
	g++ -g -c -std=c++11 -o mi.o mi.cpp
clean:
	rm main *.o
