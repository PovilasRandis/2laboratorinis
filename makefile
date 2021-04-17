main: Funkcijos.o
	c++ -o3 -o main darbasv1.0.cpp Funkcijos.o 

funkcijos:
	c++ -o3 -c Funkcijos.cpp

clean:
	rm *.o 