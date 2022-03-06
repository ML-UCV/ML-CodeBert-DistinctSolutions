#include <bits/stdc++.h>

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

const int DIM = 2e6 + 1;

int phi[DIM];

main()
{
 string v, t;
 fin >> v >> t;

 int n = v.size();
 int m = t.size();

 v = ' ' + v;
 t = ' ' + t;

 int k = 0;

 for(int i = 2; i <= n; ++i)
 {
  while(k && v[k + 1] != v[i])
   k = phi[k];

  if(v[k + 1] == v[i])
   ++k;

  phi[i] = k;
 }

 k = 0;
 int cnt = 0;

 vector <int> ans;

 for(int i = 1; i <= m; ++i)
 {
  while(k && v[k + 1] != t[i])
   k = phi[k];

  if(v[k + 1] == t[i])
   ++k;

  if(k == n)
  {
   k = phi[k];
   ++cnt;

   if(ans.size() < 1000)
   {
    ans.emplace_back(i - n);
   }
  }
 }

 fout << cnt << '\n';

 for(auto i : ans)
  fout << i << ' ';
}
