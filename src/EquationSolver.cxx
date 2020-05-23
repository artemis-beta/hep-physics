#include "EquationSolver.hxx"

template <typename T>
double PHYS::Algebra::composite::Solve(std::map<char, T>& values) const
{
    composite _temp_comp(*this);
    std::map<char, T> v = std::map<char, T>(values);
    double _temp = 1;
    for(auto i : v)
    {   
        const var* xvar = _temp_comp._var_from_char(i.first);
        _temp *= pow(i.second, _temp_comp._components[*xvar]);
    }
    return _factor*_temp;
}

std::string PHYS::Algebra::composite::toString() const
{
    std::string _out_str = "";
    const int int_factor = static_cast<int>(_factor);
    if(abs(_factor) > 1)
    {
        if(floorf(_factor) == _factor) _out_str += std::to_string(int_factor);
        else _out_str += std::to_string(_factor);
    }
    else if(_factor == -1)
    {
        _out_str += "-";
    }
    else if(_factor == 0)
    {
        return _out_str;
    }
    for(auto& i : _components)
    {
        const int int_index = static_cast<int>(i.second);
        if(i.second == 0) continue;
        _out_str += i.first.getSymbol();
        if(abs(i.second) > 1 || i.second == -1)
        {
            _out_str += "^";
            if(i.second < 0)
            {
                if(floorf(i.second) == i.second) _out_str += "(" + std::to_string(int_index) + ")";
                else _out_str += "(" + std::to_string(i.second) + ")";
            }
            else
            {
                if(floorf(i.second) == i.second) _out_str += std::to_string(int_index);
                else _out_str += std::to_string(i.second);
            }
        }
    }

    return _out_str;
    
}
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
    _equals = is_equal_to-exp.getNumericComponent();
}

PHYS::Algebra::Expression PHYS::Algebra::Derivative(const PHYS::Algebra::composite& comp)
{
    std::vector<composite> _composites = {};
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

	_composites.push_back(_temp_comp);
    }

    return PHYS::Algebra::Expression(_composites);
}

PHYS::Algebra::Expression PHYS::Algebra::Derivative(const PHYS::Algebra::Expression& e)
{
    PHYS::Algebra::Expression _temp;

    for(auto& comp : e.getComponents())
    {
        _temp += Derivative(comp);
    } 

    return _temp;
}

PHYS::Algebra::Expression PHYS::Algebra::Derivative(const PHYS::Algebra::Expo& e)
{
    return PHYS::Algebra::Derivative(e.getExponent())*e;
}

