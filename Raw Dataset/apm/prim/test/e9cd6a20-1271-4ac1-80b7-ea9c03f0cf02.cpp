#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>


using namespace std;



const int NMAX = 200000;

const int CMAX = 1000;



struct elem {

  int nod, cost;



  elem(int cnod = 0, int ccost = 0) {

    nod = cnod;

    cost = ccost;

  }

};



bool operator > (elem e1, elem e2) {

  return e1.cost > e2.cost;

}



int n, m, APM;

vector<elem> graf[NMAX + 5];

priority_queue<elem, vector<elem>, greater<elem>> pq;

bool sel[NMAX + 5];

int cmin[NMAX + 5];

int tata[NMAX + 5];



int main() {

  freopen("apm.in", "r", stdin);

  freopen("apm.out", "w", stdout);





  scanf("%d %d", &n, &m);



  for(int i = 1; i <= m; i++) {

    int x, y, c;



    scanf("%d %d %d", &x, &y, &c);



    graf[x].push_back(elem(y, c));

    graf[y].push_back(elem(x, c));

  }



  for(int i = 1; i <= n; i++)

    cmin[i] = CMAX + 5;



  cmin[1] = 0;

  pq.push(elem(1, 0));



  while(!pq.empty()) {

    elem crt = pq.top();

    pq.pop();

    if(crt.cost > cmin[crt.nod] || sel[crt.nod])

      continue;



    sel[crt.nod] = true;

    APM += crt.cost;





    for(elem vec: graf[crt.nod])





      if(!sel[vec.nod] && vec.cost < cmin[vec.nod]) {

        cmin[vec.nod] = vec.cost;

        tata[vec.nod] = crt.nod;

        pq.push(elem(vec.nod, vec.cost));

      }

  }





  printf("%d\n%d\n", APM, n - 1);

  for(int i = 2; i <= n; i++)

    printf("%d %d\n", tata[i], i);



  return 0;

}
