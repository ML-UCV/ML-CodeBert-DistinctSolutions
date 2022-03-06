#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

long long distan(pair<int,int> ee, pair<int,int> ef)

{

    return (long long)(ee.first-ef.first)*(ee.first-ef.first)+(long long)(ee.second-ef.second)*(ee.second-ef.second);

}

bool sortX(pair<int,int> ee,pair<int,int> ef)

{

    return ee.first<ef.first;

    if(ee.first==ef.first)

        return ee.second<ef.second;

}

bool sortY(pair<int,int> ee,pair<int,int> ef)

{

    return ee.second<ef.second;

}

long long calcmin(vector <pair<int,int> > &v,int l,int r)

{

    if(r-l==1)

        return distan(v[l],v[r]);

    if(r-l==2)

    {

        long long d1,d2,d3;

        d1=distan(v[l],v[r]);

        d2=distan(v[l+1],v[r]);

        d3=distan(v[l],v[l+1]);

        return min(d1,min(d2,d3));

    }

    int m=(l+r)/2;

    long long d,d1,d2,dist;

    d1=calcmin(v,m+1,r);

    d2=calcmin(v,l,m);

    d=min(d1,d2);

    dist=(int)ceil(sqrt(d));

    vector<pair<int,int> > temp;

    for(int i=l; i<=r; i++)

        if(abs(v[i].first-v[m].first)<=dist)

            temp.push_back(v[i]);

    sort(temp.begin(),temp.end(),sortY);

    for(int i=0; i<temp.size(); i++)

        for(int j=i+1; j<=i+7&&j<temp.size(); j++)

            d=min(d,distan(temp[i],temp[j]));

    return d;

}

int main()

{

    int n,x,y;

    vector<pair<int,int> >v;

    f>>n;

    for(int i=0; i<n; i++)

    {

        f>>x>>y;

        v.push_back(make_pair(x,y));

    }

    sort(v.begin(),v.end(),sortX);

    g<<fixed<<setprecision(6)<<sqrt(calcmin(v,0,n-1));

    f.close();

    g.close();

    return 0;

}
