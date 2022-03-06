#include <stdio.h>
#include <bits/stdc++.h>




using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("apm.in");
ofstream fout ("apm.out");

int root(vi &par, int x) {
  int rx = x;
  while(rx != par[rx]) { rx = par[rx]; }
  while(x != rx) {
    int i = par[x];
    par[x] = rx;
    x = i;
  }
  return rx;
}

int main(void) {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int N, M;
  fin >> N >> M;
  vi par(N);
  vector<pii> muchii(M);
  queue<int> used;

  for(int i = 0; i < (int)(N); i++) { par[i] = i; }

  priority_queue<pii, vector<pii>, greater<pii> > pq;
  int a, b, c;
  for(int i = 0; i < (int)(M); i++) {
    fin >> a >> b >> c;
    --a; --b;
    muchii[i] = {a, b};
    pq.push({c, i});
  }
  int cost = 0;
  while(!pq.empty()) {
    auto X = pq.top(); pq.pop();
    int c = X.first;
    pii much = muchii[X.second];
    int a = much.first;
    int b = much.second;

    int ra = root(par, a);
    int rb = root(par, b);
    if (ra == rb) {
      continue;
    } else {
      cost += c;
      used.push(X.second);
      par[ra] = par[rb] = min(ra, rb);
    }
  }
  fout << cost << '\n' << N-1 << '\n';
  while(!used.empty()) {
    pii much = muchii[used.front()]; used.pop();
    fout << much.first+1 << " " << much.second + 1 << '\n';
  }

  return 0;
}
