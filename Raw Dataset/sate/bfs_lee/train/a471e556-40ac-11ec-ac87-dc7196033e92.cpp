#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

int n,m,start,sfarsit;
int d[30001];

struct muchie{
    int cost,vecin;
};
vector <muchie> graf[30001];

int main()
{
    fin>>n>>m>>start>>sfarsit;
    for(int i=1; i<=m; i++)
    {
        int x,y,cost;
        fin>>x>>y>>cost;
        muchie a;
        a.vecin=y;
        a.cost=cost;
        graf[x].push_back(a);

        a.vecin=x;
        graf[y].push_back(a);
    }
    d[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int prec=q.front();
        q.pop();
        for(int i=0; i<graf[prec].size(); i++)
        {
            int nod=graf[prec][i].vecin;
            int cost=graf[prec][i].cost;
            if(d[nod]==0)
            {
                //nu am mai fost aici
                if(nod<prec)
                {
                    d[nod]=d[prec]-cost;
                }
                else{
                   d[nod]=d[prec]+cost;
                }
                q.push(nod);
            }
        }
    }

    fout<<d[sfarsit]-d[start];
    return 0;
}
