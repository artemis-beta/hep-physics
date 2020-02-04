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
                void push_back(const T&);
                void pop_back();
                void pop_front();
        };
    };
};

template<typename T>
void PHYS::Data::DynamicArray<T>::push_back(const T& value)
{
    int log_counter = 0;
    std::cout << log_counter++ << std::endl;
    const int _current_size = this->size();
    std::cout << log_counter++ << std::endl;
    T _temp_container[_current_size+1];
    std::cout << log_counter++ << std::endl;
    for(unsigned int i{0}; i < _current_size; ++i)
    {
        std::cout << log_counter++ << std::endl;
        _temp_container[i] = this->operator[](i);
    }
    std::cout << log_counter++ << std::endl;
    if(_current_size < 1) _temp_container[0] = value;
    else
    {
        
        _temp_container[_current_size] = value;
    }
    std::cout << log_counter++ << std::endl;

    std::copy(_temp_container, _temp_container+_current_size+1, this->_container);
    this->_size = _current_size+1;

    if(this->size() != _current_size+1) throw std::runtime_error("Could not resize array during push_back");
}

template<typename T>
void PHYS::Data::DynamicArray<T>::pop_back()
{
    const int _current_size = this->size();
    T _temp_container[_current_size-1];
    
    std::copy(_temp_container, _temp_container+_current_size-1, this->_container);
    this->_size = _current_size-1;

    if(this->size() != _current_size-1) throw std::runtime_error("Could not resize array during pop_back");
}

template<typename T>
void PHYS::Data::DynamicArray<T>::pop_front()
{
    const int _current_size = this->size();
    T _temp_container[_current_size-1];
    for(unsigned int i{1}; i < _current_size; ++i) _temp_container[i-1] = this->operator[](i);

    std::copy(_temp_container, _temp_container+_current_size-1, this->_container);
    this->_size = _current_size-1;

    if(this->size() != _current_size-1) throw std::runtime_error("Could not resize array during push_back");
}

#endif