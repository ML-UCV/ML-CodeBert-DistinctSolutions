#include <iostream>
#include <fstream>


using namespace std;





ifstream f("inversmodular.in");

ofstream g("inversmodular.out");





void euclidext( long long a ,long long b , long long &x,long long &y)

{



   if(!b)

   {

       x=1;

       y=0;

       return;

    }

    euclidext(b,a%b,x,y);

    long long aux=x;

    x=y;

    y=aux -(a/b)*y;

}





int main()

{

   long long a,b,x,y;

   f>>a>>b;

   euclidext(a,b,x,y);

   if(x<0)

    g<<x+b;

   else

    g<<x;

    return 0;

}
