#include <iostream>
#include <fstream>




using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int main()

{

    int a,b,x,y,r,i;

    f>>a>>b;

    x=a;

    y=b;

    r=x%y;

    while(r!=0)

    {

        x=y;

        y=r;

        r=x%y;

    }

    if(y==1) g<<"0";

    else

    {

        for(i=a;i>=2;i--)

        {

            if(a%i==0)

            {

                if(b%i==0)

                {

                    g<<i;

                    break;

                }

            }

        }

    }





    return 0;

}
