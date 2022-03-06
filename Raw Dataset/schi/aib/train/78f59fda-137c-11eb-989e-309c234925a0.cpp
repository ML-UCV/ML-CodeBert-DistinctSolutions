#include<fstream>
#include<climits>
using namespace std;

ifstream f("schi.in");

ofstream g("schi.out");

int n,aib[30003],a[30003],sol[30003];

int ub(int x)

{

    return (x&(-x));

}

void add(int poz,int val)

{

    for(int i=poz; i<=n; i+=ub(i))aib[i]+=val;

}

int sum(int poz)

{

    int s=0;

    for(int i=poz; i>=1; i-=ub(i))

        s+=aib[i];

    return s;

}

int cb(int x)

{

    int st=1,dr=n,ans=2e9,mij=0;

    while(st<=dr)

    {

        mij=(st+dr)/2;

        int nr=sum(mij);

        if(nr==x&&mij<ans)

        {

            ans=mij;

        }

        else if(nr<x)st=mij+1;

        else dr=mij-1;

    }

    return ans;

}

int main()

{

    f>>n;

    for(int i=1; i<=n; ++i)aib[i]=ub(i),f>>a[i];

    for(int i=n; i>=1; i--)

    {

        int poz=cb(a[i]);

        add(poz,-1);

        sol[poz]=i;

    }

    for(int i=1; i<=n; ++i)g<<sol[i]<<"\n";



    return 0;

}
