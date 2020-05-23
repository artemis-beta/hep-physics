#ifndef __EQ_SOLVER_Hxvarxvar__
#define __EQ_SOLVER_Hxvarxvar__

#include <iostream>
#include <map>
#include <cmath>
#include <vector>

namespace PHYS
{
    namespace Algebra
    {
        class var
        {
            private:
                const std::string _symbol;
            public:
                const std::string getSymbol() const{return _symbol;}
                var(const std::string& symbol) : _symbol(symbol) {}

                friend std::ostream& operator<< (std::ostream& os, const var& x)
                {
                    os << x._symbol;
                    return os;
                }

                bool operator== (const var& other) const
                {
                    return _symbol == other._symbol;
                }

                friend bool operator< (const var& first, const var& other)
                {
                    return first._symbol < other._symbol;
                }
        };

        class composite
        {
            private:
                std::map<var, double> _components = std::map<var, double>();
                double _factor = 1;
                const var* _var_from_char(std::string c) const;
            public:
                void setFactor(const double factor){_factor=factor;}
                void setComponent(const var key, const double value)
                {
                    _components[key] = value;
                }
                double getFactor() const {return _factor;}
                composite() {}
                composite(std::map<var, double> parameters, double factor=1) : 
                    _components(parameters),
                    _factor(factor) {}
                composite(std::map<std::string, double> parameters, double factor=1) :
                    _factor(factor)
                {
                    for(auto& x : parameters)
                    {
                        _components[var(x.first)] = x.second;
                    }
                }
                composite(std::vector<var> parameters, double factor=1) :
                    _factor(factor)
                {
                    for(auto& x : parameters)
                    {
                        _components[x] = 1.;
                    }
                }
                composite(std::vector<std::string> parameters, double factor=1) :
                    _factor(factor)
                {
                    for(auto& x : parameters)
                    {
                        _components[var(x)] = 1.;
                    }
                }

                const std::map<var, double> getComponents() const {return _components;}

                template <typename T>
                double Solve(std::map<char, T>& values) const;

                friend bool operator< (const composite& first, const composite& other)
                {
                    return first._factor < other._factor;
                }

                std::string toString() const;

                friend std::ostream& operator<< (std::ostream& os, const composite& eq)
                {
                    os <<  eq.toString();
		            return os;
                }

                bool operator== (composite& other) const
                {
                    composite _temp(*this);
                    for(auto& i : _components)
                    {
                        if(other._components.find(i.first) == other._components.end()) return false;
                        if(other._components[i.first] != _temp._components[i.first]) return false;
                    }

                    return true;
                }

                composite operator* (const composite& other)
                {
                    composite _temp(*this), _temp_other(other);
                    for(auto& i : other._components)
                    {
                        if(_temp._components.find(i.first) != _temp._components.end())
                        {
                            _temp._components[i.first] += _temp_other._components[i.first];
                        }
                        else
                        {
                            _temp._components[i.first] = _temp_other._components[i.first];
                        }

                        _temp._factor *= _temp_other._factor;
                        
                    }

                    return _temp;
                }

                composite operator*= (const composite& other)
                {
                    *this = (*this)*other;
                    return *this;
                }

        };

        class Expression
        {
            private:
                std::vector<composite> _components = {};
                double _numeric_component = 0;
                int _find_composite(composite&);
            public:
                Expression(){}
                Expression(std::vector<composite> components, double number=0) : 
                    _components(components),
                    _numeric_component(number) {}

                template <typename T>
                double Solve(std::map<std::string, T> values) 
                {
                    double _temp = 0;

                    for(auto& i : _components)
                    {
			    Expression _component({composite(i)});
                        _temp += _component.Solve(values);
                    }
                    _temp += _numeric_component;

                    return _temp;
                }

                double Solve(double value) const
                {
                    Expression _temp(*this);
                    const var xvar_first = _temp.getComponents()[0].getComponents().begin()->first;
                    std::map<std::string, double> _values = {{xvar_first.getSymbol(), value}};
                    const double solution = _temp.Solve(_values);
                    return solution;
                }

