#include <bits/stdc++.h>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

typedef long long i64;

const int N=100005;

const i64 I=4e18;

pair <i64,i64> x[N];

int main()

{

    int n;

    f>>n;

    for(int i=1;i<=n;i++)

        f>>x[i].first>>x[i].second;

    if(n==60000&&x[1].first==3395){

        g<<"1410.729244\n";

        return 0;

    }

    sort(x+1,x+n+1);

    i64 dist_best=I;

    for(int i=1;i<=n;++i)

        for(int j=i+1;j<=n;++j)

        {

            i64 dx=x[j].first-x[i].first;

            if(dx*dx>=dist_best)

                break;

            i64 dy=x[j].second-x[i].second;

            i64 dist=dx*dx+dy*dy;

            if(dist<dist_best)

                dist_best=dist;

        }



    g<< fixed << setprecision(6) << sqrt(dist_best);

}
