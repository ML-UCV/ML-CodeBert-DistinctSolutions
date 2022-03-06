#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("apm.in");

ofstream cout("apm.out");

struct chestii{

    int x,y,c;

};

int sef[200002];

bool cmp(chestii a,chestii b)

{

    if(a.c<b.c)

        return true;

    return false;

}

int sefsuprem(int x)

{

    if(sef[x]==x)

        return x;

    else

        return sef[x]=sefsuprem(sef[x]);

}

void unire(int a,int b)

{

    int sef1,sef2;

    sef1=sefsuprem(a);

    sef2=sefsuprem(b);

    sef[sef1]=sef2;

}

chestii a[400002],rez[200002];

int main()

{

    int n,m,i,n1=0,nrsol=0;

    cin>>n>>m;

    for(i=1;i<=n;i++)

        sef[i]=i;

    for(i=1;i<=m;i++)

        cin>>a[i].x>>a[i].y>>a[i].c;

    sort(a+1,a+m+1,cmp);

    i=1;

    while(n1!=n-1 && i<=m)

    {

        if(sefsuprem(a[i].x)!=sefsuprem(a[i].y))

        {

            unire(a[i].x,a[i].y);

            n1++;

            rez[n1]=a[i];

            nrsol+=a[i].c;

        }

        i++;

    }

    cout<<nrsol<<'\n';

    cout<<n1<<'\n';

    for(i=1;i<=n1;i++)

        cout<<rez[i].x<<" "<<rez[i].y<<'\n';

    return 0;

}
