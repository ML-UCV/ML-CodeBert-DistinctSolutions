#include <bits/stdc++.h>



using namespace std;


ifstream f("schi.in");
ofstream g("schi.out");

int a[30005], n;
int tree[30005 << 2];
int ans[30005];

void update (int nod, int i, int j, int poz, const int k )
{
    if (i==j)
    {
        tree[nod]=0;
        ans[i]=k;
    }
    else
    {
        int m=(i+j)/2;
        if (poz<=tree[nod*2])
            update(nod*2, i, m, poz, k);
        else
            update(nod* 2+1, m+1, j, poz-tree[nod*2], k);
        tree[nod]=tree[nod * 2 ]+tree[nod * 2 + 1 ];
    }
}


void create(int nod, int i, int j)
{
    if (i==j)
        tree[nod]=1;
    else
    {
        int m=(i+j)/2;
        create (nod*2, i, m);
        create (nod*2+1, m+1, j);
        tree[nod]=tree[nod * 2]+tree[nod * 2 + 1];
    }
}

int main()
{
    f>>n;
    create(1 ,1 ,n);
    for (int i=1; i <= n; i ++)
        f>>a[i];
    for (int i=n; i>=1; i --)
        update(1, 1, n, a[i], i);
   for (int i=1; i <=n; i ++)
       g<<ans[i]<<'\n';

}
