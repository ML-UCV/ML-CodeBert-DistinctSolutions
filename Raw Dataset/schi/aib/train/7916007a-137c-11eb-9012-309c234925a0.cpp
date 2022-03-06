#include <fstream>


using namespace std;

ifstream f("schi.in");

ofstream g("schi.out");

int n,i,nr,mij,st,dr,x,v[30005],loc[30005],aib[30005],p;

int ub(int x)

{

    return (x&(-x));

}

int sum(int x)

{

    int s=0;

    for(int i=x;i>=1;i-=ub(i))

        s+=aib[i];

    return s;

}

void Add(int x, int val)

{

    for(int i=x;i<=n;i+=ub(i))

        aib[i]+=val;

}

int main()

{

    f>>n;

    for(i=1;i<=n;i++)

        f>>v[i];

    for(i=1;i<=n;i++)

        Add(i,1);

    for(i=n;i>=1;i--)

    {

        x=v[i];

        st=1;

        dr=n;

        p=0;

        while(st<=dr)

        {

            mij=(st+dr)/2;

            nr=sum(mij);

            if(x>nr)

                st=mij+1;

            else

            {

                p=mij;

                dr=mij-1;

            }

        }

        loc[p]=i;

        Add(p,-1);

    }

    for(i=1;i<=n;i++)

        g<<loc[i]<<'\n';

    return 0;

}
