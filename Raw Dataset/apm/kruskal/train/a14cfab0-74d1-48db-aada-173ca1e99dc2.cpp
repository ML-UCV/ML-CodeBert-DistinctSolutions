#include <fstream>
#include <vector>
#include <algorithm>




using namespace std;





ifstream in("apm.in");

ofstream out("apm.out");





struct Edge {

    uint32_t node1;

    uint32_t node2;

    int16_t cost;

};





void Read(

    uint32_t &n,

    vector<Edge> &edges

) {

    in >> n;



    uint32_t m;

    uint32_t node1;

    uint32_t node2;

    int16_t cost;



    for (in >> m; m; --m) {

        in >> node1;

        in >> node2;

        in >> cost;



        edges.push_back({node1 - 1, node2 - 1, cost});

    }

}





inline bool Compare(

    Edge const &edge1,

    Edge const &edge2

) {

    return edge1.cost < edge2.cost;

}





inline uint32_t Find(

    vector<uint32_t> &parent,

    uint32_t const node

) {

    if (parent[node] == node) {

        return node;

    }



    parent[node] = Find(parent, parent[node]);



    return parent[node];

}





inline void Union(

    vector<uint32_t> &parent,

    uint32_t const node1,

    uint32_t const node2

) {

    parent[Find(parent, node1)] = Find(parent, node2);

}





void Solve(

    uint32_t const n,

    vector<Edge> &edges

) {

    sort(edges.begin(), edges.end(), Compare);



    vector<uint32_t> parent(n);



    for (uint32_t i = 0; i < n; ++i) {

        parent[i] = i;

    }



    int32_t sum = 0;

    vector<uint32_t> indices;



    for (uint32_t i = 0; i < edges.size(); ++i) {

        if (Find(parent, edges[i].node1) != Find(parent, edges[i].node2)) {

            sum += edges[i].cost;

            indices.push_back(i);



            Union(parent, edges[i].node1, edges[i].node2);

        }

    }



    out << sum << '\n';

    out << n - 1 << '\n';



    for (uint32_t i = 0; i < indices.size(); ++i) {

        out << edges[indices[i]].node1 + 1 << ' ';

        out << edges[indices[i]].node2 + 1 << '\n';

    }

}





int main() {

    uint32_t n;

    vector<Edge> edges;



    Read(n, edges);



    Solve(n, edges);



    in.close();

    out.close();



    return 0;

}
