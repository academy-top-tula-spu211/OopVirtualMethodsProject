#include <iostream>

class Animal
{
public:
    virtual void Say() = 0; //{ std::cout << "???\n"; }
    virtual ~Animal() = default;
    /*{ 
        std::cout << "Animal destruct\n"; 
    }*/
};

class Cat : public Animal
{
    int* array;
public:
    Cat() 
    { 
        array = new int[100]; 
    }

    void Say() override { std::cout << "myau\n"; }
    ~Cat()
    { 
        std::cout << "Cat destruct\n"; 
        delete array;
    }
};

class Dog : public Animal
{
    int* array;
public:
    Dog() { array = new int[100]; }
    void Say() override { std::cout << "gaff\n"; }
    ~Dog() { std::cout << "Dog destruct\n"; }                                                
};

class Pigg final : public Animal
{
public:
    void Say() override { std::cout << "hryu\n"; }
};

class HomeCat : public Cat
{
public:
    void Say() override { std::cout << "murr\n"; }
    ~HomeCat()
    {
        std::cout << "HomeCat destruct\n";
    }
};

//class SeaPigg : public Pigg
//{
//
//};

int main()
{
    /*
    Animal* animal = new Dog();
    animal->Say();
    animal = new Cat();
    animal->Say();

    animal = new Pigg();
    animal->Say();
    */

    Animal* animal; //= new Animal();

    std::cout << "----------------\n";

    animal = new HomeCat();
    delete animal;

}
