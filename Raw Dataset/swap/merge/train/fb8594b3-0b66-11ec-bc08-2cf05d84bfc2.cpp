#include <bits/stdc++.h>

using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

const int DIM = 5e4 + 7;
const int sigma = 26;

queue <int> pos_ch[sigma];
int permutare[DIM];
int arb[DIM * 4];

void build(int pos, int l, int r)
{
 arb[pos] = (r - l + 1);

 if(r != l)
 {
  int mid = (l + r) / 2;

  build(pos * 2, l, mid);
  build(pos * 2 + 1, mid + 1, r);
 }
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

 arb[pos] = arb[pos * 2 + 1] + arb[pos * 2];
}

int query(int pos, int l, int r, int x, int y)
{
 if(x <= l && r <= y)
 {
  return arb[pos];
 }

 int mid = (l + r) / 2;

 int sum = 0;

 if(x <= mid)
  sum += query(pos * 2, l, mid, x, y);

 if(y > mid)
  sum += query(pos * 2 + 1, mid + 1, r, x, y);

 return sum;
}

main()
{
 string s, t;
 fin >> s >> t;

 int n = s.size();

 for(int i = 0; i < n; i++)
  pos_ch[s[i] - 'a'].push(i + 1);

 for(int i = 0; i < n ; i++)
 {
  int id = t[i] - 'a';

  if(pos_ch[id].empty() == true)
  {
   fout << -1;
   return 0;
  }

  permutare[i + 1] = pos_ch[id].front();
  pos_ch[id].pop();
 }

 build(1, 1, n);

 int cost = 0;

 for(int i = 1; i <= n; i++)
 {
  cost += query(1, 1, n, 1, permutare[i]) - 1;
  update(1, 1, n, permutare[i]);
 }

 fout << cost;
}
