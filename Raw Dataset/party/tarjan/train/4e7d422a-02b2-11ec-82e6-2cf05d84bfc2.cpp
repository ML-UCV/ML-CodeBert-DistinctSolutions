#include<fstream>
#include<iostream>
#include<vector>


using namespace std;
ifstream fin("party.in");
ofstream fout("party.out");
int n,m,a,b,type,viz[205],st[205],top,r[205],rez[205],nr;
vector<int>g[205];
void dfs(int nod)
{
    viz[nod]=1;
    for(auto i:g[nod])
        if(!viz[i])
            dfs(i);
    top++;
    st[top]=nod-n;
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>a>>b>>type;
        if(type==1)
            b=-b;
        else
        if(type==2)
            a=-a;
        else
        if(type==3)
        {
            a=-a;
            b=-b;
        }
        g[-a+n].push_back(b+n);
        g[-b+n].push_back(a+n);
    }
    for(int i=2*n;i>=0;i--)
        if(!viz[i]&&g[i].size())
        {
            dfs(i);
        }
    for(int i=top;i>=1;i--)
        if(!r[st[i]+n]&&!r[-st[i]+n])
            r[-st[i]+n]=1;
    for(int i=1;i<=n;i++)
        if(r[i+n]||(!r[i+n]&&!r[-i+n]))
        {
            nr++;
            rez[nr]=i;
        }
    fout<<nr<<'\n';
    for(int i=1;i<=nr;i++)
        fout<<rez[i]<<'\n';
}
