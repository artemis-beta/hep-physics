CXX = g++ -std=c++17
INCLUDE = -I include

ORDERED_OBJ = obj/Units.o obj/Constants.o obj/LorentzVector.o obj/Vector.o obj/Particle.o obj/DecayTable.o obj/CommonParticles.o obj/NuclearPhysics.o obj/Atom.o obj/CommonNuclei.o obj/CommonMolecules.o obj/Thermodynamics.o obj/CommonCompounds.o obj/Hydrocarbons.o obj/ClassicalMechanics.o obj/KplusDecTable.o obj/PDF.o obj/DataFrame.o


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
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/PDFExample.cxx -o binaries/PDFExample
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/DataFrameExample.cxx -o binaries/DataFrameExample
	$(CXX) $(INCLUDE) $(ORDERED_OBJ) examples/EquationExample.cxx -o binaries/EquationExample

clean:
	rm -rf obj/ binaries/
