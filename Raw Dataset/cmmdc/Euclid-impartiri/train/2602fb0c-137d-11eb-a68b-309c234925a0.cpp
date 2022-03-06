#include <cstdio>
using namespace std;

class MyClass

{

private:

    int a , b;

public:

    MyClass(int x , int y)

    {

        a = x;

        b = y;

    }

    void cmmdc()

    {

        int r;

        while(b)

        {

            r = a % b;

            a = b;

            b = r;

        }

    }

    int geta()

    {

        if(a == 1)

            return 0;

        return a;

    }

};

int main()

{

    freopen("cmmdc.in" , "r" , stdin);

    freopen("cmmdc.out" , "w" , stdout);

    int x , y;

    scanf("%d%d" , &x , &y);

    MyClass d(x , y);

    d.cmmdc();

    printf("%d\n" , d.geta());

    return 0;

}
