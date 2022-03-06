#include <bits/stdc++.h>


using namespace std;

const int lim = 1e5;

int arbint[4 * lim], v[lim], w[lim];

vector <int> normie;



inline int to_normie(int x){

  int ans = 0;

  for(int pas = 1 << 17; pas > 0; pas /= 2)

    if(ans + pas < normie.size() && normie[ans + pas] <= x)

      ans += pas;

  return ans;

}



void update(int nod, int st, int dr, int x){

  if(st == dr){

    arbint[nod]++;

    return;

  }

  if(x <= (st + dr) / 2)

    update(2 * nod, st, (st + dr) / 2, x);

  else

    update(2 * nod + 1, (st + dr) / 2 + 1, dr, x);

  arbint[nod] = arbint[2 * nod] + arbint[2 * nod + 1];

}



int query(int nod, int st, int dr, int l, int r){

  if(l <= st && dr <= r)

    return arbint[nod];

  int ans = 0;

  if(l <= (st + dr) / 2)

    ans += query(2 * nod, st, (st + dr) / 2, l, r);

  if(r > (st + dr) / 2)

    ans += query(2 * nod + 1, (st + dr) / 2 + 1, dr, l, r);

  return ans;

}



int main()

{

  int n;

  ifstream fin("inv.in");

  ofstream fout("inv.out");

  fin >> n;

  for(int i = 0; i < n; i++){

    fin >> v[i];

    w[i] = v[i];

  }

  sort(w, w + n);

  normie.push_back(w[0]);

  for(int i = 1; i < n; i++)

    if(w[i] != w[i - 1])

      normie.push_back(w[i]);

  for(int i = 0; i < n; i++)

    v[i] = to_normie(v[i]);

  long long ans = 0;

  for(int i = 0; i < n; i++){

    if(v[i] < n - 1)

      ans = ans + query(1, 0, n - 1, v[i] + 1, n - 1);

    update(1, 0, n - 1, v[i]);

  }

  fout << ans % 9917;

  fin.close();

  fout.close();

  return 0;

}
