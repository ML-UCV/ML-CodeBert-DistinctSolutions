#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void invers(long long &x,long long &y,long long a,long long b)

{

    if(b==0)

        y=0,x=1;

    else

    {

        invers(x,y,b,a%b);

        long long aux;

        aux=x;

        x=y;

        y=aux-(a/b)*y;

    }

}

int main()

{

    long long n,minune,a,b;

    fin>>n>>minune;

    a=1;

    invers(a,b,n,minune);

    if(a<=0)

        a=minune+a%minune;

    fout<<a;

    return 0;

}
