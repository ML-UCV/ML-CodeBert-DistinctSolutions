#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

struct node {
  int first; int second;
  int nxt;
} physical[MAXM];
int nodecounter = 0;

int linsert(int l, int f, int s) {
  physical[nodecounter].first = f;
  physical[nodecounter].second = s;
  physical[nodecounter].nxt = l;
  return (nodecounter++);
}

const int MAXN = 30010;
int G[MAXN];
int dst[MAXN];
int S[MAXN], ssz;

void DFS(int nod, int tar) {
  ssz = 0;
  S[ssz++] = nod;
  dst[nod] = 0;
  while (ssz) {
    int x = S[--ssz];
    for (register int itt = G[x]; itt != -1; itt = physical[itt].nxt) {
      register node *it = &physical[itt];
      if (dst[it->first] != INT_MAX)
        continue;
      dst[it->first] = dst[x] + it->second;
      if (it->first == tar)
        return;
      S[ssz++] = it->first;
    }
  }
}

int main() {
  assert(freopen(InFile, "r", stdin));
  assert(freopen(OuFile, "w", stdout));
  parseInit();
  int N, X, Y;
  register int M;
  N = nextInt(); M = nextInt(); X = nextInt(); Y = nextInt();
  for (int i = 0; i < N; ++i)
    dst[i] = INT_MAX;
  --X, --Y;
  if (X > Y)
    swap(X, Y);
  memset(G, 0xFF, sizeof(G));
  while (M--) {
    register int a, b, c;
    a = nextInt(); b = nextInt(); c = nextInt();
    --a, --b;
    if (a > b)
      swap(a, b);
    G[a] = linsert(G[a], b, c);
    G[b] = linsert(G[b], a, -c);
  }
  DFS(X, Y);
  printf("%d\n", dst[Y]);
  return 0;
}
