#include<fstream>
#include<vector>
#include<queue>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
int n,m,x,y,b[30005],c[30005];
vector<pair<int,int> >a[30005];
queue<int >q;
void ve()
{
    int nod;
    q.push(x);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        if(nod==y)
            return;
        c[nod]=1;
        for(int i=0;i<a[nod].size();i++)
            if(c[a[nod][i].first]==0)
            {
                if(nod>a[nod][i].first)
                    b[a[nod][i].first]=b[nod]-a[nod][i].second;
                else
                    b[a[nod][i].first]=b[nod]+a[nod][i].second;
                q.push(a[nod][i].first);
            }
    }

}
int main()
{
    fin>>n>>m>>x>>y;
    for(int h=1;h<=m;h++)
    {
        int i,j,d;
        fin>>i>>j>>d;
        a[i].push_back(make_pair(j,d));
        a[j].push_back(make_pair(i,d));
    }
    if(y<x)
    {
        int aux=y;
        y=x;
        x=aux;
    }
    ve();
    fout<<b[y];
}
