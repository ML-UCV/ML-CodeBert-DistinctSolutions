#include <fstream>
#include <vector>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int n,aib[30003],sol[30003],v[30003];

int suma(int poz)

{

    int S=0;

    while (poz>0)

    {

        S+=aib[poz];

        poz-=(poz&(-poz));

    }

    return S;

}

void update(int poz)

{

    while (poz<=n)

    {

        aib[poz]-=1;

        poz+=(poz&(-poz));

    }

}

int cautare (int p,int u,int val)

{

    int min1=30003 +3;

    while (p<=u)

    {

        int m=(p+u)/2;

        int S=suma(m);

        if (S==val && m<min1)

            min1=m;

        if (val<=S)

            u=m-1;

        else

            p=m+1;

    }

    return min1;

}

int main()

{

    int i;

    fin>>n;

    for (i=1;i<=n;i++)

    {

        fin>>v[i];

        aib[i]=(i&(-i));

    }

    for (i=n;i>=1;i--)

    {

        int val=cautare(1,n,v[i]);

        update(val);

        sol[val]=i;

    }

    for (i=1;i<=n;i++)

        fout<<sol[i]<<"\n";

    return 0;

}
