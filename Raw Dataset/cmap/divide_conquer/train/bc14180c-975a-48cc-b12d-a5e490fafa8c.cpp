#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>




using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

int n;

pair<long long,long long> v[100010],w[100010],f[100010];

long long dist(pair<long long,long long> x, pair<long long,long long> y){

    return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);

}

void intercls(int st, int mid, int dr){

    int i=st;

    int j=mid+1;

    int k=0;

    while(i<=mid&&j<=dr)

        if(v[i].second<v[j].second)

            w[++k]=v[i++];

        else

            w[++k]=v[j++];

    for(;i<=mid;i++)

        w[++k]=v[i];

    for(;j<=dr;j++)

        w[++k]=v[j];

    for(k=1, i=st;i<=dr;i++, k++)

        v[i]=w[k];

}

long long rec(int st, int dr){

    long long r=0;

    if(dr-st==1){

        r=dist(v[st],v[dr]);

        intercls(st,st,dr);

        return r;

    }

    if(dr-st==2){

        r=min(dist(v[st],v[st+1]),min(dist(v[st+1],v[dr]),dist(v[st],v[dr])));

        intercls(st,st,st+1);

        intercls(st,st+1,dr);

        return r;

    }

    int mid=(st+dr)/2;

    long long sol1=rec(st,mid);

    long long sol2=rec(mid+1,dr);

    intercls(st,mid,dr);

    long long minim=min(sol1,sol2);

    int m=0;

    for(int i=st;i<=dr;i++)

        if(abs(v[mid].first-v[i].first)<=minim)

          f[++m]=v[i];

    for(int i=1;i<m;i++)

        for(int j=i+1;j<=m&&j<=i+7;j++)

            minim=min(minim,dist(f[i],f[j]));



    return minim;



}

int main(){

    fin>>n;

    for(int i=1;i<=n;i++)

        fin>>v[i].first>>v[i].second;

    sort(v+1,v+n+1);

    fout<<setprecision(6)<<fixed<<(double)sqrt(rec(1,n));

    return 0;

}
