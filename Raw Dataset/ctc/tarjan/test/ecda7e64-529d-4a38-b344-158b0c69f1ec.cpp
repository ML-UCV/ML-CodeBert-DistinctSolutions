#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream fi ("ctc.in");

ofstream fo ("ctc.out");

int n, m, a, b, idx, cnt;

stack <int> s;

vector <int> ctc[100001];

class Node {

 public:

  bool stack = false;

  int idx = -1, low;

  vector <int> edges;



  void addNode(int x) {

   edges.push_back(x);

  }

} v[100001];



void connect_component(int x) {

 v[x].idx = v[x].low = ++idx;

 v[x].stack = true;

 s.push(x);

 for (auto i:v[x].edges) {

  if (v[i].idx == -1) {

   connect_component(i);

   v[x].low = min(v[x].low, v[i].low);

  } else if (v[i].stack && v[i].idx < v[x].idx) {

   v[x].low = min(v[x].low, v[i].idx);

  }

 }

 if (v[x].idx == v[x].low) {

  while (1) {

   a = s.top();

   s.pop();

   ctc[cnt].push_back(a);

   v[a].stack = false;

   if (a == x)

    break;

  }

  ++cnt;

 }

}



int main() {

 fi >> n >> m;

 for (int i = 1; i <= m; ++i) {

  fi >> a >> b;

  v[a].addNode(b);

 }

 for (int i = 1; i <= n; ++i)

  if (v[i].idx == -1)

   connect_component(i);

 fo << cnt << '\n';

 for (int i = 0; i < cnt; ++i)

  for (auto j:ctc[i])

   fo << j << " \n"[j==ctc[i].back()];

 return 0;

}
