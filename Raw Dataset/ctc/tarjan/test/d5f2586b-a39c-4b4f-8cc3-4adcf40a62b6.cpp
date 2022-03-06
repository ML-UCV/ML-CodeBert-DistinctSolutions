#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream fi ("ctc.in");

ofstream fo ("ctc.out");

bool ins[100001];

int n, m, idx[100001], midx[100001], nodes, total, a, b;

stack <int> st;

vector <int> v[100001], ctc[100001];



void discover(int node) {

 idx[node] = midx[node] = ++nodes;

 ins[node] = true;

 st.push(node);

 for (auto i:v[node]) {

  if (!idx[i]) {

   discover(i);

   midx[node] = min(midx[node], midx[i]);

  } else if (ins[i]) {

   midx[node] = min(midx[node], idx[i]);

  }

 }

 if (idx[node] == midx[node]) {

  while (1) {

   a = st.top();

   st.pop();

   ctc[total].push_back(a);

   ins[a] = false;

   if (a == node)

    break;

  }

  ++total;

 }

}



int main() {

 fi >> n >> m;

 for (int i = 1; i <= m; ++i) {

  fi >> a >> b;

  v[a].push_back(b);

 }

 for (int i = 1; i <= n; ++i)

  if (!idx[i])

   discover(i);

 fo << total << '\n';

 for (int i = 0; i < total; ++i)

  for (auto j:ctc[i])

   fo << j << " \n"[j==ctc[i].back()];

 return 0;

}
