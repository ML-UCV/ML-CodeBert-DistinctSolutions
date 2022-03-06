#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;





typedef long long i64;

const int N=100001;

const i64 I=4e18;

vector<pair<i64,i64>> v,x,y;

int n,i;

i64 D(pair<i64,i64> &a,pair<i64,i64> &b)

{

    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);

}

i64 G(int s,int d)

{

    if(s>=d-1)

        return I;

    if(d-s==2)

    {

        if(y[s]>y[s+1])

            swap(y[s],y[s+1]);

        return D(x[s],x[s+1]);

    }

    int m=(s+d)/2,e=0,i,j;

    i64 b=min(G(s,m),G(m,d));

    sort(y.begin()+s,y.begin()+d);

    for(i=s; i<d; i++)

        if(abs(y[i].second-x[m].first)<=b)

            v[e++]=y[i];

    for(i=0; i<e-1; i++)

        for(j=i+1; j<e&&j-i<8; j++)

            b=min(b,D(v[i],v[j]));

    return b;

}

int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);



    scanf("%d",&n);



    x.resize(n);

    y.resize(n);

    v.resize(N);



    for(i=0; i<n; i++)

        scanf("%lld%lld",&x[i].first,&x[i].second);



    sort(x.begin(),x.end());



    for(i=0; i<n; i++)

        y[i]=make_pair(x[i].second,x[i].first);



    printf("%.6lf",sqrt(G(0,n)));

}
