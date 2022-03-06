#include <stdio.h>
#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("ctc.in");
ofstream fout ("ctc.out");

const int Nmax = 100555;
int counter = 0;
int ind[Nmax], lowkey[Nmax];
stack<int> st;
char inStack[Nmax];
vi G[Nmax];
int ans = 0;
vector<vi> ctc;

void dfs(int nod) {
  if (ind[nod] != INF) { return; }

  ind[nod] = lowkey[nod] = ++counter;
  st.push(nod); inStack[nod] = 1;
  for(auto y: G[nod]) {
    if (ind[y] == INF) {
      dfs(y);
    }
    if (inStack[y]) {
      lowkey[nod] = min(lowkey[nod], lowkey[y]);
    }
  }
  if (ind[nod] == lowkey[nod]) {
    ctc.resize(++ans);
    vi &comp = ctc.back();
    while(!st.empty()) {
      int x = st.top(); st.pop();
      inStack[x] = 0;
      comp.push_back(x);
      if (x == nod) {
        break;
      }
    }
  }
}

int main(void) {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  memset(ind, 0x3f, sizeof(ind));
  memset(lowkey, 0x3f, sizeof(ind));
  int N, M, a, b;
  fin >> N >> M;
  for(int i = 0; i < (int)(M); i++) {
    fin >> a >> b;
    --a, --b;
    G[a].push_back(b);
  }
  for(int i = 0; i < (int)(N); i++) {
    if (ind[i] == INF) {
      dfs(i);
    }
  }
  fout << ans << '\n';
  for(const auto& comp: ctc) {
    for(auto x: comp) {
      fout << x+1 << " ";
    }
    fout << '\n';
  }

  return 0;
}
