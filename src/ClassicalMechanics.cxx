#include "ClassicalMechanics.hxx"

void PHYS::Object::applyForce(PHYS::Force& f)
{
    _forces.push_back(f);
}

const PHYS::Force PHYS::Object::resolve() const
{
    PHYS::Force _tmp = {0,0,0};
    for(auto i : _forces)
    {
        std::cout << i << std::endl;
        _tmp = _tmp + i;
    }

    std::cout << _tmp << std::endl;

    return _tmp;
}

void PHYS::Spring::Update()
{
    for(int i{0}; i<_attachments.size(); ++i)
    {
        _points[i] = _attachments[i]->getPosition();
    }
}

const PHYS::Force PHYS::Spring::forceSpring()
{
    PHYS::Coordinate Dir = _points[1]-_points[0];
    const double r = Dir.magnitude();
    
    const double dx = r-_length_at_rest;

    const PHYS::Force F = -1*PHYS::Cartesian(_spring_constant*dx*(Dir/r));

    return F;
}

void PHYS::Spring::Attach(PHYS::Object* other)
{
    Force _tmp = this->forceSpring();
    other->applyForce(_tmp);
    _attachments.push_back(other);
    this->Update();
}