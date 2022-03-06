#include <iostream>
#include <fstream>
using namespace std;



int main()

{

    ifstream in("cmmdc.in");

    ofstream out("cmmdc.out");

    int a,b,r;

    in>>a>>b;

    while(b!=0)

    {

        r=a%b;

        a=b;

        b=r;

    }

    if(a==1)

        out<<"0";

    else out<<a;

   return 0;

}
