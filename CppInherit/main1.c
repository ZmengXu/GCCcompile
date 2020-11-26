#include <iostream>

//class A;

template <class T>
class base
{
public:
    //T Tval_; //This is wrong
    T * pt(){return static_cast<T*>(this);}//static_cast<T*>(this);
    int baseVal_;
    base()
    {
        baseVal_ = 99;
        std::cout << "This is in base(), baseVal_ = " << baseVal_ << std::endl;
        pt()->printA();
    }
    base(int val)
    {
        baseVal_ = val;
        std::cout << "This is in base(int val), baseVal_ = " << baseVal_ << std::endl;
    }
};


class A: public base<A>
{
public:
    int AVal_;
    
    A()
    :
    base<A>()
    {
        AVal_ = 999;
        std::cout << "This is in A(), baseVal_ = " << baseVal_ << ", AVal_ = " << AVal_  << std::endl; 
    }
    
    A(int val)
    :
    base<A>(val)
    {
        AVal_ = val;
        std::cout << "This is in A(int val), baseVal_ = " << baseVal_ << ", AVal_ = " << AVal_  << std::endl; 
    }
    
    void printA()
    {
        std::cout << "This is in printA()" << std::endl; 
    }
};

int main()
{
	A a1;
	A a2(1);
};


