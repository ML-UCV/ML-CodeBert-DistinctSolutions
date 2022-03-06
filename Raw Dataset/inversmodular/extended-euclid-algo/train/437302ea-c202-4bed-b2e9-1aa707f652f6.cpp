#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long int a,n;

long long int invmod(long long int a,long long int b,long long int &x,long long int &y)

{

    if (b==0)

    {

        x=1;

        y=0;

        return a;

    }

    long long int aux,d;

    d=invmod(b,a%b,x,y);

    aux=x;

    x=y;

    y=aux-(a/b)*y;

    return d;

}

int main()

{

    fin>>a>>n;

    long long int x,y,d;

    d=invmod(a,n,x,y);

    x=x%n;

    if (x<0)

        x+=n;

    fout<<x;

    return 0;

}
