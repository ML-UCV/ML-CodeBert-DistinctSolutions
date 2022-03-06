#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
int n,m,costt;
struct vladut
{
    int st,dr,cost;
}mch[400005],sol[200005];
bool compare(vladut a,vladut b)
{
    return (a.cost<b.cost);
}
int T[200005],H[200005];
int TATA(int x)
{
    while(x!=T[x])return TATA(T[x]);
    return x;

}
int muchie(int r1,int r2)
{
    r1=TATA(r1);
    r2=TATA(r2);
    if(r1==r2)return 0;
    else
    {
        if(H[r1]<H[r2])
        {
            T[r1]=r2;
        }
        else if(H[r1]>H[r2])
        {
            T[r2]=r1;
        }
        else
        {
            T[r1]=r2;
            H[r2]++;
        }
        return 1;
    }
}
void kruskal()
{
    int cnt=0,k=1;
    while(cnt<n-1)
    {
        int r1=mch[k].st;
        int r2=mch[k].dr;
        if(muchie(r1,r2))
        {
            costt+=mch[k].cost;
            sol[++cnt].st=r1;
            sol[cnt].dr=r2;
        }
        k++;

    }
}
int main() {

    f>>n>>m;
    for(int i=1;i<=m;i++)
    {
        f>>mch[i].st>>mch[i].dr>>mch[i].cost;
    }
    sort(mch+1,mch+m+1,compare);
    for(int i=1;i<=n;i++)
    {
        T[i]=i;
        H[i]=1;
    }
    kruskal();
    g<<costt<<'\n';
    g<<n-1<<'\n';
    for(int i=1;i<=n-1;i++)
    {
        g<<sol[i].st<<" "<<sol[i].dr<<'\n';
    }
    return 0;
}
