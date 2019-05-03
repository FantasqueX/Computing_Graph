<<<<<<< HEAD
all:main

main:main.o node.o onepn.o twopn.o threepn.o zeropn.o graph.o
	$(CXX) main.o node.o onepn.o twopn.o threepn.o zeropn.o graph.o -o main
node.o: graph/node.cpp graph/node.h 
	$(CXX) -c graph/node.cpp -o node.o
onepn.o: graph/onepn.cpp graph/node.h graph/onepn.h 
	$(CXX) -c graph/onepn.cpp -o onepn.o
twopn.o: graph/twopn.cpp graph/node.h graph/twopn.h 
	$(CXX) -c graph/twopn.cpp -o twopn.o
threepn.o: graph/threepn.cpp graph/node.h graph/threepn.h 
	$(CXX) -c graph/threepn.cpp -o threepn.o
zeropn.o: graph/zeropn.cpp graph/node.h graph/zeropn.h 
	$(CXX) -c graph/zeropn.cpp -o zeropn.o
graph.o: graph/graph.cpp graph/graph.h  graph/node.h graph/onepn.h graph/twopn.h graph/threepn.h graph/zeropn.h
	$(CXX) -c graph/graph.cpp -o graph.o
main.o: main.cpp graph/node.h graph/graph.h node.o onepn.o twopn.o threepn.o zeropn.o graph.o
	$(CXX) -c main.cpp -o main.o
clean:
	rm *.o 
	rm main
=======
main.exe:main.o node.o onepn.o twopn.o threepn.o zeropn.o graph.o
	g++ main.o node.o onepn.o twopn.o threepn.o zeropn.o graph.o -o main.out
node.o: node.h node.cpp
	g++ -c node.cpp -o node.o
onepn.o: node.h onepn.h onepn.cpp
	g++ -c onepn.cpp -o onepn.o
twopn.o: node.h twopn.h twopn.cpp
	g++ -c twopn.cpp -o twopn.o
threepn.o: node.h threepn.h threepn.cpp
	g++ -c threepn.cpp -o threepn.o
zeropn.o: node.h zeropn.h zeropn.cpp
	g++ -c zeropn.cpp -o zeropn.o
graph.o: graph.h graph.cpp node.h onepn.h twopn.h threepn.h zeropn.h
	g++ -c graph.cpp -o graph.o
main.o: main.cpp node.h graph.h node.o onepn.o twopn.o threepn.o zeropn.o graph.o
	g++ -c main.cpp -o main.o
clean:
	rm *.o *.out
>>>>>>> e65f6974574aab5cc82d19e04d7012d9600c4dbe
