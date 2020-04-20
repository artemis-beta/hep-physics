#include "EquationSolver.hxx"

const PHYS::Algebra::var* PHYS::Algebra::composite::_var_from_char(std::string c) const
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
PHYS::Algebra::Expression PHYS::Algebra::Expression::operator* (int other) const
{
    PHYS::Algebra::Expression _temp(*this);
    for(int i{0}; i<_temp._components.size(); ++i)
    {
        _temp._components[i].setFactor(_temp._components[i].getFactor()*other);
    }

    return _temp;
}

PHYS::Algebra::Expression PHYS::Algebra::Expression::operator* (double other) const
{
    PHYS::Algebra::Expression _temp(*this);
    for(int i{0}; i<_temp._components.size(); ++i)
    {
        _temp._components[i].setFactor(_temp._components[i].getFactor()*other);
    }

    return _temp;
}

int PHYS::Algebra::Expression::_find_composite(PHYS::Algebra::composite& composite)
{
    for(int i{0}; i<_components.size(); ++i)
    {
        if(_components[i] == composite) return i;
    }

    return -1;
}

template<typename T>
PHYS::Algebra::Expression PHYS::Algebra::Pow(const PHYS::Algebra::Expression& eq, const T& index)
{
    PHYS::Algebra::Expression _temp(eq);
    for(unsigned int i{0}; i<index-1; ++i) _temp *= eq;
    return _temp;
}

template<typename T>
PHYS::Algebra::Expression PHYS::Algebra::Pow(PHYS::Algebra::Expression& eq, const T& index)
{
    PHYS::Algebra::Expression _temp(eq);
    for(unsigned int i{0}; i<index-1; ++i) _temp *= eq;
    return _temp;
}

void PHYS::Algebra::Equation::_simplify(const PHYS::Algebra::Expression exp, const double is_equal_to)
{
    _exp = exp - exp.getNumericComponent();
    _equals = is_equal_to+exp.getNumericComponent();
    if(_exp.getComponents().size() == 1)
    {
        if(_exp.getComponents()[0].getComponents().size() == 1)
        {
            const double exponent = _exp.getComponents()[0].getComponents().begin()->second;
            _exp /= PHYS::Algebra::Pow(_exp, 1./exponent);
            _equals /= std::pow(_equals, 1./exponent);
        }
    }
}

PHYS::Algebra::Expression& PHYS::Algebra::Derivative(const PHYS::Algebra::composite& comp)
{
    PHYS::Algebra::Expression _temp;
    for(auto& part : comp.getComponents())
    {
        PHYS::Algebra::composite _temp_comp;
        _temp_comp.setComponent(part.first, part.second-1);
        _temp_comp.setFactor(comp.getFactor()*part.second);
        for(auto& part2 : comp.getComponents())
        {
            if(part.first == part2.first) continue;
            _temp_comp *= composite({{part2.first, part2.second}});
        }
    }

    return _temp;
}

PHYS::Algebra::Expression& PHYS::Algebra::Derivative(const PHYS::Algebra::Expression& e)
{
    PHYS::Algebra::Expression _temp;

    for(auto& comp : e.getComponents())
    {
        _temp += Derivative(comp);
    } 

    return _temp;
}

PHYS::Algebra::Expression& PHYS::Algebra::Derivative(const PHYS::Algebra::Expo& e)
{
    return PHYS::Algebra::Derivative(e.getExponent())*e;
}

