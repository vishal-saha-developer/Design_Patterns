#include <bits/stdc++.h>
using namespace std;

class ProductA
{
public:
    virtual void Operation() const = 0;
};

class ProductB
{
public:
    virtual void Operation() const = 0;
};

class ProductA1 : public ProductA
{
public:
    void Operation() const
    {
        cout << "ProductA1 Operation\n";
    }
};

class ProductA2 : public ProductA
{
public:
    void Operation() const
    {
        cout << "ProductA2 Operation\n";
    }
};

class ProductB1 : public ProductB
{
public:
    void Operation() const
    {
        cout << "ProductB1 Operation\n";
    }
};

class ProductB2 : public ProductB
{
public:
    void Operation() const
    {
        cout << "ProductB2 Operation\n";
    }
};

class AbstractFactory
{
public:
    virtual ProductA *CreateProductA() const = 0;
    virtual ProductB *CreateProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    ProductA *CreateProductA() const
    {
        return new ProductA1;
    }
    ProductB *CreateProductB() const
    {
        return new ProductB1;
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    ProductA *CreateProductA() const
    {
        return new ProductA2;
    }
    ProductB *CreateProductB() const
    {
        return new ProductB2;
    }
};

int main(int argc, char **argv)
{
    AbstractFactory *factory = new ConcreteFactory1;
    ProductA *productA = factory->CreateProductA();
    ProductB *productB = factory->CreateProductB();
    productA->Operation();
    productB->Operation();

    delete productA;
    delete productB;
    delete factory;

    factory = new ConcreteFactory2;
    productA = factory->CreateProductA();
    productB = factory->CreateProductB();
    productA->Operation();
    productB->Operation();
    delete productA;
    delete productB;
    delete factory;
    return 0;
}