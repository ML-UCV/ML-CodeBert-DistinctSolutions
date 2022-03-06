#include <stdio.h>
#include <string.h>




char s[50100], sfin[50100];

int ind[26], perm[50100], AIB[50100];



inline int lsb(int X)

{

 return X & -X;

}



int query(int x)

{

 int cnt = 0;



 while (x)

 {

  cnt += AIB[x];

  x = x - lsb(x);

 }



 return cnt;

}



void update(int x, int N)

{

 while (x <= N)

 {

  AIB[x] ++;

  x += lsb(x);

 }

}



int main()

{

 int i, N;



 freopen("swap.in", "r", stdin);

 freopen("swap.out", "w", stdout);



 fgets(s, 50001, stdin); fgets(sfin, 50001, stdin);

 N = strlen(s + 1);



 for (i = 1; i <= N; i ++)

 {

  int now = s[i] - 'a';

  while (ind[now] <= N)

  {

   ++ ind[now];

   if (sfin[ind[now]] == s[i])

    break;

  }

  if (ind[now] == N + 1)

  {

   printf("-1");

   return 0;

  }

  perm[i] = ind[now];

 }



 int sol = 0;

 for (i = 1; i <= N; i ++)

 {

  sol += i - 1 - query(perm[i]);

  update(perm[i], N);

 }



 printf("%d", sol);

 return 0;

}
