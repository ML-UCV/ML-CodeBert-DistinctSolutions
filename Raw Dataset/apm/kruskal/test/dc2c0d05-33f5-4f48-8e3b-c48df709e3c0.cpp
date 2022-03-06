#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> daddy;
vector<int> height;

class Edge{
 public:
  Edge(int x, int y, int c):x_(x), y_(y), cost_(c){}
  int from() const {return x_;}
  int to() const {return y_;}
  int cost() const {return cost_;}
  bool operator<(const Edge& other) {return cost() < other.cost();}
 private:
  int x_, y_, cost_;
};

int find_parent(int k)
{
  if (daddy[k] != k)
    daddy[k] = find_parent(daddy[k]);
  return daddy[k];
}

int Union(int x, int y)
{
  x = find_parent(x);
  y = find_parent(y);

  if (height[x] > height[y])
    swap(x,y);

  if (height[x] == height[y])
    ++height[y];

  daddy[x] = y;
}


int main()
{
  freopen("apm.in", "r", stdin);
  freopen("apm.out", "w", stdout);

  vector<Edge> edges, selected;

  int N, M;
  scanf("%d%d", &N, &M);
  daddy.resize(N);
  height.resize(N);
  for (int i = 0; i < N; ++i)
    daddy[i] = i;

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a; --b;
    edges.emplace_back(a, b, c);
  }

  sort(edges.begin(), edges.end());
  long long answer = 0;
  for (auto e : edges) {
    if (find_parent(e.from()) != find_parent(e.to())) {
      selected.emplace_back(e);
      Union(e.from(), e.to());
      answer += e.cost();
    }
  }
  printf("%lld\n%d\n", answer, (int)selected.size());
  for (auto e : selected)
    printf("%d %d\n", e.from() + 1, e.to() + 1);
  return 0;
}
