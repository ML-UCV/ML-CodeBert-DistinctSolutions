#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");







int main()

{

   long long a,b;



   f>>a>>b;



   while (a!=b){

    if (a>b){

        a=a-b;

    }else b=b-a;

   }

    if (a==1 && b==1)

        g<<"0";

    else {

    if (a>b)

    g<<a;

   else g<<b;

    }

    return 0;

}
