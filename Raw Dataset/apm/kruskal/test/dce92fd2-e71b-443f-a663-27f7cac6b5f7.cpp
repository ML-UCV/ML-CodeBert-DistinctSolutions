#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;



struct muchie {

  int nod1, nod2, cost;



  muchie(int n1 = 0, int n2 = 0, int c = 0) {

    nod1 = n1, nod2 = n2, cost = c;

  }

};



int n, m, capm, nm;

int repr[200000 + 5], apm[200000 + 5];

vector<int> v[200000 + 5];

muchie muchii[400000 + 5];



bool cmp(muchie m1, muchie m2) {

  return m1.cost < m2.cost;

}



int get_repr(int nod) {

  while(nod != repr[nod])

    nod = repr[nod];

  return nod;

}



void union_repr(int nod, int rnod) {

  while(nod != repr[nod]) {

    int aux = nod;

    nod = repr[nod];

    repr[aux] = rnod;

  }

  repr[nod] = rnod;

}



int main() {

  freopen("apm.in", "r", stdin);

  freopen("apm.out", "w", stdout);

  int x, y, z;



  scanf("%d %d", &n, &m);

  for(int i = 1; i <= n; i++)

    repr[i] = i;

  for(int i = 1; i <= m; i++) {

    scanf("%d %d %d", &x, &y, &z);

    muchii[i] = muchie(x, y, z);

  }



  sort(muchii + 1, muchii + m + 1, cmp);

  nm = 0;

  for(int i = 1; i <= m && nm < n - 1; i++) {

    int n1 = muchii[i].nod1, n2 = muchii[i].nod2, c = muchii[i].cost;

    int r1 = get_repr(n1), r2 = get_repr(n2);



    if(r1 == r2)

      continue;



    capm += c;

    apm[++nm] = i;

    union_repr(n1, r2);

  }



  printf("%d\n%d\n", capm, nm);

  for(int i = 1; i <= nm; i++)

    printf("%d %d\n", muchii[apm[i]].nod1, muchii[apm[i]].nod2);



  return 0;

}
