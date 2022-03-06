#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

struct dist
{
    int s,d;
};

vector<dist> v[30001];
bool visit[30001];

int findDist(int x,int y,int d = 0)
{
    //cout<<x<<'-'<<y<<':'<<d<<'\n';
    if(visit[x]) return 0;
    if(x == y) return d;
    int n = v[x].size();
    visit[x] = true;

    int i,r = 0;
    for(i=0; i<n && r == 0; i++)
    {
        if(v[x][i].s < x) r = findDist(v[x][i].s,y,d - v[x][i].d);
        else r = findDist(v[x][i].s,y,d + v[x][i].d);
    }

    return r;

}

int main()
{
    int n,m,x,y;

    in>>n>>m>>x>>y;

    int i;
    for(i=0; i<m; i++)
    {
        int a,b,l;
        in>>a>>b>>l;

        dist dst;
        dst.d = l;
        dst.s = b;
        v[a].push_back(dst);
        dst.s = a;
        v[b].push_back(dst);
    }

    out<<findDist(x,y);

    return 0;
}
