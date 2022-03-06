#include <fstream>


using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a,b,p;

int main()

{

   f>>a>>b;

   while(a%b!=0){p=a%b;

                 a=b;

                 b=p;

                }

    if(p!=1)g<<p<<'\n';

    else g<<0<<'\n';

    return 0;

}
