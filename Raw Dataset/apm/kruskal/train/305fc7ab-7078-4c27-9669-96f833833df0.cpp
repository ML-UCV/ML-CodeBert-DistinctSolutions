#include <bits/stdc++.h>

using namespace std;

ifstream in("apm.in");
ofstream out("apm.out");

class UnionFind
{
  int size;


  int *sz;


  int *id;

public:
  UnionFind(int size)
  {
    size = size;

    sz = new int[size];
    id = new int[size];

    for (int i = 0; i < size; i++)
    {

      id[i] = i;
      sz[i] = 1;
    }
  }


  int find(int p)
  {
    int root = p;
    while (id[root] != root)
    {
      root = id[root];
    }


    while (p != root)
    {
      int next = id[p];
      id[p] = root;
      p = next;
    }

    return root;
  }

  bool connected(int p, int q)
  {

    return find(p) == find(q);
  }

  void unify(int p, int q)
  {
    int root1 = find(p);
    int root2 = find(q);


    if (root1 == root2)
      return;


    if (sz[root1] > sz[root2])
    {
      id[root2] = root1;
      sz[root1] += sz[root2];
    }
    else
    {
      id[root1] = root2;
      sz[root2] += sz[root1];
    }
  }
};

template <typename T>
struct triplet
{
  T from, to, cost;
};

template <typename T>
triplet<T> make_triplet(const T &m1, const T &m2, const T &m3)
{
  triplet<T> ans;
  ans.from = m1;
  ans.to = m2;
  ans.cost = m3;
  return ans;
}

const int VMAX = 200001;
vector<triplet<int>> edges;
int v, e;


pair<int, int> rez[VMAX - 1];
int mstCost = 0;

bool cmp(triplet<int> a, triplet<int> b)
{
  return a.cost < b.cost;
}

int main()
{
  in >> v >> e;
  for (int i = 0; i < e; i++)
  {
    int from, to, cost;
    in >> from >> to >> cost;

    edges.push_back(make_triplet(from, to, cost));
  }

  sort(edges.begin(), edges.end(), cmp);

  UnionFind u(v + 1);
  int edge_count = 0;
  for (auto edge : edges)
  {
    if (edge_count == v - 1)
      break;
    if (!u.connected(edge.from, edge.to))
    {
      u.unify(edge.from, edge.to);
      rez[edge_count++] = make_pair(edge.from, edge.to);
      mstCost += edge.cost;
    }
  }

  out << mstCost << '\n';
  out << v - 1 << '\n';
  for (int i = 0; i < v - 1; i++)
  {
    out << rez[i].first << ' ' << rez[i].second << '\n';
  }
  return 0;
}
