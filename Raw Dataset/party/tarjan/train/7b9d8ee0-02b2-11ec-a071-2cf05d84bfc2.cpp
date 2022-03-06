#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


inline int get_rez(int tip, int x, int y) {

 if (tip == 0 && (x || y))

  return 1;



 if (tip == 1 && (x || (!x && !y)))

  return 1;



 if (tip == 2 && (y || (!x && !y)))

  return 1;



 if (tip == 3 && (!x || !y))

  return 1;



 return 0;

}



int main() {



 freopen("party.in", "r", stdin);

 freopen("party.out", "w", stdout);



 srand(time(0));



 int n, m, value[110], edge[3][1010];



 scanf("%d %d", &n, &m);

 for (int i = 1; i <= m; i++)

  scanf("%d %d %d", &edge[0][i], &edge[1][i], &edge[2][i]);

 memset(value, 0, sizeof(value));



 int ok = 0;

 while (!ok) {

  ok = 1;

  for (int i = 1; i <= m; i++) {

   int rez = get_rez(edge[2][i], value[edge[0][i]], value[edge[1][i]]);



   if (rez == 0) {

    ok = 0;



    int poz = rand() % 2;

    value[edge[poz][i]] = 1 - value[edge[poz][i]];

   }

  }

 }



 int nrsol = 0;

 for (int i = 1; i <= n; i++)

  nrsol += value[i];



 printf("%d\n", nrsol);

 for (int i = 1; i <= n; i++)

  if (value[i])

   printf("%d\n", i);



 return 0;

}
