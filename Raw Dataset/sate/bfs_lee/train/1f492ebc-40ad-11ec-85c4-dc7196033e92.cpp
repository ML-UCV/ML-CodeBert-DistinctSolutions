#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream fi("sate.in");
ofstream fo("sate.out");
const int nmax=30005;
int n,m,i,SEEN[nmax],a,b,x,y,c,PATH[nmax];
vector <pair <int,int> > V[nmax];
queue <int> Q;
int main()
{
    fi>>n>>m>>a>>b;
    for(i=1;i<=m;i++)
    {
        fi>>x>>y>>c;
        V[x].push_back(make_pair(y,c));
        V[y].push_back(make_pair(x,-c));
        if(x==a)
            PATH[y]=c;
    }
    Q.push(a);
    SEEN[a]=1;
    PATH[a]=0;
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for(i=0;i<V[x].size();i++)
        {
            y=V[x][i].first;
            if(!SEEN[y])
            {
                Q.push(y);
                SEEN[y]=1;
                PATH[y]=PATH[x]+V[x][i].second;
            }
            if(y==b)
            {
                if(b>a)
                    fo<<PATH[y]<<"\n";
                else
                    fo<<-PATH[y]<<"\n";
                fi.close();
                fo.close();
                return 0;
            }
        }
    }
    fi.close();
    fo.close();
    return 0;
}
