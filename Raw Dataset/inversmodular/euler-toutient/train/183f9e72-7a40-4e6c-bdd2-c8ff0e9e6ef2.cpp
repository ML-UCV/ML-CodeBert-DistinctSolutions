#include <bits/stdc++.h>

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

int phi(int x)
{
 int ans = x;

 for(int i = 2; i * i <= x; ++i)
  if(x % i == 0)
  {
   while(x % i == 0)
    x /= i;

   ans = ans / i * (i - 1);
  }

 if(x > 1)
  ans = ans / x * (x - 1);

 return ans;
}

main()
{
 int x, y;
 fin >> x >> y;

 int p = phi(y) - 1;
 int ans = 1;

 for(; p; p >>= 1, x = (x * 1LL * x) % y)
  if(p & 1)
   ans = (ans * 1LL * x) % y;

 fout << ans << '\n';
}
