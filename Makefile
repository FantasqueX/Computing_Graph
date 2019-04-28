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
