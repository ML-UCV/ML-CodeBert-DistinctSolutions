#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long a,b,x,y,z=1,r,c,in;

int main()

{

  f >> a >> b;in=b;

   while(a)

    {

        r=b%a;

        c=b/a;

        b=a;

        a=r;

        x=y-c*z;

        y=z;

        z=x;

    }

    while(y<0)

      y+=in;

      g << y ;



}
