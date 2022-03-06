#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>




using namespace std;

ifstream fin ("cmap.in");

ofstream fout("cmap.out");

int n,i,f[100001];

pair<int,int> v[100001];



int cmp(int a, int b)

{

    return v[a].second<v[b].second;

}



double dist(int i, int j)

{

    long long first=1LL*(v[i].first-v[j].first)*(v[i].first-v[j].first)+1LL*(v[i].second-v[j].second)*(v[i].second-v[j].second);

    return sqrt(first);

}



double solve(int st, int dr)

{

    int i,j,mid;

    double mini=200000000000,aux;

    if(dr-st+1<=3)

    {

        for(i=st;i<dr;i++)

            for(j=i+1;j<=dr;j++)

            {

                aux=dist(i, j);

                if(mini>aux)

                    mini=aux;

            }

        return mini;



    }

    mid=(st+dr)/2;

    mini=min(solve(st, mid), solve(mid+1, dr));

    int k=0;

    for(i=mid;i>=st&&v[mid].first-v[i].first<=mini;i--)

        f[++k]=i;

    for(i=mid+1;i<=dr&&v[i].first-v[mid].first<=mini;i++)

        f[++k]=i;

    sort(f+1, f+k+1, cmp);

    for(i=1;i<=k;i++)

        for(j=i+1;j<=i+7&&j<=k;j++)

        {

            aux=dist(f[i], f[j]);

            if(mini>aux)

                mini=aux;

        }

    return mini;

}



int main(){

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>v[i].first>>v[i].second;

    sort(v+1, v+n+1);

    fout<<setprecision(6)<<fixed<<solve(1, n);

    return 0;

}
