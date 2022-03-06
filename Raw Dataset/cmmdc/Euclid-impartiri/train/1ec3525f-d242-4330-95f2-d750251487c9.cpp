#include <fstream>
using namespace std;

int main()

{

   ifstream in("cmmdc.in");

   ofstream out("cmmdc.out");

   int a,b,r;

   in>>a>>b;

   r=a%b;

   while(r)

        {

            a=b;

            b=r;

            r=a%b;

        }

   if(b==1)

        out<<0;

    else out<<b;

}
