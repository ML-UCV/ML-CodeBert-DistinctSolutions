#include<bits/stdc++.h>


using namespace std;

long long dist(int a,int b,int c,int d)

{

    return (1LL*(c-a))*(1LL*(c-a))+(1LL*(d-b))*(1LL*(d-b));

}

int n,a,b;

vector<pair<int,int> > v,x,y;

inline long long DivImp(int st,int dr,vector<pair<int,int> > &x,vector<pair<int,int> > &y)

{

    if(st>=dr-1)

    {

        return LLONG_MAX;

    }

        else

    if(dr-st==2)

    {

        if(y[st]>y[st+1]) swap(y[st],y[st+1]);

        return dist(x[st].first,x[st].second,x[st+1].first,x[st+1].second);

    }

    int mid=(st+dr)>>1;

    long long best=LLONG_MAX;

    best=min(DivImp(st,mid,x,y),DivImp(mid,dr,x,y));

    merge(y.begin()+st,y.begin()+mid,y.begin()+mid,y.begin()+dr,v.begin());

    copy(v.begin(),v.begin()+(dr-st),y.begin()+st);

    int sz=0;



    for(int i=st;i<dr;i++)

    {

        if(abs(y[i].second-x[mid].first)<=best)

            v[sz++]=y[i];

    }

    for(int i=0;i<sz;i++)

    {

        for(int j=i+1;j<sz && (j-i)<=7;j++)

            best=min(best,dist(v[i].first,v[i].second,v[j].first,v[j].second));

    }

    return best;

}

int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++)

    {

        scanf("%d%d",&a,&b);

        x.push_back(make_pair(a,b));

    }

    sort(x.begin(),x.end());

    for(int i=0;i<n;i++)

    {

        y.push_back(make_pair(x[i].second,x[i].first));

    }

    v.resize(n);



    printf("%.6lf\n",sqrt((double)DivImp(0,n,x,y)));

    return 0;

}
