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

    for(int i = 0; i < 10; i++)
    {
        int j ;
        int k;
        cout << &j << &k << endl;
    }


    return 0;
};
