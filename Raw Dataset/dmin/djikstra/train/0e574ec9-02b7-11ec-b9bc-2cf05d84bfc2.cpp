#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

vector<pair<int,double> > g[1510];

int n,m;

double best[1510];

int dp[1510];

struct Compare{

    bool operator()(pair<int,double> a,pair<int,double> b){

        return a.second>b.second;

    }

};

priority_queue<pair<int,double>,vector<pair<int,double> >,Compare> Heap;

void Dijkstra(){

    int i,node;

    double cost;

    for(i=2;i<=n;i++)

        best[i]=1000000000;

    best[1]=0;

    dp[1]=1;

    Heap.push(make_pair(1,0));

    while(!Heap.empty()){

        node=Heap.top().first;

        cost=Heap.top().second;

        Heap.pop();

        for(i=0;i<g[node].size();i++){

            if(best[g[node][i].first]-1e-8>=cost+g[node][i].second){

                best[g[node][i].first]=cost+g[node][i].second;

                dp[g[node][i].first]=dp[node];

                Heap.push(make_pair(g[node][i].first,best[g[node][i].first]));

            }

            else

                if(fabs(best[g[node][i].first]-cost-g[node][i].second)<=1e-8){

                    dp[g[node][i].first]+=dp[node];

                    if(dp[g[node][i].first]>=104659)

                        dp[g[node][i].first]-=104659;

                }

        }

    }

}

int main(){

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    int i,a,b;

    double c;

    scanf("%d%d",&n,&m);

    for(i=1;i<=m;i++){

        scanf("%d%d%lf",&a,&b,&c);

        g[a].push_back(make_pair(b,log10(c)));

        g[b].push_back(make_pair(a,log10(c)));

    }

    Dijkstra();

    for(i=2;i<=n;i++)

        printf("%d ",dp[i]);

    return 0;

}
