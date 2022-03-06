#include <fstream>


using namespace std;

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");

int main()

{

   int a,b,r;

   in>>a>>b;

   r=a%b;

   while(r!=0)

   {

       a=b;

       b=r;

       r=a%b;

   }

   if(b==1)

     out<<0;

    else

     out<<b;

}
