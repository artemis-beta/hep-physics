#ifndef __Container_HXX__
#define __Container_HXX__

#include <initializer_list>
#include <stdexcept>
#include <iostream>

namespace PHYS
{
    namespace Data
    {
        template<typename T>
        /*! @brief  Container Class
        @details    Parent class of the two array types
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2020-01-31
        @copyright  MIT License
        */
        class Container
        {
            public:
                T* _container = nullptr;
                void _set_element(const int& index, const T& value)
                {
                    if(index < 0 || index >= _size) throw std::invalid_argument("Index "+std::to_string(index)+" out of range.");
                    _container[index] = value;
                }
                bool _dynamic = false;
                std::string _type_label = "";
                int _size {};
                std::string _label = "";
                class iterator
                {
                    private:
                        T* _pointer;
                    public:
                        iterator(T* ptr) : _pointer(ptr) {}
                        iterator operator++(){T i = *this; _pointer++; return i;};
                        iterator operator++(int){_pointer++; return *this;};
                        T& operator*() { return *_pointer; }
                        T* operator->() { return _pointer; }
                        bool operator==(const T& rhs) { return _pointer == rhs._pointer; }
                        bool operator!=(const T& rhs) { return _pointer != rhs._pointer; }
                        iterator operator--(){T i = *this; _pointer--; return i;}
                        iterator operator--(int){_pointer--; return *this;}

                };

                class const_iterator
                {
                    private:
                        T* _pointer;
                    public:
                        const_iterator(T* ptr) : _pointer(ptr) {}
                        const_iterator operator++(){T i = *this; _pointer++; return i;}
                        const_iterator operator++(int){_pointer++; return *this;}
                        const T& operator*() { return *_pointer; }
                        const T* operator->() { return _pointer; }
                        bool operator==(const T& rhs) { return _pointer == rhs._pointer; }
                        bool operator!=(const T& rhs) { return _pointer != rhs._pointer; }
                        const_iterator operator--(){T i = *this; _pointer--; return i;}
                        const_iterator operator--(int){_pointer--; return *this;}

                };
                Container(const std::string& label="", const std::string type_name="Container", bool dynamic=false)
                    : _container(nullptr), _label(label), _size(0), _type_label(type_name), _dynamic(dynamic) {}
                Container(const int &size, const std::string label="", const std::string type_name="Container", bool dynamic=false)
                    : _container(size > 0 ? new T[size] : nullptr)
                    , _size(size), _label(label), _type_label(type_name), _dynamic(dynamic) {}
                Container(const std::initializer_list<T>& elements, const std::string label="", const std::string type_name="Container", bool dynamic=false) :
                    Container(static_cast<int>(elements.size()), label, type_name, dynamic)
                {
                    int count = 0;
                    for (auto &element : elements)
                    {
                        _container[count] = element;
                        
                        ++count;
                    }

                }
                Container(const Container& other, std::string label="") : 
                    _container(new T[other.size()]), _size(other.size()), _label((label != "") ? label : other._label), _type_label(other._type_label), _dynamic(other._dynamic)
                {
                    std::copy(other._container, other._container+other.size(), _container);
                }
                ~Container() {delete[] _container;}

                iterator begin() { return iterator(_container); }
                iterator end() { return iterator(_container+size()); }
                const_iterator begin() const { return const_iterator(_container); }
                const_iterator end() const { return const_iterator(_container+size()); }
                Container operator-() const;
                Container operator+() const;
                Container& operator++();
                Container& operator--();
                const Container operator=(const Container& other);
                const Container operator+ (const Container& other) const;
                const Container operator- (const Container& other) const;
                const Container operator* (const T& other) const;
                const bool operator== (const Container& other) const;
                Container& operator+= (const Container& other);
                Container& operator*= (const T& other);
                Container& operator-= (const Container& other);
                const Container dot(const Container& other) const;
                const T& operator[] (const int&) const;
                const int size() const {return _size;}
                const bool empty() const {return _size <= 0;}
                const bool fixed() const {return !_dynamic;}
                void setLabel(const std::string& label){_label = label;}
                friend std::ostream& operator<< (std::ostream& o, const Container& d)
                {
                    o << d._type_label << "[(";
                    for(unsigned int i{0}; i < d.size(); ++i)
                    {
                        o << d[i];
                        if(i < d.size()-1) o << ", ";
                    }

                    o << "), '" << typeid(T).name() << "'";
                    
                    if(d._label != "") o << ", label='" << d._label << "'";
                    
                    o << "]";

                    return o;
                }
        };
    };
};

template<typename T>
PHYS::Data::Container<T>& PHYS::Data::Container<T>::operator*= (const T& other)
{
    if(*typeid(other).name() != 'f' && *typeid(other).name() != 'd' && *typeid(other).name() != 'i')
    {
        throw std::invalid_argument("Scale factor must be integer/float/double");
    }

    T _temp_array[size()];

    for(unsigned int i{0}; i < size(); ++i)
    {
        _temp_array[i] = this->operator[](i)*other;
    }

    std::copy(_temp_array, _temp_array+size(), this->_container);

    return *this;
}

