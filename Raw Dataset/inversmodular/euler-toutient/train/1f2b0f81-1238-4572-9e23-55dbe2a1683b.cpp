#include <fstream>
using namespace std;

ifstream in("inversmodular.in");

ofstream out("inversmodular.out");

long long A,N;

int fi(int n)

{

    int rez=n,d=2;

    while(d*d<=n)

    {

        if(n%d==0)

        {

            while(n%d==0)

                n/=d;

            rez=rez/d*(d-1);

        }

        d++;

    }

    if(n!=1)

        rez=rez/n*(n-1);

    return rez;

}

int lgput(int a,int b)

{

    long long rez=1;

    while(b)

    {

        if(b%2)

            rez=(1LL*rez*a)%N;

        a=(1LL*a*a)%N;

        b/=2;

    }

    return rez;

}

int main()

{

    in>>A>>N;

    out<<lgput(A,fi(N)-1);

    return 0;

}
