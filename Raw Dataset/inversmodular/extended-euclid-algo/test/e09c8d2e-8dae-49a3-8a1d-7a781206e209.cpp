#include <fstream>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long a,n;

void gcd(long long &x, long long &y, int a, int b)

{

     if(!b)

         x = 1, y = 0;

     else

     {

         gcd(x,y,b,a%b);

         long long aux = x;

         x = y;

         y = aux - y * (a / b);

     }

}

int main()

{

    long long inv = 0, ins;

    f >> a >> n;

    gcd(inv,ins,a,n);

    if(inv <= 0)

       inv = n + inv % n;

    g << inv;

    return 0;

}
