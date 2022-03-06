#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct dublu
{
    int x,dist;
};

vector<dublu>a[30005];
int n, m, s,X,Y;
int dp[30005];

ifstream in("sate.in");
ofstream out("sate.out");


void bfs(int x1)
{
    queue <int> q;
    dp[x1]=0;
    q.push(x1);
    while(!q.empty())
    {
        //cout<<111<<"\n";
        int x;
        x=q.front();
        q.pop();
       // cout<<x.x<<" ";
        for(auto y : a[x])
        {
            //  cout<<y.x<<" \n";
            if( dp[y.x]>dp[x]+y.dist)
            {
                dp[y.x]=dp[x]+y.dist;
                q.push(y.x);
            }
        }
        /*
        for(int i=1; i<=n; i++)
        {
            out<<dp[i]<<" ";
        }
        out<<"\n";
*/
    }

}

int main()
{
    dublu start;
    in>>n>>m>>X>>Y;
    for(int i=0; i<m; i++)
    {
        int x,y,d;
        in>>x>>y>>d;

        dublu aux;
        aux.x=y;
        aux.dist=d;
        a[x].push_back(aux);

        aux.x=x;
        aux.dist=-d;
        a[y].push_back(aux);

    }
    for(int i=1; i<=n; i++)
    {
        dp[i]=10000000000;
    }
    bfs(X);

    out<<dp[Y];


    return 0;
}
