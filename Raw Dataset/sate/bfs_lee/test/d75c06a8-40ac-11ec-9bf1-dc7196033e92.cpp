#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
int n,m,x,y,a,b,c,dist[30005],l,ind;
char c1[35];
vector <pair<int,int> > v[30005];
int rez()
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int x1=q.front();
        q.pop();
        for(auto i:v[x1])
        {
            if(dist[i.first]==0)
            {
                dist[i.first]=dist[x1]+i.second;
                q.push(i.first);
                if(i.first==y)return dist[y];
            }
        }
    }
}
int main()
{
    in>>n>>m>>x>>y;
    in.get();
    for(int i=1;i<=m;++i)
    {
        in.getline(c1,30);
        a=0,b=0,c=0;
        ind=0;
        while(isdigit(c1[ind]))
        {
            a=a*10+c1[ind++]-'0';
        }
        ind++;
        while(isdigit(c1[ind]))
        {
            b=b*10+c1[ind++]-'0';
        }
        ind++;
        while(isdigit(c1[ind]))
        {
            c=c*10+c1[ind++]-'0';
        }
        v[a].push_back({b,c});
        v[b].push_back({a,-c});
    }
    out<<rez();
    return 0;
}
