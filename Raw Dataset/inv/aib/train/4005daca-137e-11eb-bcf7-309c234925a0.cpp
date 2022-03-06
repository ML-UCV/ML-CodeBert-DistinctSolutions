#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int t[100001],aib[300001];

int k,n,sol,a,b,poz,nr,MOD=9917;

struct norm

{

    int poz,val;

}v[100001];

int cmp(norm a, norm b)

{

    if(a.val==b.val)

        return a.poz<b.poz;

    return a.val<b.val;

}

void update(int val)

{

    while(val<=k)

    {

        aib[val]++;

        if(aib[val]==MOD)

            aib[val]=0;

        val+=(val&(-val));

    }

}

int query(int x)

{

    int s=0;

    while(x>0)

    {

        s=(s+aib[x])%MOD;

        x=(x-(x&(-x)));

    }

    return s;

}

int main()

{

    fin>>n;

    for(int i=1;i<=n;i++)

    {

        fin>>v[i].val;

        v[i].poz=i;

    }

    sort(v+1,v+n+1,cmp);

    for(int i=1;i<=n;i++)

    {

        if(v[i].val!=v[i-1].val)

            k++;

        t[v[i].poz]=k;

    }



    for(int i=1;i<=n;i++)

    {

        int val=query(k)-query(t[i]);

        if(val<0)

            val+=MOD;

        sol=(sol+val)%MOD;

        update(t[i]);

    }

    fout<<sol;

    return 0;

}
