#include <fstream>

using namespace std;

ifstream in ("inv.in");
ofstream out ("inv.out");

const int N=100005, M=9917;

int v[N], aux[N];

int mergeV (int v[], int st, int dr)
{
    int m=(st+dr)/2, i, j, k, r=0;
    i=k=st;
    j=m+1;
    while(i<=m && j<=dr)
    {
        if(v[i]<=v[j])
            aux[k++]=v[i++];
        else
        {
            aux[k++]=v[j++];
            r+=m-i+1;
            r%=M;
        }
    }
    while(i<=m)
    {
        aux[k++]=v[i++];
    }
    while(j<=dr)
        aux[k++]=v[j++];
    for(k=st; k<=dr; k++)
        v[k]=aux[k];
    return r;
}

int ms(int v[], int st, int dr)
{
    int r=0;
    if(st==dr)
    {
        return 0;
    }
    int m=(st+dr)/2;
    r+=ms(v, st, m);
    r%=M;
    r+=ms(v, m+1, dr);
    r%=M;
    r+=mergeV(v, st, dr);
    r%=M;
    return r;
}

int main()
{
    int n, i;
    in>>n;
    for(i=0; i<n; i++)
    {
        in>>v[i];
    }
    out<<ms(v, 0, n-1);
    return 0;
}