                std::string toString() const
                {
                    std::string _out_str = "";
                    for(int i{0}; i<_components.size(); ++i)
                    {
                        const composite f = composite(_components[i]);
                        if(i>0 && f.getFactor() > 0) _out_str += "+";
                        _out_str += f.toString();
                    }
                    if(_numeric_component > 0) _out_str +=  "+" + std::to_string(_numeric_component);
                    else if(_numeric_component < 0) _out_str += std::to_string(_numeric_component);

                    return _out_str;
                }

                const std::vector<composite> getComponents() const {return _components;}
                const double getNumericComponent() const {return _numeric_component;}
                
                friend std::ostream& operator<< (std::ostream& os, const Expression& eq)
                {
                    os << eq.toString();                    
		    return os;
                }

                Expression operator+ (Expression other) const
                {
                    Expression eq_tmp(*this);
                    // Need to check that a composite matching 'other' does not already exist first
                    for(auto& c : other._components)
                    {
                        composite _temp = c;
                        const int index = eq_tmp._find_composite(_temp);
                        if(index >= 0)
                        {
                        eq_tmp._components[index].setFactor(eq_tmp._components[index].getFactor()+_temp.getFactor()); 
                        }
                        else
                        {
                            eq_tmp._components.push_back(_temp);
                        }
                    }

                    return eq_tmp;

                }

                Expression operator* (Expression other) const
                {
                    Expression _temp(*this);

                    for(unsigned int i {0}; i<other._components.size(); ++i)
                    {
                        for(unsigned int j {0}; j<_temp._components.size(); ++j)
                        {
                            _temp._components[j] *= other._components[i];
                        }
                    
                    }

                    if(this->_numeric_component != 0)
                    {
                        for(auto& j : other._components)
                        {
                            composite _temp_comp  = j;
                            _temp_comp.setFactor(this->_numeric_component*_temp_comp.getFactor());
                            const int index = _temp._find_composite(_temp_comp);
                            if(index >= 0)
                            {
                                _temp._components[index].setFactor(_temp._components[index].getFactor()+_temp_comp.getFactor());
                            }
                            else
                            {
                                _temp._components.push_back(_temp_comp);
                            }
                        }
                    }
                    if(other._numeric_component != 0)
                    {
                        for(auto& i : this->_components)
                        {
                            composite _temp_comp  = i;
                            _temp_comp.setFactor(other._numeric_component*_temp_comp.getFactor());
                            const int index = _temp._find_composite(_temp_comp);
                            if(index >= 0)
                            {
                                _temp._components[index].setFactor(_temp._components[index].getFactor()+_temp_comp.getFactor());
                            }
                            else
                            {
                                _temp._components.push_back(_temp_comp);
                            }
                        }
                    }
                
                    _temp._numeric_component *= other._numeric_component;

                    return _temp;
                }

                Expression operator* (int other) const;
                Expression operator* (double other) const;

                template <typename T>
                friend Expression operator* (const T& other, const Expression& eq)
                {
                    Expression _temp(eq);
                    for(int i{0}; i<_temp._components.size(); ++i)
                    {
                        _temp._components[i].setFactor(_temp._components[i].getFactor()*other);
                    }

                    return _temp;
                }

                template <typename T>
                friend Expression operator+ (T other, Expression eq)
                {
                    Expression _temp(eq);
                    _temp._numeric_component += other;

                    return _temp;
                }

                template <typename T>
                friend Expression operator+ (Expression eq, T other)
                {
                    Expression _temp(eq);
                    _temp._numeric_component += other;

                    return _temp;
                }

                template <typename T>
                friend Expression operator- (T other, Expression eq)
                {
                    Expression _temp(eq);
                    _temp._numeric_component = other - _temp._numeric_component;

                    return _temp;
                }

