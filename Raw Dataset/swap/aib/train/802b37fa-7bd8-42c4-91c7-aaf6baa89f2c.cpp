#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>



const int MAX_LENGTH = 50000;
const int SIGMA = 26;

int n;

class FenwickTree {
public:
  int a[1 + MAX_LENGTH];

  FenwickTree() {
    memset(a, 0, sizeof(a));
  }

  void update(int poz, int val) {
    for (int i = poz; i <= n; i += i & -i) {
      a[i] += val;
    }
  }

  int query(int poz) {
    int ans = 0;
    for (int i = poz; i >= 1; i -= i & -i) {
      ans += a[i];
    }
    return ans;
  }

  int query(int st, int dr) {
    return query(dr) - query(st - 1);
  }
};

int f1[SIGMA], f2[SIGMA];

int main() {
  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);

  char s1[MAX_LENGTH + 1], s2[MAX_LENGTH + 1];
  scanf("%s%s", s1, s2);
  if (strlen(s1) != strlen(s2)) {
    printf("-1");
    return 0;
  }
  n = (int)strlen(s1);
  std::queue<int> poz[SIGMA];
  for (int i = 0; i < n; i++) {
    f1[s1[i] - 'a']++;
    f2[s2[i] - 'a']++;
    poz[s1[i] - 'a'].push(i + 1);
  }
  for (char alph = 'a'; alph <= 'z'; alph++) {
    if (f1[alph - 'a'] != f2[alph - 'a']) {
      printf("-1");
      return 0;
    }
  }
  FenwickTree t;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int index = poz[s2[i] - 'a'].front();
    poz[s2[i] - 'a'].pop();
    ans += index - i - 1 + t.query(index + 1, n);
    t.update(index, 1);
  }
  printf("%d\n", ans);
  return 0;
}
