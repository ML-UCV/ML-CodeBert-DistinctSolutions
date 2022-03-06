#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <queue>
#include <stack>




using std::cin;
using std::cout;

template <typename T, typename C = T>
struct Node {
    T node;
    Node *next;
    C weight;
};

template <typename T, size_t N, size_t M>
class Graph {
public:
    size_t size;

    void add(const T& x, const T& y) {
        _nodes[++size].node = y;
        _nodes[size].next = _list[x];
        _list[x] = &_nodes[size];
    }

    void add_weighted(const T& x, const T& y, const T& weight) {
        _nodes[++size].node = y;
        _nodes[size].weight = weight;
        _nodes[size].next = _list[x];
        _list[x] = &_nodes[size];
    }

    Node<T>& get_node(const T& x) {
        return *_list[x];
    }

    bool visited(const T& x) {
        return _visited[x];
    }

    void visit(const T& x) {
        _visited[x] = true;
    }

    void reset() {
        for (auto &it : _visited) it = false;
    }
private:
    std::array<Node<T>, M> _nodes;
    std::array<Node<T>*, N> _list;

    std::array<bool, N> _visited;
};

std::vector<int> s;

template <typename T, size_t N, size_t M, typename Container>
void top_sort(Graph<T, N, M>& g, const T& x, Container& c) {
    g.visit(x);

    Node<T>* p = &g.get_node(x);

    while (p) {
        if (!g.visited(p->node))
            top_sort(g, p->node, c);
        p = p->next;
    }

    c.push_back(x);
}

Graph<int, 1 + 100000, 1 + 200000> g, d;
std::vector<std::vector<int>> f;

int main(int argc, char const *argv[])
{
    std::ifstream fin("ctc.in");
    std::ofstream fout("ctc.out");

    int n, m, x, y;

    fin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        fin >> x >> y;
        g.add(x, y);
        d.add(y, x);
    }

    for (int i = 1 ; i <= n ; i++)
        if (!g.visited(i)) top_sort(g, i, s);

    for (auto i = s.rbegin() ; i != s.rend() ; i++) {
        if (!d.visited(*i)) {
            f.push_back(std::vector<int>());
            top_sort(d, *i, f.back());
        }
    }

    fout << f.size() << '\n';
    for (const auto& it : f) {
        for (const auto& vf : it)
            fout << vf << ' ';
        fout << '\n';
    }
    return 0;
}
