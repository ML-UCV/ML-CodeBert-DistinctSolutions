#include <fstream>

using namespace std;

ifstream in("inv.in");
ofstream out("inv.out");

int v[100001],aux[100001];

int mmerge(int st,int dr,int v[])
{
    int i,j,k,m=(st+dr)/2,c=0;
    i=k=st;
    j=m+1;
    while(i<=m&&j<=dr)
    {
        if(v[i]<=v[j])
            aux[k++]=v[i++];
        else
            aux[k++]=v[j++],c+=m-i+1,c%=9917;
    }
    while(i<=m)
        aux[k++]=v[i++];
    while(j<=dr)
        aux[k++]=v[j++];
    for(k=st; k<=dr; k++)
        v[k]=aux[k];
    return c;
}

int msort(int st,int dr,int v[])
{
    int c = 0;
    if(st==dr)
        return 0;
    int m=(st+dr)/2;
    c += msort(st,m,v);
    c += msort(m+1,dr,v);
    c += mmerge(st,dr,v);
    c %= 9917;
    return c;
}

int main()
{
    int n,c=0;
    in>>n;
    for(int i=1;i<=n;i++)
        in>>v[i];

    out<<msort(1,n,v);
    return 0;
}
