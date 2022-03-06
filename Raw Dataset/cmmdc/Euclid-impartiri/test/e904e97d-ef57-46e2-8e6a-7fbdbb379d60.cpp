#include <stdio.h>
#include <fstream>
using namespace std;



int main()

{

    int r,a,b;

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>a;

    f>>b;

    while(b){

      r=a%b;

      a=b;

      b=r;

    }

    if(a==1)

      g<<0;

    else

      g<<a;

    return 0;

}
