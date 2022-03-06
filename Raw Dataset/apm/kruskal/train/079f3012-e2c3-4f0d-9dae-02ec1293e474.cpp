#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");
int h[200005],t[200005],n,m,x,y,c,i,j,aux,rad,s;
struct muchii
{
    int a;
    int b;
    int cost;
};
muchii e[200005],v[200005];
int find(int k)
{
    rad=k;
    while(t[rad])
        rad=t[rad];
    return rad;
}
void uniune(int a, int b)
{
    if(h[a]>h[b])
        t[b]=a;
    else
        if(h[a]<h[b])
            t[a]=b;
        else
        {
            t[a]=b;
            h[b]++;
        }
}
bool cmp1(muchii aa, muchii bb)
{
    if(aa.cost<bb.cost)
        return 1;
    return 0;
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=m;i++)
    {
        fin>>x>>y>>c;
        e[i].a=x;
        e[i].b=y;
        e[i].cost=c;
    }
    s=0;
    sort(e+1,e+m+1,cmp1);
    int dim=0;
    for(i=1;i<=m;i++)
    {
        if(find(e[i].a)!=find(e[i].b))
        {
            s=s+e[i].cost;
            dim++;
            v[dim]=e[i];
            uniune(find(e[i].a),find(e[i].b));
        }
    }
    fout<<s<<"\n";
    fout<<n-1<<"\n";
    for(i=1;i<=dim;i++)
        fout<<v[i].a<<" "<<v[i].b<<"\n";
    fin.close();
    fout.close();
    return 0;
}
