#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>






using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



int n;

pair<int,int> P[100001];

vector<pair<int,int> > v;



bool comp(pair<int,int> a,pair<int,int> b)

{

    return a.first<b.first;

}



double dist(pair<int,int> x, pair<int,int> y)

{

    return sqrt((long double)(x.first - y.first) * (x.first - y.first) + (long double)(x.second - y.second) * (x.second - y.second));

}



int _abs(int x)

{

    if (x<0)

        return -x;

    return x;

}



bool comp2(pair<int,int> a,pair<int,int> b)

{

    return a.second<b.second;

}



double ctb(int st,int dr)

{

    int mid = (st+dr)/2,med;

    double a,x;

    if (st==dr)

        return 1e9;

    if (st+1==dr)

        return dist(P[st],P[dr]);

    a = min(ctb(st,mid),ctb(mid+1,dr));



    med = P[mid].first;

    for (int i=st;i<=dr;i++)

    {

        if (_abs(med-P[i].first)<a)

            v.push_back(P[i]);

    }

    sort(v.begin(),v.end(),comp2);



    for (int i=0;i<v.size();i++)

    {

        for (int j=i+1;j<min(i+4,(int)v.size());j++)

        {

            x = dist(v[i],v[j]);

            if (x<a)

                a = x;

        }

    }



    v.clear();

    return a;

}



int main()

{

    f>>n;

    for (int i=1;i<=n;i++)

    {

        f>>P[i].first>>P[i].second;

    }



    sort(P+1,P+n+1,comp);



    g<<fixed<<setprecision(8);

    g<<ctb(1,n);

    return 0;

}