template<typename T>
const PHYS::Data::Container<T> PHYS::Data::Container<T>::operator* (const T& other) const
{
    PHYS::Data::Container<T> _temp(*this);
    _temp *= other;
    return _temp;
}

template<typename T>
const PHYS::Data::Container<T> PHYS::Data::Container<T>::operator=(const PHYS::Data::Container<T> &rhs)
{
    this->_container = rhs._container;
    this->_label = rhs._label;
    this->_type_label = rhs._type_label;
    this->_dynamic = rhs._dynamic;

    return *this;
}

template<typename T>
const T& PHYS::Data::Container<T>::operator[](const int &index) const
{
    if(size() < 1) throw std::runtime_error("Cannot Access Elements of array of size < 1");
    if (index < 0 || index > size()-1)
    {
        throw std::out_of_range("Invalid array index '" + std::to_string(index) + "' specified, must be positive and within Container size range [0,"+std::to_string(size())+"]");
    }
    return _container[index];
}

template<typename T>
const PHYS::Data::Container<T> PHYS::Data::Container<T>::operator+ (const PHYS::Data::Container<T>& other) const
{
    PHYS::Data::Container<T> _temp(*this);
    _temp._label = "";
    _temp += other;
    return _temp;
}

template<typename T>
PHYS::Data::Container<T>& PHYS::Data::Container<T>::operator++ ()
{
    T _temp_array[size()];

    for(unsigned int i{0}; i < size(); ++i)
    {
        _temp_array[i] = this->operator[](i)+1;
    }

    std::copy(_temp_array, _temp_array+size(), this->_container);

    return *this;
}

template<typename T>
PHYS::Data::Container<T>& PHYS::Data::Container<T>::operator-- ()
{
    T _temp_array[size()];

    for(unsigned int i{0}; i < size(); ++i)
    {
        _temp_array[i] = this->operator[](i)-1;
    }

    std::copy(_temp_array, _temp_array+size(), this->_container);

    return *this;
}

template<typename T>
PHYS::Data::Container<T>& PHYS::Data::Container<T>::operator+= (const PHYS::Data::Container<T>& other)
{
    if(other.size() != size()) throw std::runtime_error("Cannot add "+_type_label+"s with different lengths");

    for(unsigned int i{0}; i < size(); ++i)
    {
        this->_container[i] += other[i];
    }

    return *this;
}

template<typename T>
PHYS::Data::Container<T>& PHYS::Data::Container<T>::operator-= (const PHYS::Data::Container<T>& other)
{
    if(other.size() != size()) throw std::runtime_error("Cannot add "+_type_label+"s with different lengths");

    for(unsigned int i{0}; i < size(); ++i)
    {
        this->_container[i] -= other[i];
    }

    return *this;
}

template<typename T>
PHYS::Data::Container<T> PHYS::Data::Container<T>::operator-() const
{
    PHYS::Data::Container<T> _temp(*this);
    for(unsigned int i{0}; i < size(); ++i)
    {
        _temp._container[i] = -this->_container[i];
    }

    return _temp;
}

template<typename T>
PHYS::Data::Container<T> PHYS::Data::Container<T>::operator+() const
{
    PHYS::Data::Container<T> _temp(*this);
    for(unsigned int i{0}; i < size(); ++i)
    {
        _temp._container[i] = this->_container[i];
    }

    return _temp;
}

template<typename T>
const PHYS::Data::Container<T> PHYS::Data::Container<T>::dot(const PHYS::Data::Container<T>& other) const
{
    const PHYS::Data::Container<T> _self(*this);
    PHYS::Data::Container<T> _temp(size(), "", _type_label, _dynamic);
    if(other.size() != size()) throw std::runtime_error("Cannot perform dot product on "+_type_label+"s with different lengths");

    for(unsigned int i{0}; i < _self.size(); ++i)
    {
        std::cout << _self[i] << "+" << other[i] << std::endl;
        _temp._set_element(i, _self[i]*other[i]);
    }

    return _temp;
}


template<typename T>
const PHYS::Data::Container<T> PHYS::Data::Container<T>::operator- (const PHYS::Data::Container<T>& other) const
{
    PHYS::Data::Container<T> _temp(*this);
    _temp._label = "";
    _temp -= other;
    return _temp;
}

template<typename T>
const bool PHYS::Data::Container<T>::operator== (const PHYS::Data::Container<T>& other) const
{
    const PHYS::Data::Container<T> _temp(*this);

    for(unsigned int i{0}; i < size(); ++i)
    {
        if(_temp[i] != other[i]) return false;
    }

    return true;
}

#endif