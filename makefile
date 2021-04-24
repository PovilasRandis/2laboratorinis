main: Funkcijos.o
	c++ -o3 -o main darbasv1.1.cpp Funkcijos.o 

funkcijos:
	c++ -o3 -c Funkcijos.cpp

clean:
	rm *.o 