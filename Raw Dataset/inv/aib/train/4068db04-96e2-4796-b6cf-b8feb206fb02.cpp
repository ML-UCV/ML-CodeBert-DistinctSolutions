#include <fstream>
#include <algorithm>


using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

long long aib[100005],n;

int bit (int i)

{

    return i^(i&(i-1));

}

void update (int i,int val)

{

    int j;

    for (j=i;j<=n;j+=bit(j))

    {

        aib[j]+=val;

    }

}

long long query (int i)

{

    int j;long long s=0;

    for (j=i;j>=1;j-=bit(j))

    {

        s+=aib[j];

    }

    return s;

}

long long v[100005],v1[100005];

struct wow

{

    long long nr,poz;

}a[100005];

int compare (wow a,wow b)

{

    return a.nr<b.nr||(a.nr==b.nr&&a.poz<b.poz);

}

long long s;

long long i;

int main()

{

    f>>n;

    for (i=1;i<=n;i++)

    {

        f>>v[i];

        a[i].nr=v[i];

        a[i].poz=i;

    }

    sort (a+1,a+n+1,compare);

    for (i=1;i<=n;i++)

    {

        v1[a[i].poz]=i;

    }

    s=(n*(n-1))/2;

    for (i=1;i<=n;i++)

    {

        s-=1LL*query(v1[i]);

        update(v1[i],1);

    }

    g<<s%9917;

    return 0;

}
