#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <limits>
#include <cmath>
#include <fstream>
using namespace std;





ifstream fin("dmin.in");

ofstream fout("dmin.out");



vector<tuple<int, double> >graf[1600];

double dr[1600];

int nrdr[1600];



struct nod

{

 int to;

 double dst;

 bool operator< (const nod &y) const

 {

  return (dst - y.dst) > 0.0000000001;

 }

};



void dijkstra(int x, int n)

{

 priority_queue<nod> pq;

 pq.push({ x, 0.0 });

 nrdr[x] = 1;

 for (int i = 2; i <= n; i++)

  dr[i] = 1000000;

 while (!pq.empty())

 {

  int a;

  double dmin;

  dmin = pq.top().dst;

  a = pq.top().to;

  pq.pop();

  for (auto &it : graf[a])

  {

   int b;

   double w;

   tie(b, w) = it;

   if (fabs(dmin + w - dr[b]) <= 0.0000000001)

   {

    nrdr[b] = (nrdr[a] + nrdr[b]) % 104659;

   }

   else

   {

    if (w + dmin < dr[b])

    {

     dr[b] = dmin + w;

     nrdr[b] = nrdr[a];

     pq.push({ b, dr[b] });

    }

   }

  }





 }





}





int main()

{

 long long n, m;

 fin >> n >> m;

 for (long long i = 0; i < m; i++)

 {

  int a, b;

  double w;

  fin >> a >> b >> w;

  graf[a].push_back({ b, log(w) });

  graf[b].push_back({ a, log(w) });

 }

 dijkstra(1, n);

 for (int i = 2; i <= n; i++)

  fout << nrdr[i] << ' ';







}
