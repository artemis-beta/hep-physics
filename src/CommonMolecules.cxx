#include "CommonMolecules.hxx"
#include "CommonNuclei.hxx"
#include "Atom.hxx"

#include <iostream>

const extern PHYS::Molecules::Molecule PHYS::Molecules::Vacuum = PHYS::Molecules::Molecule();
const extern PHYS::Molecules::Molecule PHYS::Molecules::Oxygen = PHYS::Molecules::Molecule("Oxygen", {{Atom(PHYS::Elements::Oxygen), 2}});
const extern PHYS::Molecules::Molecule PHYS::Molecules::Ozone = PHYS::Molecules::Molecule("Ozone", {{Atom(PHYS::Elements::Oxygen), 3}});
const extern PHYS::Molecules::Molecule PHYS::Molecules::Hydrogen = PHYS::Molecules::Molecule("Hydrogen", {{Atom(PHYS::Elements::Hydrogen), 2}});
const extern PHYS::Molecules::Molecule PHYS::Molecules::Sulfur = PHYS::Molecules::Molecule("Sulfur", {{Atom(PHYS::Elements::Sulfur), 8}});

const double PHYS::Molecules::getMr(PHYS::Molecules::Molecule& molecule)
{
    double _tmp = 0;
    for(const auto& pair : molecule.getContents())
    {
        PHYS::Atom a = pair.first;
        const int n_a = pair.second;
        
        double mass = a.M();

        _tmp += mass*n_a;
    }
    return _tmp;
}

const bool PHYS::Molecules::operator< (const PHYS::Molecules::Molecule& a, const PHYS::Molecules::Molecule& b)
{
    return a.getName() < b.getName();
}