#include <stdio.h>
#include <vector>

using namespace std;

const int NMAX = 250005;
const int LMAX = 20;

int N, M;
int T[LMAX][NMAX];

int main() {
   freopen("stramosi.in", "r", stdin);
   freopen("stramosi.out", "w", stdout);

   scanf("%d%d", &N, &M);

   for (int i = 1; i <= N; ++i) {
      scanf("%d", &T[0][i]);
   }

   for (int k = 1; (1 << k) <= N; ++k) {
      for (int i = 1; i <= N; ++i) {
         T[k][i] = T[k-1][T[k-1][i]];
      }
   }

   for (int i = 0; i < M; ++i) {
      int q,p;
      scanf("%d%d", &q, &p);

      for (int k = 17; k >= 0 && p; --k) {
         if ((p >> k) % 2 == 1) {
            q = T[k][q];
         }
      }
      printf("%d\n", q);
   }

   fclose(stdin);
   fclose(stdout);
   return 0;
}
