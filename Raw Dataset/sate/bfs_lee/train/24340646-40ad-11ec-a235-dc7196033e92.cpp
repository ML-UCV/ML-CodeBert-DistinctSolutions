#include <fstream>
#include <vector>
#include <queue>
using namespace std;
const int N =  30005;
const int M = 100024;
ifstream f("sate.in");
ofstream g("sate.out");

struct depl
{
    int p,d;
};

struct drum
{
    int x,y,l;
};
vector <int> G[N];
queue  <depl> q;
int n,m,x,y;
int tx,ty,dr[N];
bool fr[N];
drum v[M];
depl Move;
int choosedir(int p,int el)
{
    int mx,my;
    mx = v[el].x;
    my = v[el].y;
    if(p == mx)
        return my;
    else
        return mx;
}
int lee()
{
    Move.p = x;
    Move.d = 0;
    q.push(Move);
    fr[x] = 1;
    while(!q.empty())
    {
        depl val = q.front();
        //g<<val.p<<" "<<val.d<<"\n";
        q.pop();
        while(!G[val.p].empty())
        {
            int num = G[val.p].back();

            Move.p = choosedir(val.p,num);
            int semn = (Move.p > val.p) ? 1 : -1;
            Move.d = val.d + semn * v[num].l;
            if(fr[Move.p]==0)
            {
                q.push(Move);
                fr[Move.p]=1;
                if(Move.p == y)
                    return Move.d;
            }
            G[val.p].pop_back();
        }
    }
    return 0 ;
}

int main()
{
    f>>n>>m>>x>>y;
    for(int i = 1; i<= m; i++)
    {
        f>>v[i].x>>v[i].y>>v[i].l;
        G[v[i].x].push_back(i);
        G[v[i].y].push_back(i);
    }
    g<<lee();
    f.close();
    g.close();
    return 0;
}
