#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int main()

{

    short int a,b,i,j,x,y,d1[100000],d2[100000],maxi;

    f>>a>>b;

    i=0;

    for(x=1; x<=a; x++)

    if(a%x==0) {

                  d1[i]=x;

                  i++;

               }

    j=0;

    for(y=1; y<=a; y++)

    if(b%y==0) {

                  d2[j]=y;

                  j++;

               }

    maxi=0;

    for(x=1 ;x<=i; x++)

        for(y=1; y<=j; y++)

    {

        if(d1[x]==d2[y]&&d1[x]>maxi) maxi=d1[x];

    }

    g<<maxi;

    f.close();

    g.close();

    return 0;

}
