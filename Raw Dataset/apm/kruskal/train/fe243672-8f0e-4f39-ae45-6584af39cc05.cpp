#include<fstream>
#include<vector>
#include<algorithm>
#include<string>



class DisjointSet {
private:
    int n;
    std::vector<int> p = std::vector<int>(200000 + 1);
    std::vector<int> h = std::vector<int>(200000 + 1);
public:
    DisjointSet(int nr) {
        n = nr;
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
            h[i] = 1;
        }
    }

    int Find(int x) {
        int r, aux;
        r = x;
        while(p[r] != r)
            r = p[r];
        while(p[x] != r) {
            aux = p[x];
            p[x] = r;
            x = aux;
        }
        return r;
    }

    bool Union(int x, int y) {
        int rx, ry;
        rx = Find(x);
        ry = Find(y);
        if(rx != ry) {
            if(h[rx] < h[ry])
                p[rx] = ry;
            else if(h[rx] > h[ry])
                p[ry] = rx;
            else {
                p[rx] = ry;
                ++h[ry];
            }
            return true;
        } else return false;
    }

    ~DisjointSet() {
        p.clear();
        h.clear();
        p.shrink_to_fit();
        h.shrink_to_fit();
    }
};

class Edge {
private:
    int x;
    int y;
    int cost;
public:
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getCost() {
        return cost;
    }

    void setX(int X) {
        x = X;
    }

    void setY(int Y) {
        y = Y;

    }

    void setCost(int Cost) {
        cost = Cost;
    }
};

class CompareCost {
public:
    bool operator() (Edge& a, Edge& b) {
        return a.getCost() < b.getCost();
    }
};

class Graph {
private:
    int V;
    int E;
    std::vector<Edge>g;
public:
    void readGraph(std::string name_fin) {
        Edge p;
        int x, y, c;
        std::ifstream fin(name_fin);
        fin >> V >> E;
        for(int i = 0; i < E; ++i) {
            fin >> x >> y >> c;
            p.setX(x);
            p.setY(y);
            p.setCost(c);
            g.push_back(p);
        }
    }

    void sortEdges() {
        sort(g.begin(), g.end(), CompareCost());
    }

    void Kruskal() {
        std::ofstream fout("apm.out");
        DisjointSet ds(this->V);
        sortEdges();
        int i, nrEdges, apmCost;
        std::vector<std::pair<int, int>>apm;
        i = nrEdges = apmCost = 0;
        while(i < this->E && nrEdges < V - 1) {
            if(ds.Union(g[i].getX(), g[i].getY())) {
                apm.push_back(std::make_pair(g[i].getX(), g[i].getY()));
                apmCost += g[i].getCost();
                ++nrEdges;
            }
            ++i;
        }
        fout << apmCost << '\n' << nrEdges << '\n';
        for(auto i : apm)
            fout << i.first << " " << i.second << "\n";
        fout.close();
    }

    ~Graph() {
        g.clear();
        g.shrink_to_fit();
    }
};

int main() {
    Graph G;
    G.readGraph("apm.in");
    G.Kruskal();
    return 0;
}
