#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <vector>
using namespace std;







struct relatie {int x, y, tip;} aux;

int n, m, x, y, tip, i, nr, p, ok;

int sol[105];

vector <relatie> R;



int main () {



 srand (time (0));

 freopen ("party.in", "r", stdin);

 freopen ("party.out", "w", stdout);



 scanf ("%d %d", &n, &m);

 for (i = 1; i <= n; i++)

  sol[i] = rand () %2;



 for (i = 1; i <= m; i++) {

  scanf ("%d %d %d", &aux.x, &aux.y, &aux.tip);

  R.push_back (aux);

 }



 while (!ok) {



  ok = 1;

  for (i = 0; i < m; i++) {

   aux = R[i];

   if (aux.tip == 0) {

    if (!sol[aux.x] && !sol[aux.y]) {

     p = i;

     ok = 0;

     break;

    }

   }



   else {

    if (aux.tip == 1) {

     if (!sol[aux.x] && sol[aux.y]) {

      p = i;

      ok = 0;

      break;

     }

    }



    else {

     if (aux.tip == 2) {

      if (sol[aux.x] && !sol[aux.y]) {

       p = i;

       ok = 0;

       break;

      }

     }



     else {

      if (sol[aux.x] && sol[aux.y]) {

       p = i;

       ok = 0;

       break;

      }

     }

    }

   }

  }



  if (!ok ) {

   aux = R[p];

   if (rand () % 2)

    sol[aux.x]^= 1;

   else

    sol[aux.y]^= 1;





  }

 }



 for (i = 1; i <= n; i++)

  nr+= sol[i];



 printf ("%d\n", nr);

 for (i = 1; i <= n; i++)

  if (sol[i]) printf ("%d\n", i);



 return 0;

}
