#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <climits>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#ifdef INFOARENA
#define ProblemName "sate"
#endif

#define MCONCAT(A, B) A B
#ifdef ProblemName
#define InFile MCONCAT(ProblemName, ".in")
#define OuFile MCONCAT(ProblemName, ".out")
#else
#define InFile "fis.in"
#define OuFile "fis.out"
#endif

const int MAXM = 200124;
const int MAXBUF = 10000010;
char parsebuf[MAXBUF], *head;
bool numeric[255];

void parseInit() {
  int off = fread(parsebuf, 1, MAXBUF, stdin);
  assert(off < MAXBUF - 10);
  parsebuf[off] = 0;
  head = parsebuf;
  memset(numeric, 0, sizeof(numeric));
  for (int i = '0'; i <= '9'; ++i)
    numeric[i] = true;
}

int nextInt() {
  for (; !numeric[*head]; ++head);
  int ans = 0;
  for (; numeric[*head]; ++head)
    ans = ans * 10 + (*head) - '0';
  return ans;
}

const int MAXN = 30010;
pii muchii[MAXM];
int offsetOf[MAXN];
int dst[MAXN];
int S[MAXN], ssz;

void DFS(int nod, int tar) {
  ssz = 0;
  S[ssz++] = nod;
  dst[nod] = 0;
  while (ssz) {
    int x = S[--ssz];
    for (register int itt = offsetOf[x], tarr = offsetOf[x + 1]; itt != tarr; ++itt) {
      register int v = muchii[itt].first;
      if (dst[v] != 0x3F3F3F3F)
        continue;
      dst[v] = dst[x] + muchii[itt].second;
      if (v == tar)
        return;
      S[ssz++] = v;
    }
  }
}

int main() {
  assert(freopen(InFile, "r", stdin));
  assert(freopen(OuFile, "w", stdout));
  parseInit();
  int N, M, X, Y;
  N = nextInt(); M = nextInt(); X = nextInt(); Y = nextInt();
  memset(dst, 0x3F, sizeof dst);
  if (X > Y)
    swap(X, Y);
  while (M--) {
    ++offsetOf[nextInt()];
    ++offsetOf[nextInt()];
    nextInt();
  }
  for (register int i = 1; i <= N; ++i)
    offsetOf[i] += offsetOf[i - 1];
  head = parsebuf;
  nextInt(); M = nextInt(); nextInt(); nextInt();
  offsetOf[N + 1] = 2 * M;
  while (M--) {
    register int a = nextInt(), b = nextInt(), c = nextInt();
    if (a > b) {
      muchii[--offsetOf[b]].first = a;
      muchii[offsetOf[b]].second = c;
      muchii[--offsetOf[a]].first = b;
      muchii[offsetOf[a]].second = -c;
    }
    else {
      muchii[--offsetOf[a]].first = b;
      muchii[offsetOf[a]].second = c;
      muchii[--offsetOf[b]].first = a;
      muchii[offsetOf[b]].second = -c;
    }
  }
  DFS(X, Y);
  printf("%d\n", dst[Y]);
  return 0;
}
