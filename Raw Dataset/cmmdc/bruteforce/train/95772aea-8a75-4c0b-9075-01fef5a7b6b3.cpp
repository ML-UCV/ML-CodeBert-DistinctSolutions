#include<iostream>
#include<fstream>
using namespace std;

int main ()

{

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    long a,b,i,d=0;

    f>>a>>b;



    for(i=2;i<=a;i++)

        if(a%i==0&&b%i==0)

            d=i;

    g<<d;

    f.close();g.close();

    return 0;

}
