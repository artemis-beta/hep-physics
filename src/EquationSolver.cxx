#include "EquationSolver.hxx"

const PHYS::var* PHYS::composite::_var_from_char(char c) const
{
    for(auto& i : _components)
    {
        if(i.first.getSymbol() == c)
        {
            return &i.first;
        }
    }

    return nullptr;
}
PHYS::Expression PHYS::Expression::operator* (int other) const
{
    PHYS::Expression _temp(*this);
    for(int i{0}; i<_temp._components.size(); ++i)
    {
        _temp._components[i].setFactor(_temp._components[i].getFactor()*other);
    }

    return _temp;
}

PHYS::Expression PHYS::Expression::operator* (double other) const
{
    PHYS::Expression _temp(*this);
    for(int i{0}; i<_temp._components.size(); ++i)
    {
        _temp._components[i].setFactor(_temp._components[i].getFactor()*other);
    }

    return _temp;
}

int PHYS::Expression::_find_composite(composite& composite)
{
    for(int i{0}; i<_components.size(); ++i)
    {
        if(_components[i] == composite) return i;
    }

    return -1;
}

PHYS::Expression PHYS::pow(const PHYS::Expression eq, int index)
{
    PHYS::Expression _temp(eq);
    for(unsigned int i{0}; i<index-1; ++i) _temp *= eq;
    return _temp;
}

PHYS::Expression PHYS::pow(const PHYS::Expression eq, double index)
{
    PHYS::Expression _temp = pow(eq, int(index));
    const double remainder = int(index);
}

void PHYS::Equation::_simplify(const Expression exp, const double is_equal_to)
{
    _exp = exp - exp.getNumericComponent();
    _equals = is_equal_to+exp.getNumericComponent();
    if(_exp.getComponents().size() == 1)
    {
        if(_exp.getComponents()[0].getComponents().size() == 1)
        {
            std::cout << "GAMOODE" << std::endl;
            const double exponent = _exp.getComponents()[0].getComponents().begin()->second;
            std::cout << "YAZA" << std::endl;
            _exp /= pow(_exp, 1./exponent);
            std::cout << "CMA" << std::endl;
            _equals /= std::pow(_equals, 1./exponent);
        }
        std::cout << "URE" << std::endl;
    }
}