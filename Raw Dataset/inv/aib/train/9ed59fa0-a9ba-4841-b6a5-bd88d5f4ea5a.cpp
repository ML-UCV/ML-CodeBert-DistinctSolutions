#include <fstream>
#include <algorithm>


using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int n,i,x,aib[100005],v[100005],a[100005],b[100005];

long long s;

int ub(int x)

{

    return x & (-x);

}

void update(int x)

{

    for(int i=x;i<=n;i+=ub(i))

        aib[i]++;

}

int query(int x)

{

    long long s=0;

    for(int i=x;i>=1;i-=ub(i))

        s+=aib[i];

    return s;

}

void normalizare()

{

    for(int i=1;i<=n;i++)

        b[i]=a[i];

    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)

    {

        int st=1,p=0;

        int dr=n;

        int x=a[i];

        while(st<=dr)

        {

            int mij=(st+dr)/2;

            if(x<=b[mij])

            {

                p=mij;

                dr=mij-1;

            }

            else st=mij+1;

        }

        v[i]=p;

    }

}

int main()

{

    f>>n;

    for(i=1;i<=n;i++)

        f>>a[i];

    normalizare();

    for(i=n;i>=1;i--)

    {

        x=v[i];

        update(x);

        s+=query(x-1);

    }

    g<<s%9917<<'\n';

    return 0;

}
