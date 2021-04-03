main: Funkcijos.o
	c++ -o3 -o main darbasv0.5.cpp Funkcijos.o 

funkcijos:
	c++ -o3 -c Funkcijos.cpp

clean:
	rm *.o 