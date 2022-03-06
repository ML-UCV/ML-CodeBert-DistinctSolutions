#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin ("schi.in");
ofstream cout ("schi.out");
int aib[30004],aib1[300004],v[30004],n;
struct ura
{
    int a,b;
}rez[30004];
int lsb (int x)
{
    return x&-x;
}
void update (int poz)
{
    for(int i=poz;i<=n;i+=lsb(i))
        ++aib[i];
}
int query (int poz)
{
    int s=0;
    for(int i=poz;i>=1;i-=lsb(i))
        s+=aib[i];
    return s;
}
void update1 (int poz)
{
    for(int i=poz;i<=n;i+=lsb(i))
        ++aib1[i];
}
int query1 (int poz)
{
    int s=0;
    for(int i=poz;i>=1;i-=lsb(i))
        s+=aib1[i];
    return s;
}
bool cmp (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    return false;
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;++i)
        {cin>>v[i];rez[i].b=i;}
    for(i=n;i>=1;--i)
    {
        int x1,x,sc=0;
        x1=0;
        sc=0;
        int pas=1<<20;
        while(pas)
        {
            if(x1+pas<=n && x1+pas-sc-aib1[x1+pas]<v[i+1])
                x1+=pas,sc+=aib1[x1];
            pas>>=1;
        }
        pas=1<<20;
        x=0;
        sc=0;
        while(pas)
        {
            if(x+pas<=n && x+pas-sc-aib1[x+pas]<v[i])
                x+=pas,sc+=aib1[x];
            pas>>=1;
        }
        ++x;
        ++x1;

        if(i<n)
        update(x1);
        update1(x);
        rez[i].a=v[i]+query(x);
    }
    sort(rez+1,rez+n+1,cmp);
    for(i=1;i<=n;++i)
        cout<<rez[i].b<<'\n';
    return 0;
}
