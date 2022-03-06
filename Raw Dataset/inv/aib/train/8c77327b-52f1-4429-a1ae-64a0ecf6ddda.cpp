#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int v[150001],v2[150001],aib[150001],n;

unordered_map<int,int> mymap;

ifstream in ("inv.in");

ofstream out ("inv.out");

void update(int value)

{

    for(int i=value;i<=n;i+=(i&(-i)))

        aib[i]++;

}

int query (int nod)

{

    int sum=0;

    for (int i=nod;i;i-=(i&(-i)))

        sum+=aib[i];

    return sum;

}

int main()

{

    in>>n;

    for (int i=1;i<=n;++i)

        in>>v[i],v2[i]=v[i];

    sort(v+1,v+n+1);

    int sum1=0,p=0;

    v[0]=-1;

    for (int i=1;i<=n;++i)

    {

        if (v[i]!=v[i-1])

            p++;

        mymap[v[i]]=p;

    }

    for (int i=n;i>=1;--i)

    {

        sum1+=query(mymap[v2[i]]-1);

        sum1%=9917;

        update(mymap[v2[i]]);

    }

    out<<sum1;

    return 0;

}
