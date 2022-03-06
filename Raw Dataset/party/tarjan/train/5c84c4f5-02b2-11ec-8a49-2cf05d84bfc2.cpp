#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

const int NMAX = 100;
const int NIL = -1;

vector<int> G[2 * NMAX];
int idx[2 * NMAX], stk[2 * NMAX];
bool onStack[2 * NMAX];

vector<int> component[2 * NMAX];
int numComponents;

bool value[2 * NMAX];

int tarjan(const int& node) {
 static int idxPtr, ss;
 int minPtr = idx[node] = idxPtr++;

 stk[ss++] = node;
 onStack[node] = true;

 for (const int& adj: G[node]) {
  if (idx[adj] == NIL) {
   minPtr = min(minPtr, tarjan(adj));
  } else if (onStack[adj]) {
   minPtr = min(minPtr, idx[adj]);
  }
 }

 if (idx[node] == minPtr) {
  int v;
  do {
   v = stk[--ss];
   onStack[v] = false;
   component[numComponents].push_back(v);
  } while (v != node);
  numComponents++;
 }
 return minPtr;
}

int main() {
 ifstream cin("party.in");
 ofstream cout("party.out");
 cin.tie(0);
 ios_base::sync_with_stdio(false);

 int n, m; cin >> n >> m;
 for (int i = 0; i < m; i++) {
  int x, y, type; cin >> x >> y >> type; x--; y--;
  x <<= 1; y <<= 1;
  x |= ((type >> 1) & 1);
  y |= (type & 1);

  G[x ^ 1].push_back(y);
  G[y ^ 1].push_back(x);
 }
 cin.close();

 memset(idx, NIL, sizeof idx);
 for (int i = 0; i < 2 * n; i++) {
  if (idx[i] == NIL) {
   tarjan(i);
  }
 }

 for (int i = numComponents - 1; i >= 0; i--) {
  if (not value[component[i].front()]) {
   for (const int& node: component[i]) {
    value[node ^ 1] = true;
   }
  }
 }

 int solutionSize = 0;
 for (int i = 0; i < n; i++) {
  solutionSize += value[2 * i];
 }
 cout << solutionSize << '\n';
 for (int i = 0; i < n; i++) {
  if (value[2 * i]) {
   cout << 1 + i << '\n';
  }
 }
 cout.close();
}
