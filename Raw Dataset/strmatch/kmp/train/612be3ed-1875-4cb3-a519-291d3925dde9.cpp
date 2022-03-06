#include <stdio.h>
#include <vector>
#include <string.h>


using namespace std;





char A[2000001], B[2000001];

int pi[2000001];

void MakePi(char* A, int leng, int pi[]) {

 pi[0] = 0;

 int lasti = 0;

 int i = 1;



 while (i < leng) {

  if (A[lasti] == A[i]) {

   pi[i++] = ++lasti;

  }

  else {

   if (lasti != 0)

    lasti = pi[lasti - 1];

   else

    pi[i++] = 0;

  }

 }

}



int main()

{

 int nr = 0;



 vector<int> ind;

 freopen("strmatch.in", "rt", stdin);

 freopen("strmatch.out", "wt", stdout);

 scanf("%s %s", A, B);

 int M = strlen(A);

 int N = strlen(B);

 MakePi(A, M, pi);

 if (M > N)

 {

  {

   printf("0\n");

   return 0;

  }

 }

 int j = 0;



 int i = 0;

 while (i < N) {

  if (A[j] == B[i]) {

   j++;

   i++;

  }

  if (j == M) {

   nr++;

   ind.push_back(i - M);

   j = pi[j - 1];

  }

  else if (i < N && A[j] != B[i]) {

   if (j != 0)

    j = pi[j - 1];

   else

    i++;

  }

 }

 printf("%d\n", nr);

 for (int i = 0; i < ((ind.size() < 1000) ? ind.size() : 1000); i++) {

  printf("%d ", ind[i]);

 }

 return 0;

}
