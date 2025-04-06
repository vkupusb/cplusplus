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

        T& operator*() const;
        T* operator->() const;
        T* get() const;
        T* release();
        void reset(T* ptr=nullptr);
        explicit operator bool() const;

    private:
        T *m_ptr;
    };

 
}