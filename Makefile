kplusgen:
	g++ -std=c++17 -I include src/*.cxx examples/GenKplusDec.cxx -o examples/GenKplusDec -Wall

purge:
	rm *.o
