#include "Thermodynamics.hxx"
#include "Units.hxx"
#include "CommonMolecules.hxx"

using namespace PHYS;
using namespace PHYS::Units;
using namespace PHYS::Molecules;

int main()
{
    Container Beaker(10*cm, 10*cm, 30*cm);

    Beaker.Fill(Oxygen, 10*g);
    Beaker.setTemperature(Celsius(0));

    std::cout << "Pressure in beaker at 0 Celsius: " << Beaker.getPressure()/Pa << "Pa" << std::endl;

    return 0;
}
