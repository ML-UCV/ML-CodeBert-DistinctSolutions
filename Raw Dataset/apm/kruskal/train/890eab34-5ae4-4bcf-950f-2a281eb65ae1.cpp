#include <stdio.h>
#include <vector>
#include <algorithm>




FILE* fin, * fout;



struct edge {

 int x, y, c;

};



int n, m;

std::vector<edge> e;

std::vector<edge> apm;

int d[200005];



void compress(int x, int r) {

 while (x != r) {

  int t = d[x];

  d[x] = r;

  x = t;

 }

}



int root(int x) {

 int r = x;

 for (;r != d[r];r = d[r]);



 compress(x, r);



 return r;

}



void combine(int x, int y) {

 int r1 = root(x), r2 = root(y);



 d[r1] = r2;

}



void buildAPM() {

 for (int i = 1;i <= n;++i)

  d[i] = i;



 auto cmp = [](edge& e, edge& f) -> bool {return e.c < f.c;};



 sort(e.begin(), e.end(), cmp);



 for (auto a : e) {

  if (root(a.x) != root(a.y)) {

   apm.push_back(a);

   combine(a.x, a.y);

  }

 }



}



int main() {

 fin = fopen("apm.in", "r");

 fout = fopen("apm.out", "w");



 fscanf(fin, "%i %i", &n, &m);



 while (m--) {

  int x, y, c;

  fscanf(fin, "%i %i %i", &x, &y, &c);

  e.push_back({ x,y,c });

 }



 buildAPM();



 int c = 0;



 for (auto a : apm)

  c += a.c;



 fprintf(fout,"%i\n%i\n", c, apm.size());



 for (auto a : apm)

  fprintf(fout,"%i %i\n", a.x, a.y);



 return 0;

}
