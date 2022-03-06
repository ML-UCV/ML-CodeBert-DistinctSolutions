#include <fstream>
#include <queue>
#include <vector>
#include <iostream>
#include <utility>
#include <string>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n,m,X,Y,dist[30001],nr;

bool viz[100001];

string sir;

vector< pair<int,int> >a[30001];

void bfs(int src)
{
    viz[src]=true;
    queue< int >q;
    q.push(src);
    while(!q.empty())
    {

        int nod = q.front();
        q.pop();
        viz[nod]=true;

        for(int i=0;i<a[nod].size();++i)
            if(!viz[a[nod][i].first])
            {
                if(a[nod][i].first>nod)
                    dist[a[nod][i].first]=dist[nod]+a[nod][i].second;
                else
                    dist[a[nod][i].first]=dist[nod]-a[nod][i].second;
                q.push(a[nod][i].first);
                if(a[nod][i].first==Y)return;
            }



    }

}

int main()
{
    f>>n>>m>>X>>Y;
    getline(f,sir);
    for(int k=1;k<=m;++k)
    {
        getline(f, sir);
        int d=0,x=0,y=0;
        for(int j=0;j<sir.size();j++)
        {
            if(sir[j]>='0' && sir[j]<='9')
            {
                nr=0;
                for(int i=j;i<sir.size();i++)
                {
                    if(sir[i]>='0' && sir[i]<='9')
                        nr=nr*10+(sir[i]-'0');
                    else
                    {
                        j=i;
                        break;
                    }
                }
                if(x==0)

                    x=nr;
                else
                    {
                        if(y==0)
                            y=nr;
                        else
                        {
                            d=nr;
                            break;
                        }
                    }
            }
        }

        a[x].push_back(make_pair(y,d));
        a[y].push_back(make_pair(x,d));

    }
    bfs(X);
    g<<dist[Y];
    return 0;
}
