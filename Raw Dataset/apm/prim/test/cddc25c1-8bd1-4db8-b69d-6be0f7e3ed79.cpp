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



struct minHeap {

  int tata[200000 + 5];

  int d[200000 + 5];

  int poz[200000 + 5];

  int val[200000 + 5];

  int dim;



  minHeap(int ddim = 0) {

    dim = 0;

    for(int i = 1; i <= ddim; i++)

      d[i] = 2000000000 + 5;

  }



  muchie top() {

    return muchie(val[1], tata[val[1]], d[val[1]]);

  }



  bool isEmpty() {

    return dim == 0;

  }



  bool inHeap(int nod) {

    return poz[nod] >= 1 && poz[nod] <= dim;

  }



  void urcare(int ind) {

    if(ind == 1)

      return;

    if(d[val[ind]] < d[val[ind / 2]]) {

      swap(val[ind], val[ind / 2]);

      poz[val[ind]] = ind;

      poz[val[ind / 2]] = ind / 2;

      urcare(ind / 2);

    }

  }



  void coborare(int ind) {

    int st = 2 * ind, dr = 2 * ind + 1, minim = ind;



    if(st <= dim)

      minim = (d[val[st]] < d[val[minim]]) ? st : minim;

    if(dr <= dim)

      minim = (d[val[dr]] < d[val[minim]]) ? dr : minim;



    if(minim != ind) {

      swap(val[minim], val[ind]);

      poz[val[minim]] = minim;

      poz[val[ind]] = ind;

      coborare(minim);

    }

  }



  void push(muchie crt) {

    if(inHeap(crt.nod)) {

      if(crt.cost < d[crt.nod]) {

        d[crt.nod] = crt.cost;

        tata[crt.nod] = crt.tata;

        urcare(poz[crt.nod]);

      }

    }

    else if(d[crt.nod] == 2000000000 + 5) {

      val[++dim] = crt.nod;

      poz[crt.nod] = dim;

      tata[crt.nod] = crt.tata;

      d[crt.nod] = crt.cost;

      urcare(dim);

    }

  }



  void pop() {

    poz[val[1]] = 0;

    if(dim > 1) {

      swap(val[1], val[dim--]);

      poz[val[1]] = 1;

      coborare(1);

    }

    else

      dim--;

  }

};



int n, m, nm, capm;

muchie muchii[200000 + 5];

vector<muchie> v[200000 + 5];



int main() {

  freopen("apm.in", "r", stdin);

  freopen("apm.out", "w", stdout);

  int x, y, z;



  scanf("%d %d", &n, &m);

  for(int i = 1; i <= m; i++) {

    scanf("%d %d %d", &x, &y, &z);

    v[x].push_back(muchie(y, x, z));

    v[y].push_back(muchie(x, y, z));

  }



  minHeap pq = minHeap(n);

  pq.push(muchie(1, 0, 0));

  nm = 0;

  while(!pq.isEmpty() && nm < n - 1) {

    muchie crt = pq.top();

    pq.pop();



    capm += crt.cost;

    if(crt.tata)

      muchii[++nm] = crt;

    for(muchie vec: v[crt.nod])

      pq.push(vec);

  }



  printf("%d\n%d\n", capm, nm);

  for(int i = 1; i <= nm; i++)

    printf("%d %d\n", muchii[i].nod, muchii[i].tata);



  return 0;

}
