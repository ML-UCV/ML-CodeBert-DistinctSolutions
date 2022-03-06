# include <fstream>
# include <algorithm>
# include <iomanip>
# include <cmath>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

pair<int,int> v[100010],d[100010];

int n,i;

long double dist(int x1,int Y1,int x2,int y2){

    return sqrt(1LL*(x1-x2)*(x1-x2)+1LL*(Y1-y2)*(Y1-y2));

}

long double cmap(int st,int dr){

    if(st==dr){

        swap(v[st].first,v[st].second);

        return 1000000000;

    }

    int mij=(st+dr)/2,k=0;

    int X=v[mij].first;

    long double sol=min(cmap(st,mij),cmap(mij+1,dr));

    sort(v+st,v+dr+1);

    for(int i=st;i<=dr;i++)

        if(abs(v[i].second-X)<=sol)

            d[++k]=v[i];

    for(int i=1;i<=k;i++)

        for(int j=i+1;j<=min(i+7,k);j++)

            sol=min(sol,dist(d[i].first,d[i].second,d[j].first,d[j].second));

    return sol;

}

int main () {

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>v[i].first>>v[i].second;

    sort(v+1,v+n+1);

    fout<<setprecision(7)<<fixed<<cmap(1,n);

    return 0;

}
