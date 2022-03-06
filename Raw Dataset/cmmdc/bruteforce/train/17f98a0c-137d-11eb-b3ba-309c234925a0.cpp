#include <iostream>
#include <fstream>


using namespace std;



int main()

{

    int a,b,c;

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>a>>b;

    if(a==1 || b==1)

        c=0;

    if(a>b)

    {

        for(int i=1;i<=b;i++)

        {

            if(a%i==0 && b%i==0)

                c=i;

        }

    }

    else

    {

        for(int i=1;i<=a;i++)

        {

            if(a%i==0 && b%i==0)

                c=i;

        }

    }

    if(c==1)

        c=0;

    g<<c;

    return 0;

}
