#ifndef __MOLECULES_HXX__
#define __MOLECULES_HXX__

#include <map>
#include <iostream>

#include "Atom.hxx"
#include "CommonNuclei.hxx"

namespace PHYS
{
    /*! @namespace PHYS::Molecules
    
    Namespace containing all molecules and compounds

    @todo Finish all compound definitions
    
    @author K. Zarebski

    @copyright MIT License

    @date last modified 2019-08-28
    */
    namespace Molecules
    {
        class Molecule
        {
            private:
                std::map<PHYS::Atom, int> _contents;
                std::string _name="";
            public:
                Molecule(){_name = "Vacuum", _contents = {{}};}
                Molecule(const std::string label, const std::map<PHYS::Atom, int> atoms) : 
                    _name(label),
                    _contents(atoms)
                    {}
                const std::string getName() const {return _name;}
                const std::map<PHYS::Atom, int> getContents() const {return _contents;};
                friend std::ostream& operator<< (std::ostream& o, const Molecule& m)
                {
                    for(const auto& atom : m.getContents())
                    {
                        const Atom a = atom.first;
                        const int n = atom.second;

                        o << a << n;
                    }

                    return o;
                }
        };

        const bool operator< (const Molecule& a, const Molecule& b);

        const extern Molecule Vacuum;
        const extern Molecule Oxygen;
        const extern Molecule Ozone;
        const extern Molecule Hydrogen;
        const extern Molecule Sulfur;

        /*! Get the molecular mass of the molecule in @f$u@f$
        @returns double*/
        const double getMr(Molecule& molecule);
    }
}

#endif