#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

typedef pair<int, int> pii;
const int MAXN = 110;

template<class T> class jmenvect : public vector<T> {
public:
  T& operator[](int n) {
    if (n > 0)
      return this->at(n);
    else
      return this->at(-n + (this->size() >> 1));
  }
};

class graph {
private:
  vector< list<int> > adiac;
  vector< list<int> > neg_adiac;
public:
  graph();
  graph(int);
  int size();
  void newnod();
  void newedge(int, int);
  const list<int>& getList(int);
  void rev_DFS(int, jmenvect<int>&, jmenvect<int>&);
  bool SCC_DFS(int, int, jmenvect<int>&);
};

graph::graph() {
  adiac.reserve(MAXN);
  neg_adiac.reserve(MAXN);
}

graph::graph(int n) {
  adiac.resize(n + 1);
  neg_adiac.resize(n + 1);
}

int graph::size() {
  return adiac.size();
}

void graph::newnod() {
  neg_adiac.resize(size() + 1);
  adiac.resize(size() + 1);
}

void graph::newedge(int n1, int n2) {
  if (n1 > 0)
    adiac[n1].push_back(n2);
  else
    neg_adiac[-n1].push_back(n2);
}

const list<int>& graph::getList(int n) {
  if (n > 0)
    return adiac[n];
  else
    return neg_adiac[-n];
}

void graph::rev_DFS(int nod, jmenvect<int>& visited, jmenvect<int> &finished) {
  auto L = this->getList(-nod);
  visited[nod] = 1;
  for (auto i = L.begin(); i != L.end(); ++i)
    if (!visited[-(*i)])
      rev_DFS(-(*i), visited, finished);
  finished.push_back(nod);
}

bool graph::SCC_DFS(int curComp, int nod, jmenvect<int>& visited) {
  visited[nod] = curComp;
  auto L = this->getList(nod);
  for (auto i = L.begin(); i != L.end(); ++i) {
    if (!visited[*i]) {
      if (!SCC_DFS(curComp, *i, visited))
        return false;
    }
  }
  if (visited[-nod])
    return false;
  visited[-nod] = -curComp;
  return true;
}

pair<jmenvect<int>, int> korasaju(graph* G) {
  int N = G->size() - 1;
  jmenvect<int> visisted;
  visisted.resize((N << 1) + 1);
  jmenvect<int> finished;
  finished.reserve((N << 1) + 1);

  for (int i = 1; i <= N; i++) {
    if (!visisted[i])
      G->rev_DFS(i, visisted, finished);
    if (!visisted[-i])
      G->rev_DFS(-i, visisted, finished);
  }

  visisted.assign((N << 1) + 1, 0);
  int curComp = 0;
  for (auto i = finished.rbegin(); i != finished.rend() - 1; ++i) {
    curComp++;
    if (!visisted[*i]) {
      if (!G->SCC_DFS(curComp, *i, visisted)) {
        jmenvect<int> dummyvect;
        return{ dummyvect, 0 };
      }
    }
    else
      curComp--;
  }
  return{ visisted, curComp };
}



int main() {

  assert(freopen("fis.in", "r", stdin));

  assert(freopen("fis.out", "w", stdout));
  int N, M;
  scanf("%d%d", &N, &M);
  graph* G = new graph(N);
  for (int i = 0; i < M; i++) {
    int tip, a, b;
    scanf("%d%d%d", &a, &b, &tip);
    switch (tip) {
    case 0:
      break;
    case 1:
      b = -b;
      break;
    case 2:
      a = -a;
      break;
    default:
      a = -a;
      b = -b;
      break;
    }
    G->newedge(-a, b);
    G->newedge(-b, a);
  }
  pair<jmenvect<int>, int> p = korasaju(G);
  jmenvect<int>& SCC = p.first;
  if (!SCC.size()) {
    printf("-1\n");
    return 0;
  }
  int nrComp = p.second;
  jmenvect<char> cval;
  cval.resize((nrComp << 1) + 1);
  for (int i = 1; i <= nrComp; i++) {
    cval[-i] = 0;
    cval[i] = 1;
  }
  vector<int> sol;
  for (int i = 1; i <= N; i++) {
    if (cval[SCC[i]] == 1)
      sol.push_back(i);
  }
  printf("%d\n", (int)sol.size());

  for (const auto &it : sol)

    printf("%d\n", it);

  return 0;

}
