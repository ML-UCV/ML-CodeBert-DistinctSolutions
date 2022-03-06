# include <fstream>
# include <algorithm>
using namespace std;

int val,poz;

struct inv

{

    int val,poz;

};

inv v[100001];

int a[100001],i,x,n;

long long r;

bool cmp(inv a, inv b)

{

    if (a.val==b.val) return(a.poz<b.poz);

    else return (a.val<b.val);

}

void update(int poz)

{

    int i;

    for(i=poz; i<=n; i+=(i&(-i)))

        a[i]++;

}

int query(int poz)

{

    int i,s=0;

    for(i=poz-1; i>=1; i-=(i&(-i)))

        s+=a[i];

    return s;

}

int main()

{

    ifstream f("inv.in");

    ofstream g("inv.out");

    f>>n;

    r=n-1;

    r*=n;

    r/=2;

    for(i=1; i<=n; ++i)

    {

        f>>v[i].val;

        v[i].poz=i;

    }

    sort(v+1,v+n+1,cmp);

    for(i=1; i<=n; ++i)

    {

        r=r-query(v[i].poz);

        update(v[i].poz);

    }

    r%=9917;

    g<< r;

    f.close();

    g.close();

    return 0;

}
