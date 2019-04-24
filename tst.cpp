#include <iostream>
using namespace std;
class Test
{
public:
    int data = 1;
    Test(int d) { data = d; }
    Test operator++()
    {
        ++data;
        return Test(data);
    }
};
int main()
{
    Test test(1);
    ++test;
    return 0;
}