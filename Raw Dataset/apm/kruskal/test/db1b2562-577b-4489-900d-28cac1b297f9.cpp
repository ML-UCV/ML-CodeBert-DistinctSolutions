#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");

pair< int, pair<int, int> > G[400010];

int n, m,a,b,ra,rb,sol,alese;

int t[200010], S[200010];



int rad(int x) {



 while (t[x] > 0)

  x = t[x];

 return x;

}



int main()

{



 fin >> n >> m;

 for (int i = 1; i <= m; i++)

 {

  fin >> G[i].second.first;

  fin >> G[i].second.second;

  fin >> G[i].first;

 }

 sort(G + 1, G + m + 1);

 for (int i = 1; i <= n; i++)

  t[i] = -1;

 for (int i = 1; i <= m; i++) {

  a = G[i].second.first;

  b = G[i].second.second;

  ra = rad(a);

  rb = rad(b);

  if (ra != rb) {

   if (-t[ra] > -t[rb]) {



    t[ra] += t[rb];

    t[rb] = ra;

   }

   else {

    t[rb] += t[ra];

    t[ra] = rb;

   }

   sol += G[i].first;



   alese++;

   S[alese] = i;

   if (alese == n - 1)

    break;

  }

 }



 fout << sol << "\n" << n - 1 << "\n";

 for (int i = 1; i <= alese; i++)

  fout << G[S[i]].second.first << " " << G[S[i]].second.second << "\n";

 return 0;

}
