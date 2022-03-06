#include <iostream>
#include <fstream>
#include <queue>
#include <set>

using namespace std;
const int size = 200001;
ifstream fin("apm.in");
ofstream fout("apm.out");
priority_queue<int, vector<pair<int, int>>,greater<pair<int, int>>> heap;
vector<pair<int, int>> a[size];
set<int> rez;
int d[size], tata[size], isInHeap[size];

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        d[i] = 20000000;
        tata[i] = 0;
        isInHeap[i] = 1;
    }
}

int main() {
    int i, n, m, x, y, c, sum = 0;
    fin >> n >> m;
    init(n);
    for(i = 1; i <= m; ++i) {
        fin >> x >> y >> c;
        a[x].push_back(make_pair(y, c));
        a[y].push_back(make_pair(x, c));
    }
    d[1] = 0;
    for(i = 1; i <= n; ++i)
        heap.push(make_pair(d[i], i));
    while(!heap.empty() && heap.top().first != 20000000) {
        pair<int, int> p = heap.top();
        heap.pop();
        int u = p.second;
        if(u != 1 && rez.find(u) == rez.end()){ sum += d[u]; rez.insert(u);}
        isInHeap[u] = 0;
        for(auto v:a[u]) {
            if(isInHeap[v.first] == 1 && v.second < d[v.first]) {
                d[v.first] = v.second;
                tata[v.first] = u;
                heap.push(make_pair(d[v.first], v.first));
            }
        }
    }
    fout << sum << "\n" << rez.size() <<" \n";
    for(auto x:rez)
        fout << x << " " << tata[x] << "\n";
    return 0;
}
