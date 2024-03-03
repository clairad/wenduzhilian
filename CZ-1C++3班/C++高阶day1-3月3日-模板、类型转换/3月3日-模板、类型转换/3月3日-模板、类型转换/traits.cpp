#include "traits.h"
#include <iostream>

bool TrueType::get()
{
    return true;
}

bool FalseType::get()
{
    return false;
}

template<class T>
inline void TypeTraits<T>::print()
{
    std::cout << "123" << std::endl;
}