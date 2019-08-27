kplusgen:
	g++ -std=c++17 -I include src/*.cxx examples/GenKplusDec.cxx -o examples/GenKplusDec -Wall
	g++ -std=c++17 -I include src/*.cxx examples/BindingEnergies.cxx -o examples/BindingEnergies -Wall

purge:
	rm *.o
