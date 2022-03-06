#include <bits/stdc++.h>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

vector<int> v, fp;

int n, aib[33033], x;

inline void Update(int poz, int val)

{

 for (int i = poz; i <= n; i += i & -i)

        aib[i] += val;

}

inline int Query(int poz)

{

 int s = 0;

 for (int i = poz; i > 0; i -= i & -i)

  s += aib[i];

 return s;

}

inline int Find(int val)

{

 int st = 1, dr = n, p, mid, res;

 while (st <= dr)

 {

  mid = (st + dr) / 2;

  p = Query(mid);

  if (p == val)

   res = mid, dr = mid - 1;

  else if (p < val)

   st = mid + 1;

  else dr = mid - 1;

 }

 return res;

}

int main()

{

 fin >> n;

 v = fp = vector<int>(n + 1);

 for (int i = 1; i <= n; ++i)

  fin >> v[i], Update(i, 1);

 for (int i = n; i; --i)

 {

  x = Find(v[i]);

  fp[x] = i;

  Update(x, -1);

 }

 for (int i = 1; i <= n; ++i)

  fout << fp[i] << '\n';

 fin.close();

 fout.close();

 return 0;

}
