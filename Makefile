all:main

main:main.o  NodeFactory.o node.o UnaryOperation.o BinaryOperation.o TernaryOperation.o Operand.o graph.o
	$(CXX) main.o  NodeFactory.o node.o UnaryOperation.o BinaryOperation.o TernaryOperation.o Operand.o graph.o -o main
node.o: graph/Node/node.cpp graph/Node/node.h 
	$(CXX) -c graph/Node/node.cpp -o node.o
UnaryOperation.o: graph/Node/UnaryOperation.cpp graph/Node/node.h graph/Node/UnaryOperation.h 
	$(CXX) -c graph/Node/UnaryOperation.cpp -o UnaryOperation.o
BinaryOperation.o: graph/Node/BinaryOperation.cpp graph/Node/node.h graph/Node/BinaryOperation.h 
	$(CXX) -c graph/Node/BinaryOperation.cpp -o BinaryOperation.o
TernaryOperation.o: graph/Node/TernaryOperation.cpp graph/Node/node.h graph/Node/TernaryOperation.h 
	$(CXX) -c graph/Node/TernaryOperation.cpp -o TernaryOperation.o
Operand.o: graph/Node/Operand.cpp graph/Node/node.h graph/Node/Operand.h 
	$(CXX) -c graph/Node/Operand.cpp -o Operand.o
NodeFactory.o: graph/Graph/NodeFactory.cpp graph/Graph/NodeFactory.h graph/Node/node.h graph/Node/UnaryOperation.h graph/Node/BinaryOperation.h graph/Node/TernaryOperation.h graph/Node/Operand.h
	$(CXX) -c graph/Graph/NodeFactory.cpp -o NodeFactory.o
graph.o: graph/Graph/graph.cpp graph/Graph/graph.h  graph/Node/node.h graph/Node/UnaryOperation.h graph/Node/BinaryOperation.h graph/Node/TernaryOperation.h graph/Node/Operand.h graph/Graph/NodeFactory.h
	$(CXX) -c graph/Graph/graph.cpp -o graph.o
main.o: main.cpp graph/Node/node.h graph/Graph/graph.h NodeFactory.o node.o UnaryOperation.o BinaryOperation.o TernaryOperation.o Operand.o graph.o
	$(CXX) -c main.cpp -o main.o
clean:
	rm *.o 
	rm main
