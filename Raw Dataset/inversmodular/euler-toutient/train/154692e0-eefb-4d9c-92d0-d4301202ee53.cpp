#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long phi(long long n)

{

    long long cur=n;

    for (int i=2;i*i<=n;i++)

    {

        if (n%i==0)

        {

            while (n%i==0)

            {

                n/=i;

            }

            cur=cur*(i-1)/i;

        }

    }

    if (n!=1) cur=cur*(n-1)/n;

    return cur;

}

int main()

{

    long long a,n,x,b,p;

    fin >> a >> n;

    b=phi(n)-1;

    p=1;

    while (b)

    {

        if (b%2) p=(p*a)%n;

        a=(a*a)%n;

        b/=2;

    }

    x=p%n;

    fout << x;

}
