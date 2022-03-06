#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;



int main()

{

    int a,b,c;

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>a>>b;

    for(int i=1;i<=min(a,b);i++)

    {

        if(a%i==0 && b%i==0)

            c=i;

    }

    if(c==1)

        c=0;

    g<<c;

    return 0;

}
