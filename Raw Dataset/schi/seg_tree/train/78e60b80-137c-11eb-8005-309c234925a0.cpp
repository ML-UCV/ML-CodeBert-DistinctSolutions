#include <bits/stdc++.h>

using namespace std;

ifstream fin("schi.in");
ofstream fout("schi.out");

const int DIM = 30007;

int arb[DIM * 4];
int sol[DIM];

void build(int pos, int l, int r)
{
 arb[pos] = r - l + 1;

 if(l != r)
 {
  int mid = (l + r) / 2;

  build(pos * 2, l, mid);
  build(pos * 2 + 1, mid + 1, r);
 }
}

int query(int pos, int l, int r, int x)
{
 if(x >= r)
 {
  return arb[pos];
 }

 int mid = (l + r) / 2;

 int ans = 0;

 if(x <= mid)
 {
  ans = query(pos * 2, l, mid, x);
 }
 else
 {
  ans = arb[pos * 2] + query(pos * 2 + 1, mid + 1, r, x);
 }

 return ans;
}

void update(int pos, int l, int r, int x)
{
 if(l == r)
 {
  arb[pos] = 0;
  return ;
 }

 int mid = (l + r) / 2;

 if(x <= mid)
  update(pos * 2, l, mid, x);
 else
  update(pos * 2 + 1, mid + 1, r, x);

 arb[pos] = arb[pos * 2] + arb[pos * 2 + 1];
}

int v[DIM];

main()
{
 int n;
 fin >> n;

 build(1, 1, n);

 for(int i = 1; i <= n; i++)
  fin >> v[i];

 for(int i = n; i >= 1; i--)
 {
  int l = 1;
  int r = n;

  int pos = 0;

  while(l <= r)
  {
   int mid = (l + r) / 2;

   if(query(1, 1, n, mid) < v[i])
   {
    l = mid + 1;
   }
   else
   {
    pos = mid;
    r = mid - 1;
   }
  }

  sol[pos] = i;

  update(1, 1, n, pos);
 }

 for(int i = 1; i <= n; i++)
  fout << sol[i] << '\n';
}
