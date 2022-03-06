#include <fstream>


using namespace std;

ifstream in ("cmmdc.in");

ofstream out ("cmmdc.out");

int main()

{

    int a,b,c;

   in>>a>>b;

   while (b)

   {

       c=a%b;

       a=b;

       b=c;

   }

   if (a==1)

    out <<0;

   else

   out <<a;

    return 0;

}
