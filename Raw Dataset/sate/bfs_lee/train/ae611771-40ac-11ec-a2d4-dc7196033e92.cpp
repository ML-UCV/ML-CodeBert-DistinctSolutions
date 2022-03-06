#include<bits/stdc++.h>
using namespace std;

int sol[30001], vizitat[30001];
vector <pair<int,int>> vecin[30001];
queue <int> q;

void bfs(int k)
{

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto i : vecin[x])
        {
            if(!vizitat[i.first])
            {
                q.push(i.first);
                vizitat[i.first]=1;
                if(x > i.first)
                    sol[i.first]=sol[x]-i.second;
                else
                    sol[i.first]=sol[x]+i.second;

            }
        }
    }
}

int main()
{ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,x,y,d,i,j;
    fin>>n>>m>>x>>y;
    for(int k=1;k<=m;k++)
    {
        fin>>i>>j>>d;
        vecin[i].push_back({j, d});
        vecin[j].push_back({i, d});
    }

    q.push(x);
    vizitat[x]=1;
    bfs(x);
    fout<<sol[y];

    return 0;
}
