#include <bits/stdc++.h>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

const int NMAX = 100000, UNVISITED = -1;
vector<int> lst_ad[NMAX];
stack<int> st;
int n, m, ids[NMAX], lowLink[NMAX], id = 0, nr_ctc = 0;
bool onStack[NMAX];
string ctc = "";

void dfs(int curr)
{
  ids[curr] = lowLink[curr] = id++;
  st.push(curr);
  onStack[curr] = true;

  for (auto next : lst_ad[curr])
  {
    if (ids[next] == UNVISITED)
    {
      dfs(next);
    }


    if (onStack[next])
    {
      lowLink[curr] = min(lowLink[curr], lowLink[next]);
    }
  }


  if (ids[curr] == lowLink[curr])
  {
    nr_ctc++;
    int node;
    do
    {
      node = st.top();
      st.pop();
      onStack[node] = false;
      lowLink[node] = lowLink[curr];
      ctc += to_string(node + 1);
      ctc += " ";
    } while (node != curr);
    ctc += "\n";
  }
}

int main()
{
  in >> n >> m;
  for (int i = 0; i < n; i++)
  {
    ids[i] = UNVISITED;
  }
  for (int i = 0; i < m; i++)
  {
    int x, y;
    in >> x >> y;
    x--;
    y--;
    lst_ad[x].push_back(y);
  }

  for (int i = 0; i < n; i++)
  {
    if (ids[i] == UNVISITED)
    {
      dfs(i);
    }
  }
  out << nr_ctc << '\n';
  out << ctc;
  return 0;
}
