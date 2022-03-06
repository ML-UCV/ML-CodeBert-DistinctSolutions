#include <fstream>


using namespace std;

ifstream cin ("schi.in");

ofstream cout ("schi.out");

int n,aib[30005],v[30005];

int len(int x)

{

    return (x-(x&(x-1)));

}

int update(int pz,int val)

{

    while (pz<=n)

    {

        aib[pz]+=val;

        pz+=len(pz);

    }

}

int sol[30005];

int main()

{

    int i,x,pas,rz;

    cin>>n;

    for (i=1;i<=n;i++)

    {

        cin>>v[i];

        update(i,1);

    }

    for (i=n;i>=1;i--)

    {

        x=v[i];

        pas=1<<20;rz=0;

        while (pas)

        {

            if (rz+pas<=n&&aib[rz+pas]<x)

            {

                rz+=pas;

                x-=aib[rz];

            }

            pas/=2;

        }

        sol[++rz]=i;

        update(rz,-1);

    }

    for (i=1;i<=n;i++)

    {

        cout<<sol[i]<<'\n';

    }

    return 0;

}
