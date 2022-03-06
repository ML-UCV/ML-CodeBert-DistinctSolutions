#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<cmath>




using namespace std;

fstream fin("cmap.in",ios::in),fout("cmap.out",ios::out);
vector<pair<int,int> > v,aux;
int n;

void citire()
{
    int i,a,b;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a>>b;
        v.push_back({a,b});
    }
}
double dist(int ax,int ay,int bx,int by)
{
    long long c,d;
    c=(ax-bx);c=c*c;
    d=(ay-by);d=d*d;
    c=c+d;
    return sqrt(c);
}
double solv(int st,int dr)
{
    int m=(st+dr)/2,i,j,d;
    double minim=5999999999;

    if(dr-st<=3)
    {
        for(i=st;i<=dr;i++)
        {
            for(j=i+1;j<=dr;j++)
            {
                minim=min(minim,dist(v[i].first,v[i].second,v[j].first,v[j].second));
            }
        }
    }
    else
    {
        minim=min(solv(st,m),solv(m+1,dr));
        aux.clear();
        d=v[m].first;
        for(i=st;i<=dr;i++)
        {
            if(dist(v[i].first,v[i].second,d,v[i].second)<=minim)
            {
                aux.push_back(v[i]);
            }
        }
        for(i=0;i<aux.size();i++)
        {
            for(j=i+1;j<aux.size() && j<i+8;j++)
            {
                minim=min(minim,dist(aux[i].first,aux[i].second,aux[j].first,aux[j].second));
            }
        }

    }
    return minim;
}


int main()
{
    double dis;
    citire();
    sort(v.begin(),v.end());

    dis=solv(0,n-1);

    fout<<fixed<<setprecision(7)<<dis;
}
