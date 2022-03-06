#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

ifstream cin("cmap.in");

ofstream cout("cmap.out");

typedef long double ld;

const int lim=1e5+3;

struct point

{

    ld x,y;

}v[lim],k[lim];

ld dist(point a,point b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

ld modul(ld a)

{

    if(a<0) return -a;

    return a;

}

vector<point> vec;

ld rez(int l,int r)

{

    if(r-l==1)

    {

        if(v[r].x>v[l].x)

            k[l]=v[l],k[r]=v[r];

        else k[l]=v[r],k[r]=v[l];

        return dist(v[l],v[r]);

    }

    if(r-l==2)

    {

        k[l]=v[l];

        k[l+1]=v[l+1];

        k[r]=v[r];

        if(k[l+1].x<=k[l].x and k[l+1].x<=k[r].x)

            swap(k[l],k[l+1]);

        else if(k[r].x<=k[l].x and k[r].x<=k[l+1].x)

            swap(k[l],k[r]);

        if(k[l+1].x>k[r].x)

            swap(k[l+1],k[r]);

        return min(dist(v[l],v[l+1]),min(dist(v[l+1],v[r]),dist(v[l],v[r])));

    }

    int sep=(l+r)/2,nr;

    ld d=v[sep+1].y;

    ld ans=min(rez(l,sep),rez(sep+1,r));

    vec.clear();

    int ind1=l;

    int ind2=sep+1;

    int poz=l;

    while(ind1<=sep and ind2<=r)

    {

        if(k[ind1].x<k[ind2].x)

            v[poz++]=k[ind1++];

        else v[poz++]=k[ind2++];

    }

    while(ind1<=sep)

        v[poz++]=k[ind1++];

    while(ind2<=r)

        v[poz++]=k[ind2++];

    for(int i=l;i<=r;++i)

    {

        k[i]=v[i];

        if(modul(v[i].y-d)<=ans)

            vec.push_back(v[i]);

    }

    nr=vec.size();

    for(int i=0;i<nr-1;++i)

    for(int j=i+1;j<min(nr,i+8);++j)

        ans=min(ans,dist(vec[i],vec[j]));

    return ans;

}

bool dupay(point a,point b)

{

    if(a.y==b.y)

        return a.x<b.x;

    return a.y<b.y;

}

int main()

{

    int n;

    cin>>n;

    for(int i=1;i<=n;++i)

        cin>>v[i].x>>v[i].y;

    sort(v+1,v+n+1,dupay);

    cout<<fixed<<setprecision(6)<<rez(1,n)<<'\n';

    return 0;

}
