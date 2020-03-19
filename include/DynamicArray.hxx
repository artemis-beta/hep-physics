 #ifndef __DYNAMICARRAY_HXX__
 #define __DYNAMICARRAY_HXX__
 
#include "Container.hxx"

#include <iostream>
#include <algorithm>

namespace PHYS
{
    namespace Data
    {
        template<typename T>
        /*! @brief  DynamicArray Class
        @details    A dynamic size container class
        @version    0.1.0
        @author     Kristian Zarebski
        @date 	    last modified 2020-01-31
        @copyright  MIT License
        */
        class DynamicArray : public Container<T>
        {
            public:
                DynamicArray(const std::string label="") :
                    Container<T>(label, "DynamicArray", true) {}
                DynamicArray(const int &size, const std::string label="") :
                    Container<T>(size, label, "DynamicArray", true) {}
                DynamicArray(const std::initializer_list<T>& elements, const std::string label="") :
                    Container<T>(elements, label, "DynamicArray", true) {}
                DynamicArray(Container<T>& other, std::string label="") : 
                    Container<T>(other, label) {}

                void push_back(const T&);
                void pop_back();
                void pop_front();
                void insert(const int&, const T&);
        };
    };
};

template<typename T>
void PHYS::Data::DynamicArray<T>::push_back(const T& value)
{
    const int _current_size = this->size();
    T* _temp_container = new T[_current_size+1];
    if(_current_size < 1)
    {
        _temp_container[0] = value;
    }
    else
    {
        _temp_container[_current_size] = value;
    }
    for(unsigned int i{0}; i < _current_size; ++i)
    {
        _temp_container[i] = this->operator[](i);
    }
    delete[] this->_container;
    this->_container = _temp_container;
    this->_size = _current_size+1;    
}

template<typename T>
void PHYS::Data::DynamicArray<T>::pop_back()
{
    const int _current_size = this->size();
    T*  _temp_container = new T[_current_size-1];
    for(unsigned int i{0}; i < _current_size-1; ++i)
    {
        _temp_container[i] = this->operator[](i);
    }
    if(_current_size < 1) throw std::runtime_error("Array is of size 0, pop_back failed");

    delete[] this->_container;
    this->_container = _temp_container;
    this->_size = _current_size-1;
}

template<typename T>
void PHYS::Data::DynamicArray<T>::pop_front()
{
    const int _current_size = this->size();
    T*  _temp_container = new T[_current_size-1];
    for(unsigned int i{1}; i < _current_size; ++i)
    {
        _temp_container[i-1] = this->operator[](i);
    }
    if(_current_size < 1) throw std::runtime_error("Array is of size 0, pop_front failed");

    delete[] this->_container;
    this->_container = _temp_container;
    this->_size = _current_size-1;
}

template<typename T>
void PHYS::Data::DynamicArray<T>::insert(const int& position, const T& value)
{
    PHYS::Data::DynamicArray<T> _temp;

    for(int i{0}; i < this->size(); ++i)
    {
        if(i == position) _temp.push_back(value);
        _temp.push_back(this->operator[](i));
    }

    int _new_size = this->size()+1;

    std::swap(this->_size, _new_size);
    std::swap(this->_container, _temp._container);
}

#endif