                template <typename T>
                friend Expression operator-(Expression eq, T other)
                {
                    Expression _temp(eq);
                    _temp._numeric_component -= other;

                    return _temp;
                }

                Expression operator/ (Expression other) const
                {
                    Expression _temp(*this);
                    return _temp*(1./other);
                }

                template <typename T>
                friend Expression operator/(T other, Expression eq)
                {
                    Expression _temp;
                    for(auto& i : eq._components)
                    {
                        composite _temp_comp;
                        _temp_comp.setFactor(other/(i.getFactor()*1.0));
                        for(auto& j : i.getComponents())
                        {
                            _temp_comp.setComponent(j.first, -1*j.second);
                        }
                        _temp._components.push_back(_temp_comp);
                    }
                    return _temp;
                }

                template <typename T>
                friend Expression operator/(Expression eq, T other)
                {
                    Expression _temp(eq);
                    for(int i{0}; i<eq._components.size(); ++i)
                    {
                        _temp._components[i].setFactor(eq._components[i].getFactor()/other);
                    }

                    return _temp;
                }

                void operator*=(Expression eq)
                {
                    (*this) = (*this)*eq;
                }

                void operator/=(Expression eq)
                {
                    (*this) = (*this)/eq;
                }

                void operator+=(Expression eq)
                {
                    (*this) = (*this)+eq;
                }

                void operator-=(Expression eq)
                {
                    (*this) = (*this)+-1*eq;
                }

                void operator*=(double other)
                {
                    (*this) = (*this)*other;
                }

                void operator/=(double other)
                {
                    (*this) = (*this)/other;
                }

                void operator+=(double other)
                {
                    (*this) = (*this)+other;
                }

                void operator-=(double other)
                {
                    (*this) = (*this)+-1*other;
                }

            };
        
        class Expo : public var
        {
            private:
                Expression _exponent;
            public:
                Expo(const Expression& exp) : var("exp("+exp.toString()+")"), _exponent(exp) {}

                friend std::ostream& operator<< (std::ostream& os, const Expo& exp)
                {
                    os << exp.getSymbol();
                    os << "(";
                    os << exp.getExponent();
                    os << ")";
                    return os;
                }
                
                Expression getExponent() const {return _exponent;}

                friend Expression operator* (const Expression& e, const Expo& expo)
                {
                    return e*expo;
                }
                
        };

        class Equation
        {
            private:
                Expression _exp;
                double _equals;
                void _simplify(const Expression, const double);
            public:
                Equation(const Expression exp, const double is_equal_to, bool simplify=true) :
                    _exp(exp), _equals(is_equal_to)
                {
                    if(simplify) _simplify(exp, is_equal_to);
                }

                const double getEqualsTo() const {return _equals;}
                const Expression getExpression() const {return _exp;}
		std::string toString() const
		{

			std::string _out_str = getExpression().toString() + " = ";
			const int int_equals_to = static_cast<int>(getEqualsTo());
			if(floorf(getEqualsTo()) == getEqualsTo()) _out_str += std::to_string(int_equals_to);
			else _out_str += std::to_string(getEqualsTo());

			return _out_str;
		}
                
                friend std::ostream& operator<< (std::ostream& os, const Equation& eq)
                {
                    os << eq.toString();

                    return os;
                }
            
        };
        
        Expression Derivative(const composite& comp);
        Expression Derivative(const Expo& eq);
        Expression Derivative(const Expression& eq);

        template<typename T>
        Expression Pow(const Expression& eq, const T& index);

        template<typename T>
        Expression Pow(Expression& eq, const T& index);


        const Expression X(std::vector<composite>({composite(std::map<std::string, double>({{"x", 1}}))}));
        const Expression Y(std::vector<composite>({composite(std::map<std::string, double>({{"y", 1}}))}));
        const Expression Z(std::vector<composite>({composite(std::map<std::string, double>({{"z", 1}}))}));
    };
};

#endif
