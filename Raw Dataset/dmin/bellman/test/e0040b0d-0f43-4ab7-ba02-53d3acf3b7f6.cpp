#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cmath>
using namespace std;



vector<pair<double,int> > G[1605];

vector<int> daddy[1605];

queue<int> Q;

bitset<1605> inQ;



int N,M;

double dist[1605];

int DP[1605];



void read()

{

    int a,b,c;

    scanf("%d%d",&N,&M);

    for(int i = 1; i <= M; ++i){

        scanf("%d%d%d",&a,&b,&c);

        G[a].push_back(make_pair(log2((double)c),b));

        G[b].push_back(make_pair(log2((double)c),a));

    }

}



void bellman_ford()

{

    Q.push(1);

    for(int i = 2; i <= N; ++i) dist[i] = 0x3f3f3f3f;

    dist[1] = 0;

    int k;

    while(!Q.empty())

    {

        k = Q.front();Q.pop();inQ[k] = 0;

        for(vector<pair<double,int> >::iterator it = G[k].begin(); it != G[k].end(); ++it)

        {

            if(dist[it->second] > dist[k] + it->first + 0.00000001)

            {

                dist[it->second] = dist[k] + it->first;

                daddy[it->second].clear();

                daddy[it->second].push_back(k);

                inQ[it->second] = 1;

                Q.push(it->second);

                continue;

            }

            if(dist[it->second] - dist[k] - it->first + 0.00000001 >= 0 &&

               dist[it->second] - dist[k] - it->first <= 0.0001 )

                daddy[it->second].push_back(k);

        }

    }

}



int dynamic(int k)

{

    if(DP[k])return DP[k];

    int sum = 0;

    for(vector<int>::iterator it = daddy[k].begin(); it != daddy[k].end(); ++it)

        sum = (sum%104659 + dynamic(*it)%104659) % 104659;

    DP[k] = sum;

    return DP[k] % 104659;

}

void prepare()

{

    for(int i = 1; i <= N; ++i)

    {

        vector<int>::iterator it = unique(daddy[i].begin(),daddy[i].end());

        daddy[i].resize(distance(daddy[i].begin(),it));

    }

}





int main()

{

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);



    read();

    bellman_ford();

    DP[1] = 1;

    prepare();

    for(int i = 2; i <= N; ++i)

        printf("%d ",dynamic(i));



    return 0;

}
