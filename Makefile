CXX = g++ -std=c++17
INCLUDE = -I include

ORDERED_OBJ = obj/Units.o obj/Constants.o obj/LorentzVector.o obj/Vector.o \
			  obj/Particle.o obj/DecayTable.o obj/CommonParticles.o obj/NuclearPhysics.o \
			  obj/Atom.o obj/CommonNuclei.o obj/CommonMolecules.o obj/Thermodynamics.o \
			  obj/CommonCompounds.o obj/Hydrocarbons.o obj/ClassicalMechanics.o \
			  obj/KplusDecTable.o obj/PDF.o obj/EquationSolver.o obj/Epoch.o


all:
	mkdir -p obj
	$(CXX) $(INCLUDE) src/*.cxx -c
	mv *.o obj/
	mkdir -p binaries
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/BindingEnergies.cxx -o binaries/BindingEnergies
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/IdealGas.cxx -o binaries/IdealGas
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/Mass_on_Spring.cxx -o binaries/Mass_on_Spring
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/GenKplusDec.cxx -o binaries/GenKplusDec
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/SUVAT_Example.cxx -o binaries/SUVAT_Example
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/DataFromPDFExample.cxx -o binaries/DataFromPDFExample
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/DataFrameExample.cxx -o binaries/DataFrameExample
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/EquationExample.cxx -o binaries/EquationExample
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/DynamicArrayExample.cxx -o binaries/DynamicArrayExample
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/DataSeriesExample.cxx -o binaries/DataSeriesExample
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/ChronoExample.cxx -o binaries/ChronoExample

clean:
	rm -rf obj/ binaries/
