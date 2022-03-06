#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n,m,viz[30003],x,y,dist[30003],distanta;
vector<pair<int,int> >v[30003];
queue<int>coada;

void bfs(int nod)
{
    coada.push(nod);
    viz[nod]=1;
    int ok=1;
    while(!coada.empty() && ok)
    {
        int x=coada.front();
        coada.pop();
        for(vector<pair<int,int> > :: iterator it=v[x].begin();it!=v[x].end();it++)
        {
            if(viz[it->first]==0)
            {
                dist[it->first]=dist[x]+it->second;
                viz[it->first]=1;
                coada.push(it->first);
            }
            if(it->first==y)
                {distanta=dist[y];
                ok=0;}
        }
    }
}

int main()
{
    fin>>n>>m>>x>>y;
    int x1,y1,d1;
    char sir[20];
    fin.get();
    for(int i=1;i<=m;i++)
    {
        fin.getline(sir,20);
        int cnt=0;
        for(int j=0;sir[j];j++)
        {
            if(isdigit(sir[j]))

            {
                if(cnt==0)
                    {
                        x1=0;
                        while(isdigit(sir[j]))
                        {
                            x1=x1*10+(sir[j]-'0');
                            j++;
                        }
                        j--;
                    }
                else if(cnt==1)
                    {
                        y1=0;
                        while(isdigit(sir[j]))
                        {
                            y1=y1*10+(sir[j]-'0');
                            j++;
                        }
                        j--;
                    }
                else{
                    d1=0;
                        while(isdigit(sir[j]))
                        {
                            d1=d1*10+(sir[j]-'0');
                            j++;
                        }
                        j--;
                }
                cnt++;
            }
        }
        v[x1].push_back(make_pair(y1,d1));
        v[y1].push_back(make_pair(x1,-d1));
    }
    bfs(x);

    fout<<distanta;
}
