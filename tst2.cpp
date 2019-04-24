#include <iostream>
using namespace std;
class num
{
    int a;
public:
    num(int b = 1)
    {
        a = b;
    }
    void print()
    {
        cout<<++a<<endl;
    }
    void print() const 
    {
        cout<<a<<endl;
    }
};
int main()
{
    num x;
    const num y(3);
    x.print();
    y.print();
    return 0;
}