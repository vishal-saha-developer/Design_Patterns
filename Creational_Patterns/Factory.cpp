#include <bits/stdc++.h>
using namespace std;

// Actual Classes
class Product
{
public:
    virtual string Operation() const = 0;
};

class Product1 : public Product
{
public:
    string Operation() const
    {
        return "Product1 Operation";
    }
};

class Product2 : public Product
{
public:
    string Operation() const
    {
        return "Product2 Operation";
    }
};

// Factory Classes
class Creator
{
public:
    virtual Product *FactoryMethod() const = 0;
    void Operation(Product *product)
    {
        cout << product->Operation() << "\n";
    }
};

class Creator1 : public Creator
{
public:
    Product *FactoryMethod() const
    {
        return new Product1;
    }
};

class Creator2 : public Creator
{
public:
    Product *FactoryMethod() const
    {
        return new Product2;
    }
};

class Client
{
public:
    void ClientCode(Creator *creator)
    {
        Product *product = creator->FactoryMethod();
        creator->Operation(product);
        delete product;
    }
};

// Driver Code

int main(int argc, char **argv)
{
    Client client;
    client.ClientCode(new Creator1);
    client.ClientCode(new Creator2);
    return 0;
}