#include <stdio.h>
#include <string.h>





char A[50000 + 2], B[50000 + 2];

int next[50000];
int c[26];

int P[50000];
int tmp[50000];
int n;


inline int mergeCount(int left, int right) {
  int i, j, k;
  int mid = (left + right) / 2;
  int cnt = 0;

  i = left;
  j = mid + 1;
  k = left;
  while (i <= mid && j <= right) {
    if (P[i] < P[j]) {
      tmp[k] = P[i];
      i++;
    } else {
      cnt += (mid - i + 1);
      tmp[k] = P[j];
      j++;
    }
    k++;
  }
  while (i <= mid) {
    tmp[k++] = P[i];
    i++;
  }
  while (j <= right) {
    tmp[k++] = P[j];
    j++;
  }
  memcpy(P + left, tmp + left, (right - left + 1) << 2);
  return cnt;
}

int inversionCount(int left, int right) {
  if (left >= right) {
    return 0;
  }
  int mid = (left + right) >> 1;
  int invCount = inversionCount(left, mid) + inversionCount(mid + 1, right);
  invCount += mergeCount(left, right);
  return invCount;
}

int main(void) {
  FILE *f = fopen("swap.in", "r");
  int pos, character;

  fgets(A, 50000 + 2, f);
  fgets(B, 50000 + 2, f);
  fclose(f);

  n = strlen(A) - 1;


  for (int i = 0; i < 26; i++) {
    c[i] = -1;
  }

  for (int i = n - 1; i >= 0; i--) {
    character = A[i] - 'a';
    next[i] = c[character];
    c[character] = i;
  }




  pos = 0;
  do {
    character = B[pos] - 'a';
    P[pos] = c[character];
    c[character] = next[c[character]];
    pos++;
  } while ((pos < n) && (P[pos - 1] != -1));

  f = fopen("swap.out", "w");
  if (pos != n || P[n - 1] == -1) {
    fputs("-1\n", f);
  } else {
    fprintf(f, "%d\n", inversionCount(0, n - 1));
  }
  fclose(f);
  return 0;
}
