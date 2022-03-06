#include <bits/stdc++.h>

using namespace std;

ifstream in("apm.in");
ofstream out("apm.out");


template<typename T>
struct triplet
{
  T from, to, cost;
};

template<typename T>
triplet<T> make_triplet(const T &m1, const T &m2, const T &m3)
{
  triplet<T> ans;
  ans.from = m1;
  ans.to = m2;
  ans.cost = m3;
  return ans;
}

class Compare
{
public:
  bool operator() (triplet<int> t1, triplet<int> t2)
  {
  return (t1.cost > t2.cost);
  }
};

void Prims(int = 1);
void addEdges(int node);

const int VMAX = 200001, EMAX = 400001;
int v, e;
bool viz[VMAX];


vector<pair<int, int>> ad[VMAX];


priority_queue<triplet<int>, vector<triplet<int>>, Compare> pq;


pair<int, int> rez[VMAX-1];
int mstCost = 0;

int main()
{
  in >> v >> e;
  for(int i=0; i<e; i++)
  {
    int from, to, cost;
    in >> from >> to >> cost;
    ad[from].push_back(make_pair(to, cost));
    ad[to].push_back(make_pair(from, cost));

  }

  Prims();

  return 0;
}

void Prims(int start_node)
{
  int i= 0;
  addEdges(start_node);

  while(!pq.empty() && i != v - 1)
  {
    triplet<int> curr_edge = pq.top();
    pq.pop();
    if(!viz[curr_edge.to])
    {
      rez[i++] = make_pair(curr_edge.from, curr_edge.to);
      mstCost += curr_edge.cost;
      addEdges(curr_edge.to);
    }
  }

  out << mstCost << '\n';
  out << v - 1 << '\n';
  for(int i=0; i<v-1; i++)
  {
    out << rez[i].first << ' ' << rez[i].second << '\n';
  }
}

void addEdges(int node)
{
  viz[node] = true;
  for(auto edge : ad[node])
  {
    if(!viz[edge.first])
    {
      pq.push(make_triplet(node, edge.first, edge.second));
    }
  }
}
