#include <fstream>




long long a,n,aux,inv,ins;

using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void invers(long long &x,long long &y,int a,int b)

{

    if(b==0)

        x=1, y=0;

    else

    {

        invers(x,y,b,a%b);

        aux=x;

        x=y;

        y=aux-(a/b)*y;

    }

}

int main()

{

    fin>>a>>n;

    invers(inv,ins,a,n);

    if(inv<=0)

        inv=n+inv%n;

    fout<<inv;

    return 0;

}
