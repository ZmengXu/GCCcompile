#include <iostream>
/* Structure similar to boost's enable if, to use
  SFINAE */

template <typename X, class U = void>
struct test {
    typedef U type;
};

enum Commands {
    Swim,
    Fly
};

/* Structure used for template overloading,
  as no partial function template specialization available */
template<Commands T>
struct Param {

};

template <class T>
class Invoker
{
public:
    typedef T workerClass;

    workerClass *wc() {
        return static_cast<workerClass*>(this);
    }

    template <Commands command>
    void invoke() {
        invoke2(Param<command>());
    }

    /* If the child class has those functions, call them */
    /* Needs template paramter Y to apply SFINAE */
    template<class Y=workerClass>
    typename test<decltype(&Y::fly)>::type 
    invoke2(Param<Fly>) {
        wc()->fly();
    }

    template<class Y=workerClass>
    typename test<decltype(&Y::swim)>::type 
    invoke2(Param<Swim>) {
        wc()->swim();
    }

    template<Commands command>
    void invoke2(Param<command>) {
        /* Default action */
        printf("Default handler for command %d\n", command);
    }
};

// 基类
template <class T, class Inv = Invoker<T> >
class BaseClass
 : public Inv
{
public:

    template<Commands command>
    void invoke() {
        Inv::template invoke<command>();
        // This is wrong
        //T invoke<command>();
    }

};

// 派生类
class MyClass : public BaseClass<MyClass>
{
public:
    void swim() {
        printf("Swimming like a fish!\n");
    }

    /* void fly(); */
};


void testing() {
    MyClass foo;
    foo.invoke<Fly>(); /* No 'void fly()' in MyClass, calls the default handler */
    foo.invoke<Swim>(); /* Should print the swimming message */
}


int main()
{
    testing();
    return 0;
}