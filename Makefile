kplusgen:
	g++ -std=c++17 -I include src/Units.cxx src/LorentzVector.cxx src/Particle.cxx src/DecayTable.cxx src/CommonParticles.cxx src/KplusDecTable.cxx examples/GenKplusDec.cxx -o examples/GenKplusDec -Wall

purge:
	rm *.o
