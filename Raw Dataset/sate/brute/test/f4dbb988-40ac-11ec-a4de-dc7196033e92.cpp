#include <bits/stdc++.h>

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

int n,m,x,y;
int a[100025],b[100025],d[100025];
int s[100025];///daca stim dist de la x la i

void read()
{
    int i;
    fin>>n>>m>>x>>y;
    for(i=1; i<=m; ++i)fin>>a[i]>>b[i]>>d[i];
    fin.close();
}

void solve()
{int i;
 s[x]=1;
 while(!s[y])

 for(i=1;i<=m;++i)
    if(!s[a[i]]&&s[b[i]])
       s[a[i]]=s[b[i]]-d[i];
    else if(s[a[i]]&&!s[b[i]])
        s[b[i]]=s[a[i]]+d[i];

 fout<<s[y]-1;
 fout.close();
}

int main()
{
    read();
    solve();
    return 0;
}
