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

void PHYS::SUVATSolver::SUVAT1()
{
    if(_variables['u'] != 1E-38 && _variables['v'] != 1E-38 && _variables['a'] != 1E-38 && _variables['t'] == 1E-38)
    {
        _variables['t'] = (_variables['v']-_variables['u'])/_variables['a'];
    }
    else if(_variables['u'] != 1E-38 && _variables['v'] != 1E-38 && _variables['a'] == 1E-38 && _variables['t'] != 1E-38)
    {
        _variables['a'] = (_variables['v']-_variables['u'])/_variables['t'];
    }
    else if(_variables['u'] == 1E-38 && _variables['v'] != 1E-38 && _variables['a'] != 1E-38 && _variables['t'] != 1E-38)
    {
        _variables['u'] = _variables['v']-(_variables['a']*_variables['t']);
    }
    else if(_variables['u'] != 1E-38 && _variables['v'] == 1E-38 && _variables['a'] != 1E-38 && _variables['t'] != 1E-38)
    {
        _variables['v'] = _variables['u']+(_variables['a']*_variables['t']);
    }
}

void PHYS::SUVATSolver::SUVAT2()
{
    if(_variables['u'] != 1E-38 && _variables['a'] != 1E-38 && _variables['t'] != 1E-38 && _variables['s'] == 1E-38)
    {
        _variables['s'] = _variables['u']*_variables['t']+0.5*_variables['a']*pow(_variables['t'],2);
    }
    else if(_variables['u'] != 1E-38 && _variables['a'] == 1E-38 && _variables['t'] != 1E-38 && _variables['s'] != 1E-38)
    {
        _variables['a'] = (_variables['s']-_variables['u']*_variables['t'])/(0.5*pow(_variables['t'],2));
    }
    else if(_variables['u'] == 1E-38 && _variables['a'] != 1E-38 && _variables['t'] != 1E-38 && _variables['s'] != 1E-38)
    {
        _variables['u'] = (_variables['s']-0.5*_variables['a']*pow(_variables['t'],2))/_variables['t'];
    }
}

void PHYS::SUVATSolver::SUVAT3()
{
    if(_variables['s'] != 1E-38 && _variables['u'] != 1E-38 && _variables['v'] != 1E-38 && _variables['t'] == 1E-38)
    {
        _variables['t'] = 2*_variables['s']/(_variables['u']+_variables['v']);
    }
    else if(_variables['s'] != 1E-38 && _variables['u'] != 1E-38 && _variables['v'] == 1E-38 && _variables['t'] != 1E-38)
    {
        _variables['v'] = 2*_variables['s']/_variables['t'] - _variables['u'];
    }
    else if(_variables['s'] != 1E-38 && _variables['u'] == 1E-38 && _variables['v'] != 1E-38 && _variables['t'] != 1E-38)
    {
        _variables['u'] = 2*_variables['s']/_variables['t'] - _variables['v'];
    }
    else if(_variables['s'] == 1E-38 && _variables['u'] == 1E-38 && _variables['v'] == 1E-38 && _variables['t'] != 1E-38)
    {
        _variables['s'] = 0.5*_variables['t']*(_variables['u']+_variables['v']);
    }
}

void PHYS::SUVATSolver::SUVAT4()
{
    if(_variables['s'] != 1E-38 && _variables['u'] != 1E-38 && _variables['v'] != 1E-38 && _variables['a'] == 1E-38)
    {
        _variables['a'] = 0.5*(pow(_variables['v'],2)-pow(_variables['u'], 2))/_variables['s'];
    }
    else if(_variables['s'] == 1E-38 && _variables['u'] != 1E-38 && _variables['v'] != 1E-38 && _variables['a'] != 1E-38)
    {
        _variables['s'] = 0.5*(pow(_variables['v'],2)-pow(_variables['u'], 2))/_variables['a'];
    }
    else if(_variables['s'] != 1E-38 && _variables['u'] != 1E-38 && _variables['v'] == 1E-38 && _variables['a'] != 1E-38)
    {
        _variables['v'] = pow(pow(_variables['u'],2)+2*_variables['a']*_variables['s'], 0.5);
    }
    else if(_variables['s'] != 1E-38 && _variables['u'] == 1E-38 && _variables['v'] != 1E-38 && _variables['a'] != 1E-38)
    {
        _variables['u'] = pow(pow(_variables['v'],2)-2*_variables['a']*_variables['s'], 0.5);
    }
}

PHYS::SUVATSolver::SUVATSolver(const double s, const double u, const double v, const double a, const double t)
{
    _variables = {{'s', s}, {'u', u}, {'v', v}, {'a', a}, {'t', t}};

    SUVAT1();
    SUVAT2();
    SUVAT3();
    SUVAT4();
}

double& PHYS::SUVATSolver::operator()(const char& var, const double val)
{
    if(val != 1E-38){_variables[var] = val;}
    return _variables[var];
}