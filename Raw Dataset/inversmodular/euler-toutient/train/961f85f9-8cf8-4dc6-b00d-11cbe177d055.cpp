#include <fstream>


using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");

long long a, putere, nr, r;

long long n;

long long fi(long n)

{

    long long aux=n,prod=1;

    long long d=2, nr=1;

    while(d*d<=aux)

    {

        if(aux%d==0)

        {

            while(aux%d==0)

                 aux=aux/d;

            prod=prod*d;

            nr=nr*(d-1);

        }

        d++;

    }

    if(aux!=1)

        nr*=(aux-1);

    return (long long)n/prod*nr;

}

int main()

{

    fin >> a >> n;

    putere=fi(n)-1;

    nr=a;

    r=1;

    while(putere!=0)

    {

        if(putere%2==1)

            r=(r*nr)%n;

        nr=(nr*nr)%n;

        putere=putere/2;

    }

    fout << r;

    return 0;

}
