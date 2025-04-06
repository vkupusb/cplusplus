
#include <iostream>
#include "UniquePtr.h"

template class Pointers::SmartPointers::Unique::UniquePtr<int>;

template <class T>
Pointers::SmartPointers::Unique::UniquePtr<T>::UniquePtr(T *ptr): m_ptr{ptr}
{
    std::cout<<"Default constructor called...\n";
}

template <class T>
Pointers::SmartPointers::Unique::UniquePtr<T>::~UniquePtr()
{
    std::cout<<"Default destructor called...\n";
    delete m_ptr;
}

template <class T>
Pointers::SmartPointers::Unique::UniquePtr<T>::UniquePtr(UniquePtr &&moveObject): m_ptr{moveObject.m_ptr}
{
    std::cout<<"Default constructor called...\n";
    moveObject.m_ptr = nullptr; // avoid deleteing twice
}

template <class T>
Pointers::SmartPointers::Unique::UniquePtr<T> &Pointers::SmartPointers::Unique::UniquePtr<T>::operator=(UniquePtr &&moveObject)
{
    if( this != &moveObject){
        delete m_ptr;
        m_ptr = moveObject.m_ptr;
        moveObject.m_ptr = nullptr;
    }
    return *this;
}

template <class T>
T &Pointers::SmartPointers::Unique::UniquePtr<T>::operator*() const
{
    return *m_ptr;
}

template <class T>
T *Pointers::SmartPointers::Unique::UniquePtr<T>::operator->() const
{
    return m_ptr;
}

template <class T>
T *Pointers::SmartPointers::Unique::UniquePtr<T>::get() const
{
    return m_ptr;
}

template <class T>
T *Pointers::SmartPointers::Unique::UniquePtr<T>::release()
{
    T* temp = m_ptr;
    m_ptr = nullptr;
    return temp;
}

template <class T>
void Pointers::SmartPointers::Unique::UniquePtr<T>::reset(T *ptr)
{
    delete m_ptr;
    m_ptr = ptr;
}

template <class T>
Pointers::SmartPointers::Unique::UniquePtr<T>::operator bool() const
{
    return m_ptr != nullptr;
}
