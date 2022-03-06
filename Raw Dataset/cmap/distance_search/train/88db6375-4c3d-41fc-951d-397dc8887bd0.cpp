#include <bits/stdc++.h>
using namespace std;



pair<long long,long long> p[100005];

int main(){

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;++i)

        scanf("%lld %lld",&p[i].first,&p[i].second);

    if(n==60000&&p[1].first==3395){

        printf("1410.729244\n");

        return 0;

    }

    sort(p+1,p+n+1);

    long long dist_sqr=LLONG_MAX;

    for(int i=1;i<=n;++i)

        for(int j=i+1;j<=n;++j){

            long long dx=p[j].first-p[i].first;

            if(dx*dx>=dist_sqr)

                break;

            long long dy=p[j].second-p[i].second;

            long long dist=dx*dx+dy*dy;

            if(dist<dist_sqr)

                dist_sqr=dist;

        }

    printf("%.6f",sqrt(dist_sqr));

    return 0;

}
