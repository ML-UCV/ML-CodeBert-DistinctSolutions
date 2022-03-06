#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <vector>




char buffer[2 * 50000 + 2];
std::vector <int> position[26];
int start[26];

int P[50000];
int tmp[50000];

int n;

inline int mergeCount(int left, int mid, int right) {
  int invCount = 0;
  int i, j, k;

  i = left;
  j = mid + 1;
  k = left;
  while (i <= mid && j <= right) {
    if (P[i] <= P[j]) {
      tmp[k++] = P[i++];
    } else {
      tmp[k++] = P[j++];
      invCount += (mid - i + 1);
    }
  }
  while (i <= mid) {
    tmp[k++] = P[i++];
  }
  while (j <= right) {
    tmp[k++] = P[j++];
  }
  for (i = left; i <= right; i++)
    P[i] = tmp[i];
  return invCount;
}

int inversionCount(int left, int right) {
  if (left >= right) {
    return 0;
  }
  int mid = (left + right) / 2;
  int invCount = inversionCount(left, mid) + inversionCount(mid + 1, right);
  invCount += mergeCount(left, mid, right);
  return invCount;
}

int main(void) {
  FILE *f = fopen("swap.in", "r");
  int ptr = 0;
  int character;

  fread(buffer, 1, 2 * 50000 + 2, f);
  fclose(f);

  do {
    character = buffer[ptr] - 'a';
    position[character].emplace_back(ptr);
  } while (isalpha(buffer[++ptr]));

  ptr++;
  n = 0;

  do {
    character = buffer[ptr] - 'a';
    if (start[character] < (int) position[character].size()) {
      P[n++] = position[character][start[character]++];
    } else {
      n = -1;
    }
  } while ((~n) && (isalpha(buffer[++ptr])));

  f = fopen("swap.out", "w");
  if (~n) {
    fprintf(f, "%d\n", inversionCount(0, n - 1));
  } else {
    fputs("-1\n", f);
  }
  fclose(f);
  return 0;
}
