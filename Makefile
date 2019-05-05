all:main

main:main.o  NodeFactory.o node.o UnaryOperation.o BinaryOperation.o TernaryOperation.o Operand.o graph.o
	$(CXX) main.o  NodeFactory.o node.o UnaryOperation.o BinaryOperation.o TernaryOperation.o Operand.o graph.o -o main
node.o: graph/node.cpp graph/node.h 
	$(CXX) -c graph/node.cpp -o node.o
UnaryOperation.o: graph/UnaryOperation.cpp graph/node.h graph/UnaryOperation.h 
	$(CXX) -c graph/UnaryOperation.cpp -o UnaryOperation.o
BinaryOperation.o: graph/BinaryOperation.cpp graph/node.h graph/BinaryOperation.h 
	$(CXX) -c graph/BinaryOperation.cpp -o BinaryOperation.o
TernaryOperation.o: graph/TernaryOperation.cpp graph/node.h graph/TernaryOperation.h 
	$(CXX) -c graph/TernaryOperation.cpp -o TernaryOperation.o
Operand.o: graph/Operand.cpp graph/node.h graph/Operand.h 
	$(CXX) -c graph/Operand.cpp -o Operand.o
NodeFactory.o: graph/NodeFactory.cpp graph/NodeFactory.h graph/node.h graph/UnaryOperation.h graph/BinaryOperation.h graph/TernaryOperation.h graph/Operand.h
	$(CXX) -c graph/NodeFactory.cpp -o NodeFactory.o
graph.o: graph/graph.cpp graph/graph.h  graph/node.h graph/UnaryOperation.h graph/BinaryOperation.h graph/TernaryOperation.h graph/Operand.h graph/NodeFactory.h
	$(CXX) -c graph/graph.cpp -o graph.o
main.o: main.cpp graph/node.h graph/graph.h NodeFactory.o node.o UnaryOperation.o BinaryOperation.o TernaryOperation.o Operand.o graph.o
	$(CXX) -c main.cpp -o main.o
clean:
	rm *.o 
	rm main
