#ifndef vectors_hpp
#define vectors_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

template <class T>
class Rvec : public std::vector<T>
{
public:
    Rvec<T> operator+(const Rvec<T>& rhs);
    Rvec<T> operator-(const Rvec<T>& rhs);
    Rvec<T> operator*(const double scalar);
    Rvec<T> operator+(const double scalar);
    Rvec<T> operator-(const double scalar);
    Rvec<T> operator*(const Rvec<T>& rhs);
    Rvec<T> operator/(const Rvec<T>& rhs);
    void show();
};

template <class T>
Rvec<T> Rvec<T>::operator+(const Rvec<T>& rhs)
{
    for(unsigned long i = 0; i < this->size(); i++)
    {
        this->at(i)+=rhs.at(i);
    }
    return *this;
}

template <class T>
Rvec<T> Rvec<T>::operator-(const Rvec<T>& rhs)
{
    for(unsigned long i = 0; i < this->size(); i++)
    {
        this->at(i)-=rhs.at(i);
    }
    return *this;
}

template <class T>
Rvec<T> Rvec<T>::operator*(const double scalar)
{
    for(unsigned long i = 0; i < this->size();i++)
    {
        this->at(i)*=scalar;
    }
    return *this;
}

template <class T>
Rvec<T> Rvec<T>::operator+(const double scalar)
{
    for(unsigned long i = 0; i < this->size();i++)
    {
        this->at(i)+=scalar;
    }
    return *this;
}

template <class T>
Rvec<T> Rvec<T>::operator-(const double scalar)
{
    for(unsigned long i = 0; i < this->size();i++)
    {
        this->at(i)-=scalar;
    }
    return *this;
}

template <class T>
Rvec<T> Rvec<T>::operator*(const Rvec<T>& rhs)
{
    for(unsigned long i = 0; i < this->size();i++)
    {
        this->at(i)*=rhs.at(i);
    }
    return *this;
}

template <class T>
Rvec<T> Rvec<T>::operator/(const Rvec<T>& rhs)
{
    for(unsigned long i = 0; i < this->size();i++)
    {
        this->at(i)/=rhs.at(i);
    }
    return *this;
}

template <class T>
void Rvec<T>::show()
{
    for(unsigned long i = 0; i < this->size(); i++)
    {
        std::cout << this->at(i) << std::endl;
    }
}

#endif /* vectors_hpp */
