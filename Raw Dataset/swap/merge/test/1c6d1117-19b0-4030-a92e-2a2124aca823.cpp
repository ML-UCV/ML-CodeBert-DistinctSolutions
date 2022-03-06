#include <stdio.h>
#include <string.h>
#include <vector>






using namespace std;







char S[2][50666];

vector<int> v[30];

int cnt[2][30], P[50666], Paux[50666];

int i, j, k, N, ninv;



void compute_ninv(int li, int ls)

{

 int m;



 if (li >= ls)

  return;



 m = (li + ls) >> 1;



 compute_ninv(li, m);

 compute_ninv(m + 1, ls);



 i = li, j = m + 1, k = li - 1;



 while (i <= m && j <= ls)

 {

  if (P[i] < P[j])

   Paux[++k] = P[i++];

  else

  {

   ninv += (m - i + 1);

   Paux[++k] = P[j++];

  }

 }



 if (i <= m)

 {

  for (j = i; j <= m; j++)

   Paux[++k] = P[j];

 }

 else

 {

  for (i = j; i <= ls; i++)

   Paux[++k] = P[i];

 }



 for (i = li; i <= ls; i++)

  P[i] = Paux[i];

}



int main()

{

 freopen("swap.in", "r", stdin);

 freopen("swap.out", "w", stdout);



 fgets(S[0] + 1, 50666, stdin);

 fgets(S[1] + 1, 50666, stdin);



 N = strlen(S[0] + 1) - 1;



 memset(cnt, 0, sizeof(cnt));

 for (i = 1; i <= N; i++)

 {

  cnt[1][S[1][i] - 'a']++;

  v[S[1][i] - 'a'].push_back(i);

 }



 for (i = 1; i <= N; i++)

 {

  cnt[0][S[0][i] - 'a']++;



  if (cnt[0][S[0][i] - 'a'] > cnt[1][S[0][i] - 'a'])

  {

   printf("-1\n");

   return 0;

  }



  P[i] = v[S[0][i] - 'a'][cnt[0][S[0][i] - 'a'] - 1];

 }



 ninv = 0;

 compute_ninv(1, N);



 printf("%d\n", ninv);



 return 0;

}
