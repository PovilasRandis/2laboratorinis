main: Funkcijos.o
	c++ -o main darbasv0.3.cpp Funkcijos.o 

funkcijos:
	c++ -c Funkcijos.cpp

clean:
	rm *.o 