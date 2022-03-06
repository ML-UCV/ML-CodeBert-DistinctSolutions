#include <fstream>
#include <vector>
#include <queue>
#define Nmax 30001

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,in,sf,dist[Nmax];
bool ap[Nmax];
vector <pair<int,int> > G[Nmax];
queue<int> q;
char s[50];
int BFS(int start)
{
    q.push(start);
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for (auto i:G[x])
        {
            if (ap[i.first]==0)
            {
                ap[i.first]=1;
                dist[i.first]=dist[x]+i.second;
                q.push(i.first);
                if (i.first==sf){
                    return dist[i.first];
                }
            }
        }
    }
}
int main()
{
    int a,b,c;
    fin>>n>>m>>in>>sf;
    fin.get();
    for (;m--;)
    {
         fin.getline(s, 30);

        int i = 0, x = 0;
        while ( s[i] != ' ' )
            x = x*10 + s[i++] - '0';

        i++;
        int y = 0;
        while ( s[i] != ' ' )
            y = y*10 + s[i++] - '0';

        i++;
        int cost = 0;
        while ( isdigit(s[i]) )
            cost = cost*10 + s[i++] - '0';
        G[x].push_back({y, cost});
        G[y].push_back({x, -cost});
    }
    fout<<BFS(in);
    return 0;
}
