#ifndef __EQ_SOLVER_Hxvarxvar__
#define __EQ_SOLVER_Hxvarxvar__

#include <iostream>
#include <map>
#include <cmath>
#include <vector>

namespace PHYS
{
    class var
    {
        private:
            const char _symbol;
        public:
            const char getSymbol() const{return _symbol;}
            var(const char& symbol) : _symbol(symbol) {}

            friend std::ostream& operator<< (std::ostream& os, const var& x)
            {
                os << x._symbol;
                return os;
            }

            const bool operator== (var& other)
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
            const var* _var_from_char(char c) const;
        public:
            void setFactor(const double factor){_factor=factor;}
            double getFactor() const {return _factor;}
            composite(std::map<var, double> parameters, double factor=1) : 
                _components(parameters),
                _factor(factor) {}
            composite(std::map<char, double> parameters, double factor=1) :
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
            composite(std::vector<char> parameters, double factor=1) :
                _factor(factor)
            {
                for(auto& x : parameters)
                {
                    _components[var(x)] = 1.;
                }
            }

            const std::map<var, double> getComponents() const {return _components;}

            template <typename T>
            double Solve(std::map<char, T>& values) const
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

            friend bool operator< (const composite& first, const composite& other)
            {
                return first._factor < other._factor;
            }

            friend std::ostream& operator<< (std::ostream& os, const composite& eq)
            {
                if(abs(eq._factor) > 1) os << eq._factor;
                else if(eq._factor == -1) os << "-";
                else if(eq._factor == 0)
                {
                    return os;
                }
                for(auto& i : eq._components)
                {
                    if(i.second == 0) continue;
                    os << i.first;
                    if(abs(i.second) > 1)
                    {
                         os << "^";
                         os << i.second;
                    }
                }
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

            composite operator* (composite& other) const
            {
                composite _temp(*this);
                for(auto& i : other._components)
                {
                    if(_temp._components.find(i.first) != _temp._components.end())
                    {
                        _temp._components[i.first] += other._components[i.first];
                    }
                    else
                    {
                        _temp._components[i.first] = other._components[i.first];
                    }

                    _temp._factor *= other._factor;
                    
                }

                return _temp;
            }

            void operator*= (composite& other)
            {
                *this = (*this)*other;
            }

    };

    class Equation
    {
        private:
            std::vector<composite> _components = {};
            double _numeric_component = 0;
            int _find_composite(composite&);
        public:
            Equation(){}
            Equation(std::vector<composite> components, double number=0) : 
                _components(components),
                _numeric_component(number) {}

            template <typename T>
            double Solve(std::map<char, T> values) 
            {
                double _temp = 0;

                for(auto& i : _components)
                {
                    const composite c(i);
                    _temp += c.Solve(values);
                }
                _temp += _numeric_component;

                return _temp;
            }
            double Solve(double value) const
            {
                Equation _temp(*this);
                const var xvar_first = _temp.getComponents()[0].getComponents().begin()->first;
                std::map<char, double> _values = {{xvar_first.getSymbol(), value}};
                const double solution = _temp.Solve(_values);
                return solution;
            }
            const std::vector<composite> getComponents() const {return _components;}
            
            friend std::ostream& operator<< (std::ostream& os, const Equation& eq)
            {
                for(int i{0}; i<eq._components.size(); ++i)
                {
                    const composite f = composite(eq._components[i]);
                    if(i>0 && f.getFactor() > 0) os << "+";
                    os << f;
                }
                if(eq._numeric_component > 0) os << "+" << std::to_string(eq._numeric_component);
                else if(eq._numeric_component < 0) os << std::to_string(eq._numeric_component);

                return os;
            }

            Equation operator+ (Equation other) const
            {
                Equation eq_tmp(*this);
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

            Equation operator* (Equation other) const
            {
                Equation _temp(*this);

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

            Equation operator* (int other) const;
            Equation operator* (double other) const;

            template <typename T>
            friend Equation operator* (T other, const Equation& eq)
            {
                Equation _temp(eq);
                for(int i{0}; i<_temp._components.size(); ++i)
                {
                    _temp._components[i].setFactor(_temp._components[i].getFactor()*other);
                }

                return _temp;
            }

            template <typename T>
            friend Equation operator+ (T other, Equation eq)
            {
                Equation _temp(eq);
                _temp._numeric_component += other;

                return _temp;
            }

            template <typename T>
            friend Equation operator+ (Equation eq, T other)
            {
                Equation _temp(eq);
                _temp._numeric_component += other;

                return _temp;
            }

            template <typename T>
            friend Equation operator- (T other, Equation eq)
            {
                return other + -1*eq;
            }

            template <typename T>
            friend Equation operator-(Equation eq, T other)
            {
                return eq + -1*other;
            }

        };

    const Equation X(std::vector<composite>({composite(std::map<char, double>({{'x', 1}}))}));
    const Equation Y(std::vector<composite>({composite(std::map<char, double>({{'y', 1}}))}));
    const Equation Z(std::vector<composite>({composite(std::map<char, double>({{'z', 1}}))}));
};

#endif