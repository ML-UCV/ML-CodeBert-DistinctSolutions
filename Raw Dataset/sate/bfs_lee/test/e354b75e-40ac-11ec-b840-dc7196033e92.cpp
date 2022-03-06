//
//  main.cpp
//  sate
//
//  Created by Ciprian Ionescu on 1/16/20.
//  Copyright Â© 2020 Ciprian Ionescu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <array>
#include <queue>

#define MAX_N 300001
#define MAX_M 1000025

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

template <typename T, size_t N, size_t M>
void dfs(Graph<T, N, M>& g, const T& x) {
    g.visit(x);
    
    Node<T>* p = &g.get_node(x);
    
    while (p) {
        if (!g.visited(p->node))
            dfs(g, p->node);
        p = p->next;
    }
}

int d[MAX_N];

template <typename T, size_t N, size_t M>
T bfs(Graph<T, N, M>& g, const T& x, const T& y, std::queue<T>& q) {
    for (q.push(x) ; !q.empty() ; q.pop()) {
        g.visit(q.front());
        
        for (auto p = &g.get_node(q.front()) ; p ; p = p->next) {
            if (g.visited(p->node)) continue;
            
            q.push(p->node);
            if (p->node > q.front())
                d[p->node] = d[q.front()] + p->weight;
            else
                d[p->node] = d[q.front()] - p->weight;
            
            if (p->node == y) return d[p->node];
        }
    }
    
    return 0;
}

Graph<int, MAX_N, MAX_M> g;

using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    
    std::ifstream fin("sate.in");
    std::ofstream fout("sate.out");
    
    int n, m, x, y, a, b, d;
    std::queue<int> q;
    fin >> n >> m >> x >> y;
    
    for (auto i = 1 ; i <= m ; i++) {
        fin >> a >> b >> d;
        g.add_weighted(a, b, d);
        g.add_weighted(b, a, d);
    }
    
    fout << bfs(g, x, y, q);
    return 0;
}
