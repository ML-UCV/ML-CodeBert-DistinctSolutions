#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct node{
    int value, depth;
    node *parent;

    node(int v, int d, node *p = nullptr){
        this->value = v;
        this->depth = d;
        this->parent = p;
    }
    node* root(){
        if(this->parent == nullptr) return this;
        this->parent = this->parent->root();
        return this->parent;
    }

};

struct edge{
    int x, y, cost;
    edge(int d1, int d2, int c){
        this->x = d1;
        this->y = d2;
        this->cost = c;
    }
    bool operator< (const edge &other) const {
        return this->cost > other.cost;
    }
};

bool query(node* x, node* y){
    return (x->root() == y->root());
}

void update(node* x, node* y){
    if(x->depth < y->depth) x->root()->parent = y;
    else if(x->depth > y->depth) y->root()->parent = x;
    else{
        x->depth++, y->depth++;
        x->root()->parent = y;
    }
}
int main() {
    int n, m;
    ifstream f("apm.in");
    ofstream g("apm.out");
    f>>n>>m;
    vector<node*> nodes;
    nodes.reserve(n);
    priority_queue<edge> edges;
    for (int i = 0; i < n; ++i) {
        nodes.push_back(new node(i, 1, nullptr));
    }
    for (int i = 0; i < m; ++i) {
        int x, y, o;
        f>>x>>y>>o;
        edges.push(edge(x - 1, y - 1, o));
    }

    int totalCost = 0;
    vector<pair<int, int>> result;
    result.reserve(n - 1);
    while(!edges.empty()){
        edge t = edges.top();
        edges.pop();
        if(!query(nodes[t.x], nodes[t.y])){
            update(nodes[t.x], nodes[t.y]);
            totalCost += t.cost;
            result.push_back(make_pair(t.x, t.y));
        }
    }
    g<<totalCost<<'\n'<<n - 1<<'\n';
    for (int i = 0; i < n - 1; ++i) {
        g<<result[i].first + 1<<' '<<result[i].second + 1<<'\n';
    }
    return 0;
}
