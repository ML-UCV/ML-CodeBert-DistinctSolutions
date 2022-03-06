#include <stdio.h>
#include <string.h>


int n, sol;

int aib[50002], f[155];

int nr[27][50002];

char s1[50002], s2[50002];



int query (int p)

{

 int x = 0;

 while (p)

 {

  x += aib[p];

  p -= p & -p;

 }

 return x;

}



void update (int p)

{

 while (p <= n)

 {

  aib[p] ++;

  p += p & -p;

 }

}



int main ()

{

 freopen ("swap.in", "r", stdin);

 freopen ("swap.out", "w", stdout);



 fgets (s1, 50001, stdin);

 fgets (s2, 50001, stdin);

 n = strlen (s1 + 1);



 int i, p;



 for (i = 1; i <= n; i ++)

 {

  f[s1[i] - 'a'] ++;

  nr[s1[i] - 'a'][++ nr[s1[i] - 'a'][0]] = i;

  f[s2[i] - 'a'] --;

 }

 for (i = 0; i <= 26;nr[i][0] = 0, i ++)

  if (f[i])

  {

   printf ("-1\n");

   return 0;

  }



 for (i = 1; i <= n; i ++)

 {

  p = nr[s2[i] - 'a'][++ nr[s2[i] - 'a'][0]];

  sol = sol + i - 1 - query (p);

  update (p);

 }

 printf ("%d\n", sol);

 return 0;

}
