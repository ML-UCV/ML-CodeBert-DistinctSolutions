#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;



struct muchie {

  int nod, tata, cost;



  muchie(int nn = 0, int tt = 0, int cc = 0) {

    nod = nn, tata = tt, cost = cc;

  }

};



int n, m, nm, capm;

int d[200000 + 5];

muchie apm[200000 + 5];

vector<muchie> v[200000 + 5];

priority_queue<muchie, vector<muchie>, greater<muchie>> pq;



bool operator > (muchie m1, muchie m2) {

  return m1.cost > m2.cost;

}



int main() {

  freopen("apm.in", "r", stdin);

  freopen("apm.out", "w", stdout);

  int x, y, z;



  scanf("%d %d", &n, &m);

  for(int i = 1; i <= n; i++)

    d[i] = 2000000000 + 5;

  for(int i = 1; i <= m; i++) {

    scanf("%d %d %d", &x, &y, &z);

    v[x].push_back(muchie(y, x, z));

    v[y].push_back(muchie(x, y, z));

  }



  pq.push(muchie(1, 0, 0));

  nm = 0;

  while(!pq.empty() && nm < n - 1) {

    muchie crt = pq.top();

    pq.pop();

    if(d[crt.nod] <= crt.cost)

      continue;



    d[crt.nod] = crt.cost;

    capm += crt.cost;

    if(crt.tata)

      apm[++nm] = crt;



    for(muchie vec: v[crt.nod])

      if(d[vec.nod] == 2000000000 + 5)

        pq.push(vec);

  }



  printf("%d\n%d\n", capm, nm);

  for(int i = 1; i <= nm; i++)

    printf("%d %d\n", apm[i].nod, apm[i].tata);



  return 0;

}
