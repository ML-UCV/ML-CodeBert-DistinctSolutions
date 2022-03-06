#include <fstream>


using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a,b,r;

int main()

{

    f>>a>>b;

    while(b!=0)

    {

       r=a%b;

       a=b;

       b=r;

    }

   if(a!=1)



    g<<a;

   else

    g<<"0";

    return 0;

}
