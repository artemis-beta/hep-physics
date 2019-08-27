#include "ClassicalMechanics.hxx"

void PHYS::SimpleBody::applyForce(const PHYS::Force& f)
{
    _forces.push_back(f);
}

const PHYS::Force PHYS::SimpleBody::resolve() const
{
    PHYS::Force _tmp = {0,0,0};
    for(auto i : _forces)
    {
        _tmp += i;
    }

    return _tmp;
}