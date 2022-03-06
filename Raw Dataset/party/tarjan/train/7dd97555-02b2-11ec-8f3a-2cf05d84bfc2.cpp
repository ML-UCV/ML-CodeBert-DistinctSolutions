#include <cstdio>
#include <cstring>#include <math.h>
#include <vector>
using namespace std;



int N, M;

pair <int, int> EXPR[100100];

int SOL[100100], SOL_PR[100100];

vector <int> G[100100], CT[100100];



bool eval_term(pair <int, int> T, int STACK[]) {

    int x, y;



    x = STACK[abs(T.first)];

    y = STACK[abs(T.second)];



    if (T.first < 0)

        x ^= 1;

    if (T.second < 0)

        y ^= 1;



    return (x | y);

}





inline bool ok_sol(int T) {

 int Q[100100], p, u, i, punQ;

 int VIZ[100100];

 int x, y, nE;



 memset(VIZ, 0, sizeof(VIZ));



 p = u = 1;

 Q[p] = T;

 VIZ[T] = 1;



 while (p <= u) {

  x = Q[p];



  for (i = 0; i < G[x].size(); i++) {

   y = abs(G[x][i]);

   nE = CT[x][i];



   if (VIZ[y] == 0) {



    int ant = SOL_PR[y];

    int punQ = 0;

    SOL_PR[y] = 0;

    if (!eval_term(EXPR[nE], SOL_PR))

     punQ = 1;



    SOL_PR[y] = 1;

    if (!eval_term(EXPR[nE], SOL_PR))

     punQ = 1;



    if (punQ) {

     SOL_PR[y] = 0;

     if (!eval_term(EXPR[nE], SOL_PR))

      SOL_PR[y] = 1;



     Q[++u] = y;

     VIZ[y] = 1;

    }

    else

     SOL_PR[y] = ant;

   }

   else {

    if (!eval_term(EXPR[nE], SOL_PR))

     return false;

   }

  }



  p++;

 }



 return true;

}





void read() {

 int i, a, b, c;

 scanf("%d%d", &N, &M);

 for (i = 1; i <= M; i++) {

  scanf("%d%d%d", &a, &b, &c);

  if (c == 0)

   EXPR[i] = make_pair(a, b);

  if (c == 1)

   EXPR[i] = make_pair(a, -b);

  if (c == 2)

   EXPR[i] = make_pair(-a, b);

  if (c == 3)

   EXPR[i] = make_pair(-a, -b);

  G[abs(a)].push_back(b); G[abs(b)].push_back(a);

  CT[abs(a)].push_back(i); CT[abs(b)].push_back(i);





 }



}



void afis() {

 int i, rez = 0;

 for (i = 1; i <= N; i++)

  rez += SOL[i];



 printf("%d\n", rez);

 for (i = 1; i <= N; i++)

  if (SOL[i] == 1)

   printf("%d\n", i);

}

int main() {



 int i, j, a, b;



 freopen("party.in", "r", stdin);

 freopen("party.out", "w", stdout);



 read();
 memset(SOL, -1, sizeof(SOL));



 for (i = 1; i <= N; i++) {

  if (SOL[i] == -1) {

   SOL[i] = 0;

   memcpy(SOL_PR, SOL, sizeof(SOL));

   if (ok_sol(i))

    memcpy(SOL, SOL_PR, sizeof(SOL));

   else {

    SOL[i] = 1;

    memcpy(SOL_PR, SOL, sizeof(SOL));

    if (ok_sol(i))

     memcpy(SOL, SOL_PR, sizeof(SOL));

    else {

     printf("-1\n");

     return 0;

    }

   }

  }

  else {

   memcpy(SOL_PR, SOL, sizeof(SOL));

   if (ok_sol(i))

    memcpy(SOL, SOL_PR, sizeof(SOL));

   else {

    SOL[i] ^= 1;

    if (ok_sol(i))

     memcpy(SOL, SOL_PR, sizeof(SOL));

    else {

     printf("-1\n");

     return 0;

    }



   }

  }
 }







 afis();



 return 0;

}
