#include <stdio.h>
int M, N;

char A[2000005], B[2000005];

int pi[2000005], pos[1024];



void make_prefix(void)

{

 int i, q = 0;



 for (i = 2, pi[1] = 0; i <= M; ++i)

 {

  while (q && A[q + 1] != A[i])

   q = pi[q];

  if (A[q + 1] == A[i])

   ++q;

  pi[i] = q;

 }

}



int main(void)

{

 int i, q = 0, n = 0;



 freopen("strmatch.in", "r", stdin);

 freopen("strmatch.out", "w", stdout);



 fgets(A, sizeof(A), stdin);

 fgets(B, sizeof(B), stdin);

 for (; (A[M] >= 'A' && A[M] <= 'Z') || (A[M] >= 'a' && A[M] <= 'z')

  || (A[M] >= '0' && A[M] <= '9'); ++M);

 for (; (B[N] >= 'A' && B[N] <= 'Z') || (B[N] >= 'a' && B[N] <= 'z')

  || (B[N] >= '0' && B[N] <= '9'); ++N);

 for (i = M; i; --i) A[i] = A[i - 1]; A[0] = ' ';

 for (i = N; i; --i) B[i] = B[i - 1]; B[0] = ' ';



 make_prefix();



 for (i = 1; i <= N; ++i)

 {

  while (q && A[q + 1] != B[i])

   q = pi[q];

  if (A[q + 1] == B[i])

   ++q;

  if (q == M)

  {

   q = pi[M];

   ++n;

   if (n <= 1000)

    pos[n] = i - M;

  }

 }



 printf("%d\n", n);

 for (i = 1; i <= ((n < 1000) ? n : 1000); ++i)

  printf("%d ", pos[i]);

 printf("\n");



 return 0;

}
