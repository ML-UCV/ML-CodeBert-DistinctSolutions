#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



int n, m, r[200001], t[200001], ct, poz[200000], k;

pair < int, pair <int , int> > mu[400001];



int cauta (int a) {

  int x = a, y;

  while (x != t[x])

    x = t[x];

  while (a != t[a]) {

    y = t[a];

    t[a] = x;

    a = y;

  }

  return x;

}



void uneste (int a, int b) {

  int x = cauta (a);

  int y = cauta (b);

  if (r[x] < r[y])

    t[x] = y;

  else

    t[y] = x;

  if (r[x] == r[y])

    r[x]++;

}



void kruskal () {

  sort (mu + 1, mu + m + 1);

  for (int i = 1; i <= m; i++)

    if (cauta (mu[i].second.first) != cauta (mu[i].second.second)) {

      poz[++k] = i;

      uneste (mu[i].second.first, mu[i].second.second);

      ct += mu[i].first;

    }

}



int main()

{

  fin >> n >> m;

  for (int i = 1; i <= n; i++) {

    r[i] = 1; t[i] = i;

  }

  int x, y, c;

  for (int i = 1; i <= m; i++) {

    fin >> x >> y >> c;

    mu[i].first = c; mu[i].second = {x, y};

  }

  kruskal ();

  fout << ct << '\n';

  fout << k << '\n';

  for (int i = 1; i <= k; i++)

    fout << mu[poz[i]].second.first << ' ' << mu[poz[i]].second.second << '\n';

  return 0;

}
