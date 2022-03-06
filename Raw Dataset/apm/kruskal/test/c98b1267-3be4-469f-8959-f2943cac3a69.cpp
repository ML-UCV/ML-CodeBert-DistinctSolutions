#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin ("apm.in");
ofstream cout ("apm.out");
int sef[200010];
struct ura
{
    int x,y,cost;
};
ura v[400010];
struct urica
{
    int x,y;
};
urica rez[400010];
bool cmp(ura a,ura b)
{
    if (a.cost<b.cost)
        return true;
    else
        return false;
}
int sef_suprem(int nod)
{
    if (sef[nod]==nod)
        return nod;
    else
        return sef[nod]=sef_suprem(sef[nod]);
}
void unire(int nod1,int nod2)
{
    int sef1,sef2;
    sef1=sef_suprem(nod1);
    sef2=sef_suprem(nod2);
    sef[sef1]=sef2;
}
int main()
{
    int n,m,i,ct,cost_total,sef_x,sef_y;
    cin>>n>>m;
    for (i=1; i<=m; i++)
        cin>>v[i].x>>v[i].y>>v[i].cost;
    sort (v+1,v+m+1,cmp);
    for (i=1; i<=n; i++)
        sef[i]=i;
    i=1;
    ct=0;
    cost_total=0;
    while (ct<n-1)
    {
        sef_x=sef_suprem(v[i].x);
        sef_y=sef_suprem(v[i].y);
        if (sef_x!=sef_y)
        {
            unire(v[i].x,v[i].y);
            cost_total=cost_total+v[i].cost;
            ct++;
            rez[ct].x=v[i].x;
            rez[ct].y=v[i].y;
        }
        i++;
    }
    cout<<cost_total<<"\n"<<ct<<"\n";
    for (i=1; i<=ct; i++)
        cout<<rez[i].x<<" "<<rez[i].y<<"\n";
    return 0;
}
