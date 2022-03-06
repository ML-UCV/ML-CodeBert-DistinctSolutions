#pragma GCC optimize ("-O2")
#include <fstream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
ifstream cin("sate.in");
ofstream cout("sate.out");
vector<pair<int,int> > vec[30003];
int drum[30003];
bool ok[30003];
queue<int> q;
int citire()
{
    char ch;
    int nr=0;
    cin.get(ch);
    while(ch!=' ' and ch!='\n')
        nr=nr*10+ch-'0',cin.get(ch);
    return nr;
}
int main()
{
    int n,m,x,y,a,b,cost;
    n=citire();
    m=citire();
    x=citire();
    y=citire();
    for(int i=1;i<=m;++i)
    {
        a=citire();
        b=citire();
        cost=citire();
        vec[a].push_back(make_pair(b,cost));
        vec[b].push_back(make_pair(a,-cost));
    }
    q.push(x);
    ok[x]=1;
    while(1)
    {
        int nod=q.front();
        q.pop();
        for(int i=0;i<vec[nod].size();++i)
        if(ok[vec[nod][i].first]==0)
        {
            drum[vec[nod][i].first]=drum[nod]+vec[nod][i].second;
            if(vec[nod][i].first==y)
            {
                cout<<drum[y];
                return 0;
            }
            ok[vec[nod][i].first]=1;
            q.push(vec[nod][i].first);
        }
    }
    return 0;
}
