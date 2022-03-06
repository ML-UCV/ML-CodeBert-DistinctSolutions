#include <fstream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

#define lim 30010
#define maxb 8192

int n,m,x,y,a,b,c;
int dist[lim];
bool viz[lim];
struct loc{int sat,d;};
vector <loc> G[lim];

char buff[maxb];
int pos=0;

int get_int()
{
    int nr=0;
    while(buff[pos]<'0' || buff[pos]>'9')
     if(++pos==maxb) fin.read(buff,maxb),pos=0;

    while(buff[pos]>='0' && buff[pos]<='9')
    {
        nr=nr*10+buff[pos]-'0';
        if(++pos==maxb) fin.read(buff,maxb),pos=0;
    }
    return nr;
}


void bfs(int nod)
{
    queue <int> q;
    q.push(nod);
    dist[nod]=0;

    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(auto it:G[nod])
        {
            if(!viz[it.sat])
            {
                viz[it.sat]=true;
                if(it.sat>nod)
                {
                    dist[it.sat]=dist[nod]+it.d;
                    q.push(it.sat);
                }
                if(it.sat<nod)
                {
                    dist[it.sat]=dist[nod]-it.d;
                    q.push(it.sat);
                }

                if(it.sat==y)
                {
                    fout<<dist[y];
                    fout.close();
                    return;
                }
            }
        }
    }

}


int main()
{
    n=get_int();
    m=get_int();
    x=get_int();
    y=get_int();
    for(int i=1; i<=m; i++)
    {
        a=get_int();
        b=get_int();
        c=get_int();
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    bfs(x);

    fin.close();
    fout.close();
    return 0;
}
