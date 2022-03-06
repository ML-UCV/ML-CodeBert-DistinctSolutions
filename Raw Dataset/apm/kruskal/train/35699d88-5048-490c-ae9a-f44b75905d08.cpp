#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct MUCHIE

{

 int x, y, c;

 bool v;

};



vector<MUCHIE> v(1);

vector<int> t(1), h(1);

MUCHIE temp;

int n, m, x, y, c, vfx, vfy, nrm, cost, i;



bool cmp(MUCHIE a, MUCHIE b)

{

 return a.c < b.c;

}



int varf(int x)

{

 while (x != t[x])

  x = t[x];

 return x;

}



void unire(int x, int y)

{

 if (h[x] < h[y])

  t[x] = y;

 else if (h[y] < h[x])

  t[y] = x;

 else

 {

  t[y] = x;

  ++h[x];

 }

}



int main()

{

 fin >> n >> m;

 for (i = 1; i <= n; ++i)

 {

  t.push_back(i);

  h.push_back(1);

 }

 for (i = 1; i <= m; ++i)

 {

  fin >> x >> y >> c;

  temp.x = x;

  temp.y = y;

  temp.c = c;

  v.push_back(temp);

 }

 sort(v.begin() + 1, v.end(), cmp);

 for (i = 1; i <= m; ++i)

 {

  vfx = varf(v[i].x);

  vfy = varf(v[i].y);

  if (vfx != vfy)

  {

   unire(vfx, vfy);

   v[i].v = true;

   ++nrm;

   cost += v[i].c;

  }

 }

 fout << cost << '\n' << nrm << '\n';

 for (i = 1; i <= m; ++i)

  if (v[i].v)

   fout << v[i].x << ' ' << v[i].y << '\n';

 fin.close();

 fout.close();

 return 0;

}
