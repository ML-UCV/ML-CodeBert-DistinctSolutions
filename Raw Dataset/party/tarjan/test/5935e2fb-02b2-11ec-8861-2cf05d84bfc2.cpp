#include <bits/stdc++.h>


using namespace std;



const int N = 1005;

mt19937 gen(time(0));

uniform_int_distribution<int> dis(0, 1e6);



int i, n, m, x[N], y[N], z[N], val[N], nx[N], ny[N], rs;



int main() {

  ifstream cin("party.in");

  ofstream cout("party.out");

  ios_base::sync_with_stdio(0);



  cin >> n >> m;

  for(i = 1; i <= m; ++i) {

    cin >> x[i] >> y[i] >> z[i];



    if(z[i] == 1) ny[i] = 1;

    if(z[i] == 2) nx[i] = 1;

    if(z[i] == 3) nx[i] = ny[i] = 1;

  }



  for(i = 1; i <= m; ++i)

    if(!(val[x[i]] ^ nx[i]) && !(val[y[i]] ^ ny[i])) {

      if(dis(gen) & 1) val[x[i]] ^= 1;

      else val[y[i]] ^= 1;

      i = 0;

    }



  for(i = 1; i <= n; ++i) if(val[i]) ++rs;



  cout << rs << '\n';

  for(i = 1; i <= n; ++i) if(val[i]) cout << i << '\n';



  return 0;

}
