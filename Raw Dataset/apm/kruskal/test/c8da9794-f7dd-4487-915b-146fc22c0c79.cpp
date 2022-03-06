#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin ("apm.in");
ofstream fout ("apm.out");
const int nmax=200005,mmax=400005;
int n,m,tt[nmax],rg[nmax],cnt,s;
pair <int,int> rez[mmax];
struct muchie
{
    int x,y,c;
}v[mmax];
bool cmp (muchie a,muchie b)
{
    return a.c<b.c;
}
int findset (int x)
{
    while (x!=tt[x])
    {
        x=tt[x];
    }
    return x;
}
void unionset (int x,int y)
{
    if (rg[x]<rg[y])
        tt[x]=y;
    else if (rg[y]<rg[x])
        tt[y]=x;
    else if (rg[x]==rg[y])
    {
        rg[x]++;
        tt[y]=x;
    }
}
void apm()
{
    for (int i=1;i<=m;i++)
    {
        int ttx=findset(v[i].x);
        int tty=findset(v[i].y);
        if (ttx!=tty)
        {
            unionset(ttx,tty);
            cnt++;
            rez[cnt].first=v[i].x;
            rez[cnt].second=v[i].y;
            s+=v[i].c;
        }
    }
}
int main()
{
    fin >> n >> m;
    for (int i=1;i<=m;i++)
    {
        fin >> v[i].x >> v[i].y >> v[i].c;
    }
    sort (v+1,v+m+1,cmp);
    for (int i=1;i<=n;i++)
    {
        tt[i]=i;
        rg[i]=1;
    }
    apm();
    fout << s << '\n';
    fout << cnt << '\n';
    for (int i=1;i<=cnt;i++)
    {
        fout << rez[i].first << " " << rez[i].second << '\n';
    }
}
