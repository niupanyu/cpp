#include <iostream>

using namespace std;

class Functor
{
    int x, y;
    public:
        Functor()
        {
            x = 0;
            y = 0;
        }

        Functor(int a, int b)
        {
            x = a;
            y = b;
        }
        int operator()(){
            return x+y;
        }

};

int main()
{
    Functor f(1,3);

    cout << f() << endl;

    volatile int i;
    i = 0;
    i = !i;
    i = !i;
    cout << i << endl;

    return 0;
};
