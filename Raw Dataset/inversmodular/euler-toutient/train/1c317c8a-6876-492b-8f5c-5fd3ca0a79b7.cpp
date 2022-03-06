#include<fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int phi(long long m)

{

    long long k=m,i;

    for(i=2;i*i<=m;i++)

        if(m%i==0)

        {

            while(m%i==0)m/=i;

            k=k/i*(i-1);

        }

    if(m!=1)

        k=k/m*(m-1);

    return k;

}

int main()

{

    long long a,n,p,rez;

    f>>a>>n;

    p=phi(n)-1;

    rez=1;

    while(p)

    {

        if(p&1) rez=rez*a%n;

        a=a*a%n;

        p/=2;

    }

    g<<rez;

}
