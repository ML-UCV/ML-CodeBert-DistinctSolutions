#include <iostream>
#include <fstream>

using namespace std;

ifstream in("inv.in");
ofstream out("inv.out");

int aux[100005],v[100005],n,cnt = 0;

int mmerge(int st,int dr,int v[])
{
     int i,j,k,m = (st+dr)/2,nr = 0;
     i = k = st;
     j = m+1;
     while (i <= m && j <= dr)
     {
         if (v[i] <= v[j])
         {
            aux[k++] = v[i++];
         }
         else
         {
            aux[k++] = v[j++];
            nr += m-i+1;
            nr %= 9917;
         }
     }
     while (i <= m)
     {
        aux[k++] = v[i++];
     }
     while (j <= dr)
     {
        aux[k++] = v[j++];
     }
     for (k=st; k<=dr; k++)
     {
        v[k] = aux[k];
     }
     return nr;
}

int msort(int st,int dr,int v[])
{
    int cnt = 0;
    if (st == dr)
    {
        return 0;
    }
    int m = (st+dr)/2;
    cnt += msort(st,m,v);
    cnt %= 9917;
    cnt += msort(m+1,dr,v);
    cnt %= 9917;
    cnt += mmerge(st,dr,v);
    cnt %= 9917;
    return cnt;
}

int main()
{
    int i;
    in >> n;
    for (i=1; i<=n; i++)
    {
        in >> v[i];
    }
    cnt = msort(1,n,v);
    out << cnt;
    return 0;
}
