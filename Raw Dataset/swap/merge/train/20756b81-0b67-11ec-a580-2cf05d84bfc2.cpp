#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;



long ind[2][30], a[50010], A[50010], i, j, k, len, sol;
vector<long> v[30];
char cuv[2][50010];

void baga_arbore(long li, long ls) {
 long mid;
 if (li >= ls) {
  return;
 }
 mid = (li + ls) >> 1;
 baga_arbore(li, mid);
 baga_arbore(mid + 1, ls);
 i = li;
 j = mid + 1;
 k = li - 1;
 while (i <= mid && j <= ls) {
  if (a[i] < a[j]) {
   A[++k] = a[i++];
  } else {
   sol += (mid - i + 1);
   A[++k] = a[j++];
  }
 }
 if (i <= mid) {
  for (j = i; j <= mid; ++j) {
   A[++k] = a[j];
  }
 } else {
  for (i = j; i <= ls; ++i) {
   A[++k] = a[i];
  }
 }
 for (i = li; i <= ls; ++i) {
  a[i] = A[i];
 }
}

int main() {
 freopen("swap.in", "r", stdin);
 freopen("swap.out", "w", stdout);
 fgets(cuv[0] + 1, 50010, stdin);
 fgets(cuv[1] + 1, 50010, stdin);
 len = strlen(cuv[0] + 1) - 1;
 for (i = 1; i <= len; ++i) {
  ++ind[1][cuv[1][i] - 'a'];
  v[cuv[1][i] - 'a'].push_back(i);
 }
 for (i = 1; i <= len; i++) {
  ++ind[0][cuv[0][i] - 'a'];
  if (ind[0][cuv[0][i] - 'a'] > ind[1][cuv[0][i] - 'a']) {
   printf("-1\n");
   return 0;
  }
  a[i] = v[cuv[0][i] - 'a'][ind[0][cuv[0][i] - 'a'] - 1];
 }
 baga_arbore(1, len);
 printf("%ld\n", sol);
 return 0;
}
