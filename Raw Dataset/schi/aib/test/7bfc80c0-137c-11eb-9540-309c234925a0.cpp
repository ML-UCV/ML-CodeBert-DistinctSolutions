#include<fstream>
using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");

int i,k,x,n,u[30001],w[30001],v[30001],p;

void Add(int k, int x)

{

    int i;

    for (i = k; i <= n; i += ( (i ^ (i - 1)) & i ))

        v[i]+=x;

}

int Compute(int k)

{

    int i, ret=0;

    for (i = k; i > 0; i -= ( (i ^ (i - 1)) & i ))

        ret+=v[i];

    return ret;

}

int cautbin(int st,int dr,int k)

{

    int x,p,mij;

    while(st<=dr)

    {

        mij=(st+dr)/2;

        x=Compute(mij);

        if(x>=u[k])

        {

            p=mij;

            dr=mij-1;

        }

        else

        {

            st=mij+1;

        }

    }

    return p;

}

int main()

{

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>u[i];

        Add(i,1);

    }

    for(i=n;i>=1;i--)

    {

        p=cautbin(1,n,i);

        w[p]=i;

        Add(p,-1);

    }

    for(i=1;i<=n;i++)

        g<<w[i]<<"\n";

}
