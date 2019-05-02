all:main

<<<<<<< HEAD
main:main.o node.o onepn.o twopn.o threepn.o zeropn.o graph.o
=======
main.exe:main.o node.o onepn.o twopn.o threepn.o zeropn.o graph.o
>>>>>>> 895d1d48c25cb7d0887bd6021983ed67e7d726dc
	$(CXX) main.o node.o onepn.o twopn.o threepn.o zeropn.o graph.o -o main
node.o: node.cpp node.h 
	$(CXX) -c node.cpp -o node.o
onepn.o: onepn.cpp node.h onepn.h 
	$(CXX) -c onepn.cpp -o onepn.o
twopn.o: twopn.cpp node.h twopn.h 
	$(CXX) -c twopn.cpp -o twopn.o
threepn.o: threepn.cpp node.h threepn.h 
	$(CXX) -c threepn.cpp -o threepn.o
zeropn.o: zeropn.cpp node.h zeropn.h 
	$(CXX) -c zeropn.cpp -o zeropn.o
graph.o: graph.cpp graph.h  node.h onepn.h twopn.h threepn.h zeropn.h
	$(CXX) -c graph.cpp -o graph.o
main.o: main.cpp node.h graph.h node.o onepn.o twopn.o threepn.o zeropn.o graph.o
	$(CXX) -c main.cpp -o main.o
clean:
	rm *.o 
	rm main
