#include <iostream>
#include "UniquePtr.h"

class A{
    public:
    A(){std::cout<<"A constructor called ...\n";}
    virtual ~A(){std::cout<<"A destructor called ...\n";}
    virtual void display(){std::cout<<" A::display()...\n";}
    
};

class B: virtual public A{
    public:
    B(){std::cout<<"B constructor called ...\n";}
    ~B(){std::cout<<"B destructor called ...\n";}
    void display(){std::cout<<" B::display()...\n";}
};

class C: virtual public A{
    public:
    C(){std::cout<<"C constructor called ...\n";}
    ~C(){std::cout<<"C destructor called ...\n";}
    void display(){std::cout<<" C::display()...\n";}

};

class D: public B, public C{
    public:
    D(){std::cout<<"D constructor called ...\n";}
    ~D(){std::cout<<"D destructor called ...\n";}
    void display(){std::cout<<" D::display()...\n";}
};

int main(int agrc,char** argv)
{
    Pointers::SmartPointers::Unique::UniquePtr<A> a{new D};
    a->display();

    return 0;
}