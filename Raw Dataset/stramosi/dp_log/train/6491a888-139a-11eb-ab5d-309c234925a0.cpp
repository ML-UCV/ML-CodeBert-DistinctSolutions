#include<bits/stdc++.h>

using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");
int n,m;
int s[250020][19];

int query(int x,int g)
{
    for(int i=0;(1<<i)<=g;i++)
        if(g&(1<<i))
            x=s[x][i];
    return x;
}

int main()
{
    fin.sync_with_stdio(0);
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>s[i][0];
    int lg2=32-__builtin_clz(n-1);
    cout<<lg2<<'\n';
    for(int j=1;j<lg2;j++)
        for(int i=1;i<=n;i++)
            s[i][j]=s[s[i][j-1]][j-1];
    for(int i=0;i<m;i++)
    {
        int q,g;
        fin>>q>>g;
        fout<<query(q,g)<<'\n';
    }
    return 0;
}
