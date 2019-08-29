#ifndef __HYDROCARBONS_HXX__
#define __HYDROCARBONS_HXX__

#include "CommonMolecules.hxx"

namespace PHYS
{
    namespace Molecules
    {
        typedef Molecule Compound;
    
        const std::string prefixes[12] = {"Meth", "Eth", "Prop", "But", "Pent", "Hex", "Hept",
                                          "Oct", "Non", "Dec", "Undec", "Dodec"};

        /*! Generate a standard Alkane chain given the number of carbon atoms
        @param n_carbon Number of Carbon atoms
        */
        //const Compound genAlkane(const int n_carbon);
        /*! Generate a standard Alkene chain given the number of carbon atoms
        @param n_carbon Number of Carbon atoms
        */
        //const Compound genAlkene(const int n_carbon);

        /*! Generate a standard Alkyne chain given the number of carbon atoms
        @param n_carbon Number of Carbon atoms
        */
        //const Compound genAlkyne(const int n_carbon);
        /*
        const extern Compound Methane;
        const extern Compound Ethane;
        const extern Compound Propane;
        const extern Compound Butane;
        const extern Compound Pentane;
        const extern Compound Hexane;
        const extern Compound Heptane;
        const extern Compound Octane;
        const extern Compound Nonane;
        const extern Compound Decane;
        const extern Compound Undecane;
        const extern Compound Dodecane;

        const extern Compound Methene;
        const extern Compound Ethene;
        const extern Compound Propene;
        const extern Compound Butene;
        const extern Compound Pentene;
        const extern Compound Hexene;
        const extern Compound Heptene;
        const extern Compound Octene;
        const extern Compound Nonene;
        const extern Compound Decene;
        const extern Compound Undecene;
        const extern Compound Dodecene;

        const extern Compound Ethyne;
        const extern Compound Propyne;
        const extern Compound Butyne;
        const extern Compound Pentyne;
        const extern Compound Hexyne;
        const extern Compound Heptyne;
        const extern Compound Octyne;
        const extern Compound Nonyne;
        const extern Compound Decyne;*/
    }
}

#endif
