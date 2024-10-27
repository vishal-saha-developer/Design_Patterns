#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    Singleton(string data) : data{data}
    {
    }
    static Singleton *instance;
    static mutex mtx;
    string data;

public:
    Singleton(const Singleton &other) = delete;
    Singleton &operator=(const Singleton &other) = delete;

    static Singleton &getInstance(string data)
    {
        lock_guard<mutex> lock(mtx);
        if (instance == nullptr)
            instance = new Singleton(data);
        return *instance;
    }

    void printData()
    {
        cout << data << "\n";
    }
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;


int main(int argc, char **argv)
{
    Singleton& a=Singleton::getInstance("Hello");
    a.printData();
    Singleton& b=Singleton::getInstance("World");
    b.printData();
    return 0;
}