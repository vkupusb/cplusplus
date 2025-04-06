#pragma once

// Reference
// https://en.cppreference.com/w/cpp/memory/unique_ptr

namespace Pointers::SmartPointers::Unique
{

    template <class T>
    class UniquePtr
    {
    public:
        explicit UniquePtr(T *ptr = nullptr);
        ~UniquePtr();

        /*The class satisfies the requirements of MoveConstructible and MoveAssignable,
         but of neither CopyConstructible nor CopyAssignable.*/
        UniquePtr(UniquePtr &copyObject) = delete;
        UniquePtr &operator=(UniquePtr &copyObject) = delete;

        UniquePtr(UniquePtr &&moveObject);
        UniquePtr &operator=(UniquePtr &&moveObject);

        T &operator*() const;
        T *operator->() const;
        T *get() const;
        T *release();
        void reset(T *ptr = nullptr);
        explicit operator bool() const;

    private:
        T *m_ptr;
    };

    template <class T>
    UniquePtr<T>::UniquePtr(T *ptr) : m_ptr{ptr}
    {
        std::cout << "UniquePtr constructor called...\n";
    }

    template <class T>
    UniquePtr<T>::~UniquePtr()
    {
        std::cout << "UniquePtr destructor called...\n";
        delete m_ptr;
    }

    template <class T>
    UniquePtr<T>::UniquePtr(UniquePtr &&moveObject) : m_ptr{moveObject.m_ptr}
    {
        std::cout << "UniquePtr move constructor called...\n";
        moveObject.m_ptr = nullptr; // avoid deleteing twice
    }

    template <class T>
    UniquePtr<T> &UniquePtr<T>::operator=(UniquePtr &&moveObject)
    {
        if (this != &moveObject)
        {
            delete m_ptr;
            m_ptr = moveObject.m_ptr;
            moveObject.m_ptr = nullptr;
        }
        return *this;
    }

    template <class T>
    T &UniquePtr<T>::operator*() const
    {
        return *m_ptr;
    }

    template <class T>
    T *UniquePtr<T>::operator->() const
    {
        return m_ptr;
    }

    template <class T>
    T *UniquePtr<T>::get() const
    {
        return m_ptr;
    }

    template <class T>
    T *UniquePtr<T>::release()
    {
        T *temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    template <class T>
    void UniquePtr<T>::reset(T *ptr)
    {
        delete m_ptr;
        m_ptr = ptr;
    }

    template <class T>
    UniquePtr<T>::operator bool() const
    {
        return m_ptr != nullptr;
    }

}