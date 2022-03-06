#include <stdio.h>
#include <string.h>
char A[2000001], B[2000001];

int NA, NB;

int hashA1, hashA2, P1, P2;

char match[2000001];

int main()

{

 freopen("strmatch.in", "rt", stdin);

 freopen("strmatch.out", "wt", stdout);

 scanf("%s %s", A, B);

 NA = strlen(A);

 NB = strlen(B);

 P1 = P2 = 1;

 hashA1 = hashA2 = 0;

 for (int i = 0; i < NA; i++)

 {

  hashA1 = (hashA1 * 73 + A[i]) % 100007;

  hashA2 = (hashA2 * 73 + A[i]) % 100021;



  if (i != 0)

   P1 = (P1 * 73) % 100007,

   P2 = (P2 * 73) % 100021;

 }

 if (NA > NB)

 {

  printf("0\n");

  return 0;

 }

 int hash1 = 0, hash2 = 0;

 for (int i = 0; i < NA; i++)

  hash1 = (hash1 * 73 + B[i]) % 100007,

  hash2 = (hash2 * 73 + B[i]) % 100021;

 int Nr = 0;

 if (hash1 == hashA1 && hash2 == hashA2)

  match[0] = 1, Nr++;

 for (int i = NA; i < NB; i++)

 {

  hash1 = ((hash1 - (B[i - NA] * P1) % 100007 + 100007) * 73 + B[i]) % 100007;

  hash2 = ((hash2 - (B[i - NA] * P2) % 100021 + 100021) * 73 + B[i]) % 100021;



  if (hash1 == hashA1 && hash2 == hashA2)

   match[ i - NA + 1 ] = 1, Nr++;

 }

 printf("%d\n", Nr);

 Nr = 0;

 for (int i = 0; i < NB && Nr < 1000; i++)

  if (match[i])

   Nr++,

   printf("%d ", i);

 printf("\n");



 return 0;

}
