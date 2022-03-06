#include<bits/stdc++.h>




using namespace std;





inline long double getDist(pair<int,int> a,pair<int,int> b)

{

    long double d1=(long double)(a.first-b.first);

    long double d2=(long double)(a.second-b.second);

    long double d=d1*d1+d2*d2;

    d=sqrt((long double)d);

    return d;

}

vector<pair<int,int> > x,v;



inline long double divimp(int st,int dr,vector<pair<int,int> > &y)

{

    if(st>=dr)

    {

        return (long double)(LLONG_MAX);

    }



    if(st==dr-1)

    {

        if(y[st]>y[dr]) swap(y[st],y[dr]);

        return getDist(x[st],x[dr]);

    }



    if(st==(dr-2))

    {

        sort(y.begin()+st,y.begin()+dr+1);

        return min(getDist(x[st],x[st+2]),min(getDist(x[st],x[st+1]),getDist(x[st+1],x[st+2])));

    }



    int mid=(st+dr)>>1;

    long double best;



    best=min(divimp(st,mid-1,y),divimp(mid,dr,y));



    merge(y.begin()+st,y.begin()+mid,y.begin()+mid,y.begin()+dr+1,v.begin());

    copy(v.begin(),v.begin()+(dr-st+1),y.begin()+st);



    int sz=0;



    for(int i=st;i<=dr;i++)

        if(fabs(y[i].second-x[mid].first)<=best) v[++sz]=y[i];



    for(int i=1;i<=sz;i++)

        for(int j=i+1;j<=sz && (j-i)<=10;j++)

            best=min(best,getDist(v[i],v[j]));

    return best;

}

int n;

int a,b;

vector<pair<int,int> > y;



int main()

{

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");



    fin>>n;



    x.push_back({-INT_MAX,-INT_MAX});

    for(int i=1;i<=n;i++)

    {

        fin>>a>>b;



        x.push_back(make_pair(a,b));

    }



    sort(x.begin(),x.end());



    for(int i=0;i<=n;i++)

        y.push_back(make_pair(x[i].second,x[i].first));

    v.resize(n);



    long double sol=divimp(1,n,y);



    fout<<setprecision(7)<<fixed<<sol<<'\n';

    return 0;

}
