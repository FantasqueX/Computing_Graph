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
