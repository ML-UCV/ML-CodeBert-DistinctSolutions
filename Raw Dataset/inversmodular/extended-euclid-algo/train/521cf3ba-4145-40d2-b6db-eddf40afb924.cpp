#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void inversmod(long long &x, long long &y, int a, int b)

{

     if (b==0)

     {

         x=1;

         y=0;

     }

     else

     {

         inversmod(x, y, b, a%b);

         long long aux=x;

         x=y;

         y=aux-y*(a/b);

     }

}



int main()

{

    long long x, y;

    int a, n;

    fin>>a>>n;

    inversmod(x, y, a, n);

    while(x<=0)

        x=x+n;

    fout<<x;

    return 0;

}
