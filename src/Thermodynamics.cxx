#include "Thermodynamics.hxx"

void PHYS::Container::Fill(const PHYS::Molecules::Molecule& molecule, const double quantity)
{
    if(!is_empty)
    {
        _contents[molecule] = quantity;
    }
    else
    {
        _contents = Occupancy({{molecule, quantity}});
    }
    
}

const double PHYS::Container::getNMoles(const PHYS::Molecules::Molecule& molecule = PHYS::Molecules::Molecule())
{
    if(_contents.find(molecule) == _contents.end())
    {
        double n_moles = 0;
        if(molecule.getContents().size() == 0)
        {
            for(const auto &pair : _contents)
            {
                PHYS::Molecules::Molecule m = pair.first;
                double mass = pair.second;

                n_moles += mass/PHYS::Molecules::getMr(m);

            }

            return n_moles;
        }
        throw std::runtime_error("Stated Molecule not in Container");
    }
    return _contents[molecule];
}

const double PHYS::Container::getPressure()
{
    return getNMoles()*PHYS::Constants::R*_temperature/getVolume();
}