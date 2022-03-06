#include <bits/stdc++.h>
using namespace std;


int M, N;
char A[2000005], B[2000005];
int pi[2000005], pos[1024];


void make_prefix(void)
{
 int i, q = 0;
    pi[1] = 0;
 for (i = 2, pi[1] = 0; i <= M; ++i) {
  while (q && A[q+1] != A[i])
   q = pi[q];

  if (A[q+1] == A[i])
   ++q;

  pi[i] = q;
 }
}



int main() {
 int i, q = 0, count = 0;

    ifstream fin("strmatch.in");
    ofstream fout("strmatch.out");

    fin.getline(A, 2000005);
    fin.getline(B, 2000005);

    M = strlen(A);
    N = strlen(B);

 for (i = M; i; i--)
        A[i] = A[i-1];
    A[0] = ' ';

    for (i = N; i; i--)
        B[i] = B[i-1];
    B[0] = ' ';

 make_prefix();

 for (i = 1; i <= N; i++) {
  while (q && A[q+1] != B[i])
   q = pi[q];

  if (A[q+1] == B[i])
   ++q;

  if (q == M) {
   q = pi[M];
   count++;
   if (count <= 1000)
    pos[count] = i - M;
  }
 }

 fout << count << "\n";

 for (i = 1; i <= min(count, 1000); i++)
        fout << pos[i] << " ";

 fout << "\n";



 return 0;

}
