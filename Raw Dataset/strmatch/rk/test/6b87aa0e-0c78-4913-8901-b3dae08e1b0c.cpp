#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;



const int MOD = 1000000007;

const int MAX_LENGTH = 2000000;

const int BASE = 62;



char s1[MAX_LENGTH + 5];

char s2[MAX_LENGTH + 5];

int p;



int code(char ch) {

  if (ch >= 'a' && ch <= 'z') {

    return ch - 'a' + 1;

  } else if (ch >= 'A' && ch <= 'Z') {

    return 26 + ch - 'A' + 1;

  } else {

    return 52 + ch - '0' + 1;

  }

}



int remove_first(int h, char ch) {

  int newH;

  newH = h - (1LL * p * code(ch)) % MOD;

  if (newH < 0)

    newH += MOD;

  return newH;

}



int add(int h, char ch) {

  return (1LL * h * BASE + code(ch)) % MOD;

}



int main() {

  freopen("strmatch.in", "r", stdin);

  freopen("strmatch.out", "w", stdout);



  int n, m;

  scanf("%s\n%s", s1, s2);

  n = strlen(s1);

  m = strlen(s2);



  if (n > m) {

    printf("0\n");

    return 0;

  }



  int h1;

  h1 = 0;

  for (int i = 0; i < n; i++)

    h1 = add(h1, s1[i]);



  int h2;

  h2 = 0;

  for (int i = 0; i < n; i++)

    h2 = add(h2, s2[i]);



  p = 1;

  for (int i = 1; i <= n - 1; i++)

    p = (1LL * p * BASE) % MOD;



  int ans;

  vector<int> sol;

  ans = 0;

  if (h1 == h2) {

    sol.push_back(0);

    ans++;

  }

  for (int i = n; i < m; i++) {

    h2 = remove_first(h2, s2[i - n]);

    h2 = add(h2, s2[i]);

    if (h1 == h2) {

      ans++;

      if (sol.size() < 1000)

        sol.push_back(i - n + 1);

    }

  }



  printf("%d\n", ans);

  for (auto it : sol)

    printf("%d ", it);

  printf("\n");



  return 0;

}
