#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>


using namespace std;
int a, b, n, m, i, j, nod, fiu;

int viz[1510], Nr[1510];

long double Cst, cst[1510], c, Min;

vector < pair <int, double> > V[1510];



int egal (double a, double b) {

 if ( a - b >= -0.00000000001 && a - b <= 0.00000000001 ) return 0;

 if ( a - b < -0.00000000001) return -1;

 if ( a - b > 0.00000000001) return 1;

 return 0;

}



int main () {



 FILE *f = fopen ("dmin.in", "r");

 FILE *g = fopen ("dmin.out", "w");



 fscanf (f, "%d %d", &n, &m);

 for (i = 1; i <= m; i++) {

  fscanf (f, "%d %d %Lf", &a, &b, &c);

  c = log(c);

  V[a].push_back (make_pair (b, c));

  V[b].push_back (make_pair (a, c));

 }



 for (i = 2; i <= n; i++)

  cst[i] = 1 << 30;



 cst[1] = 0; Nr[1] = 1;

 for (i = 1; i <= n; i++) {

  Min = 1 << 30;

  for (j = 1; j <= n; j++) {

   if ( egal(Min, cst[j]) == 1 && !viz[j]) {

    Min = cst[j];

    nod = j;

   }

  }



  viz[nod] = 1;

  for (j = 0; j < (int)V[nod].size(); j++) {

   fiu = V[nod][j].first;

   Cst = V[nod][j].second + cst[nod];

   if ( !egal (cst[fiu], Cst) ) {

    Nr[fiu]+= Nr[nod];

    if (Nr[fiu] > 104659) Nr[fiu]-= 104659;

   }



   if ( egal(cst[fiu], Cst) == 1 ) {

    cst[fiu] = Cst;

    Nr[fiu] = Nr[nod];

    if (Nr[fiu] > 104659) Nr[fiu]-= 104659;

   }

  }

 }



 for (i = 2; i <= n; i++)

  fprintf (g, "%d ", Nr[i]);



 fclose (f);

 fclose (g);



 return 0;



}
