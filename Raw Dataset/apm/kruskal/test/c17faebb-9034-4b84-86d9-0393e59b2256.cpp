#include <fstream>
#include <algorithm>


using namespace std;



ifstream cin ("apm.in");

ofstream cout ("apm.out");



struct ura{

    int x,y,c,ok;

};

ura v[400005];

int h[200005];

bool cmp(ura a,ura b)

{

    return a.c<b.c;

}

int d[200005];

int nr,cost;

int stramos(int x)

{

    if (d[x]==x)

        return x;

    int r=stramos(d[x]);

    d[x]=r;

    return r;

}

int unire(int i)

{

    int x=v[i].x,y=v[i].y;

    int d1=stramos(x),d2=stramos(y);

    if (d1!=d2)

    {

        nr++;

        v[i].ok=1;

        cost+=v[i].c;

        if (h[d1]>h[d2])

            d[d2]=d1;

        else

        {

            d[d1]=d2;

            if(h[d1]==h[d2])

                h[d2]++;

        }

    }

}

int main()

{

    int n,m,i;

    cin>>n>>m;

    for (i=1;i<=m;i++)

        cin>>v[i].x>>v[i].y>>v[i].c;

    for (i=1;i<=n;i++)

        d[i]=i;

    sort(v+1,v+m+1,cmp);

    nr=cost=0;

    for(i=1;i<=m;i++)

        unire(i);

    cout<<cost<<'\n'<<nr;

    for(i=1;i<=m;i++)

        if(v[i].ok==1)

            cout<<'\n'<<v[i].x<<" "<<v[i].y;

    return 0;

}
