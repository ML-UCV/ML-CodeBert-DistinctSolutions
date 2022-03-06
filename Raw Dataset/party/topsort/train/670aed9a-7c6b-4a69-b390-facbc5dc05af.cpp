#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;



const int kMaxNodes = 205;



ifstream fin("party.in");

ofstream fout("party.out");



int N;

vector<int> g[kMaxNodes];

vector<int> gt[kMaxNodes];



bool use[kMaxNodes];

stack<int> st;



bitset<kMaxNodes> val;



int Not(int x) {

  if (x > N) return x - N;

  return x + N;

}



void AddEdge(int x, int y) {

  g[x].push_back(y);

  gt[y].push_back(x);

}



void Init() {

  int M;

  fin >> N >> M;

  while (M--) {

    int x, y, t;

    fin >> x >> y >> t;

    if (t & 1) y = Not(y);

    if (t & 2) x = Not(x);

    AddEdge(Not(x), y);

    AddEdge(Not(y), x);

  }

}



void SortDfs(int node) {

  use[node] = true;

  for (int i : g[node])

    if (!use[i])

      SortDfs(i);

  st.push(node);

}



void SolveDfs(int node) {

  use[node] = true;

  if (node > N)

    val[Not(node)] = true;

  for (int i : gt[node])

    if (!use[i])

      SolveDfs(i);

}



void Solve() {

  for (int i = 1; i <= 2 * N; ++i)

    if (!use[i])

      SortDfs(i);

  memset(use, 0, sizeof use);

  while (!st.empty()) {

    int node = st.top();

    st.pop();

    if (!use[node] && !use[Not(node)])

      SolveDfs(node);

  }

}



void Print() {

  fout << val.count() << "\n";

  for (int i = 1; i <= N; ++i)

    if (val[i])

      fout << i << "\n";

}



int main() {

  Init();

  Solve();

  Print();

  return 0;

}
