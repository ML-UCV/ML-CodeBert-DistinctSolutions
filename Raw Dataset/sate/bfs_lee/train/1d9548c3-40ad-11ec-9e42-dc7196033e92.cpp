#include <fstream>
#include <vector>
#include <queue>
#define nmax 30002
#define ll long long
#define infinit 30000010
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

int dist[nmax];
int start,x,y,n,m,sfarsit,c;
vector <pair<int,int> > graf[nmax];
queue <pair<int,int> > coada;

void determinare()
{
    for(int i=0;i<graf[start].size();i++)
    {   if(graf[start][i].first<start){
        dist[graf[start][i].first]=(-1)*graf[start][i].second;
        }
        else{
            dist[graf[start][i].first]=graf[start][i].second;
        }
        coada.push(make_pair(graf[start][i].first,dist[graf[start][i].first]));
    }
    while(!coada.empty())
    {
        int nod=coada.front().first;
        int cost=coada.front().second;
        coada.pop();
        for(int i=0;i<graf[nod].size();i++)
        {
            if(dist[graf[nod][i].first]==infinit)
            {
                if(graf[nod][i].first>nod)
                {
                    dist[graf[nod][i].first]=cost+graf[nod][i].second;
                }
                else
                {
                    dist[graf[nod][i].first]=cost-graf[nod][i].second;
                }
                coada.push(make_pair(graf[nod][i].first,dist[graf[nod][i].first]));
            }
        }
    }
}

int main()
{
    fin>>n>>m>>start>>sfarsit;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y>>c;
        pair <int,int> m;
        m.first=y;
        m.second=c;
        graf[x].push_back(m);
        m.first=x;
        graf[y].push_back(m);
    }
    for(int i=1;i<=n;i++)
    {
        dist[i]=infinit;
    }
    dist[start]=0;
    determinare();
    fout<<dist[sfarsit];
    return 0;
}
