#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector<short> vecini[30005];
vector<int> distanta[30005];
short coada[30005];
string s;
int k,n,m,x,y,a,b,start,d,cost[30005],deparcurs,c;

int next(int &c)
{
    int nr=0,cif;
    while(s[c]!=' ' && c<s.size())
    {
        cif=s[c]-'0';
        nr=nr*10+cif;
        ++c;
    }
    ++c;
    return nr;
}

void bfs(int x)
{
    k=1;
    b=0;
    coada[k]=x;
    while(b<k && cost[y]==0)
    {
        ++b;
        start=coada[b];
        deparcurs=vecini[start].size();
        for(int i=0;i<deparcurs;++i)
        {
            if(cost[vecini[start][i]]==0 && vecini[start][i]!=x)
            {
                cost[vecini[start][i]]=cost[start]+distanta[start][i];
                ++k;
                coada[k]=vecini[start][i];
                if(vecini[start][i]==y) break;
            }
        }
    }
}

int main()
{
    f>>n>>m>>x>>y; getline(f,s);
    for(int i=1;i<=m;++i)
    {
        getline(f,s);
        c=0;
        a=next(c); b=next(c); d=next(c);
        if(b<a) swap(a,b);
        vecini[a].push_back(b); vecini[b].push_back(a);
        distanta[a].push_back(d); distanta[b].push_back(-d);
    }
    bfs(x);
    g<<cost[y];
    return 0;
}
