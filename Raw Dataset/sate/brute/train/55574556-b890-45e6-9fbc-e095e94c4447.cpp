#include <bits/stdc++.h>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
vector < pair < int, int > > graf[30005];
bool vizitat[30005];
int n,m,X,y,ok=1;
long int s;
void citire()
{
    fin>>n>>m>>X>>y;
    for(int i=1; i<=m; i++)
    {
        int a,b,d;
        fin>>a>>b>>d;
        graf[a].push_back(make_pair(b,d));
        graf[b].push_back(make_pair(a,-d));
    }
}
void drum(int x,int s)
{

    if(x==y)
    {
        fout<<s;
        return;
        ok=0;
    }
    else
    {
        for(unsigned int i=0; i<graf[x].size(); i++)
        {
            if(vizitat[graf[x][i].first]==0)
            {
                vizitat[graf[x][i].first]=1;
                drum(graf[x][i].first,s+graf[x][i].second);
                if(ok==0)
                    return;
            }
        }
    }
}
int main()
{
    citire();
    drum(X,0);
}
