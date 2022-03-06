#include <bits/stdc++.h>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");
const int MAX=100006;
int n,m,x,y,st[MAX],dr[MAX],c[MAX];
int d[MAX];

int main()
{
    in>>n>>m>>x>>y;
    for(int i=1;i<=m;i++)
    {
        in>>st[i]>>dr[i]>>c[i];
    }
    d[x]=1;


    while(!d[y])
    {
        for(int i=1;i<=m;i++)
        {
            if(!d[st[i]] && d[dr[i]]) d[st[i]]=d[dr[i]]-c[i];
            else if(d[st[i]] && !d[dr[i]]) d[dr[i]]=d[st[i]]+c[i];
        }
    }
    out<<d[y]-1;
    return 0;
}
