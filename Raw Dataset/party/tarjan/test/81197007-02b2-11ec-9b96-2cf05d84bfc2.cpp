#include <fstream>
#include <utility>
#include <stdlib.h>
#include <vector>
#include <ctime>
using namespace std;







int N, M, bad;
int v[2001], c[2001], b[2001];
vector<pair<int, int> > exp;

int eval(int pos)
{
 pair<int, int> e = exp[pos];
 if (c[pos] == 0)
  return (v[e.first] || v[e.second]);
 if (c[pos] == 1)
  return (v[e.first] || !v[e.second]);
 if (c[pos] == 2)
  return (!v[e.first] || v[e.second]);
 return (!v[e.first] || !v[e.second]);
}

int extra()
{
 int i;
 for (i = (1); i <= (N); i++)
  if (v[i]) return 1;
 return 0;
}

int main()
{
 int i, x, y, pas;
 ifstream fin("party.in");
 ofstream fout("party.out");
 srand(time(NULL));
 fin >> N >> M;
 for (i = (0); i <= (M - 1); i++)
 {
  fin >> x >> y >> c[i];
  exp.push_back(make_pair(x, y));
 }




 for (i = (1); i <= (N); i++) v[i] = (i % 2);

 for (pas = (0); pas <= (100000); pas++)
 {
  bad = 0;
  int ok = eval(0);
  if (!eval(0)) b[++bad] = 0;
  for (i = (1); i <= (M - 1); i++)
  {
   ok = ok && eval(i);
   if (!eval(i)) b[++bad] = i;
  }

  if (ok && extra()) break;
  if (!bad) b[++bad] = rand() % N + 1;

  int nr = b[rand() % bad + 1], nr2 = rand() % 2;

  if (nr2)
   v[exp[nr].first] = !v[exp[nr].first];
  else
   v[exp[nr].second] = !v[exp[nr].second];
 }

 int res = 0;
 for (i = 1; i <= N; i++)
  if (v[i]) res++;
 fout << res << '\n';
 for (i = (1); i <= (N); i++)
  if (v[i]) fout << i << '\n';
 fin.close(), fout.close();
}
