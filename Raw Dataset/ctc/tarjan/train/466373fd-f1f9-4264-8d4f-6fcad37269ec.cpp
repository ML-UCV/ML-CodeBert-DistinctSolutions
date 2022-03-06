#include <fstream>
#include <vector>
#include <stack>




using namespace std;





ifstream in("ctc.in");

ofstream out("ctc.out");





void Read(

    vector<vector<uint32_t>> &nodes

) {

    uint32_t n;

    uint32_t m;

    in >> n;

    in >> m;



    nodes.resize(n);



    uint32_t node1;

    uint32_t node2;



    for (; m; --m) {

        in >> node1;

        in >> node2;



        --node1;

        --node2;



        nodes[node1].push_back(node2);

    }

}





inline void Add_SCC(

    vector<vector<uint32_t>> &SCCs,

    stack<uint32_t> &stk,

    vector<bool> &on_stack,

    uint32_t const node

) {

    SCCs.push_back(vector<uint32_t>());



    uint32_t top;



    do {

        top = stk.top();

        stk.pop();

        on_stack[top] = false;



        SCCs.back().push_back(top);

    } while (top != node);

}





inline void DFS(

    vector<vector<uint32_t>> const &nodes,

    vector<uint32_t> &order,

    vector<vector<uint32_t>> &SCCs,

    uint32_t const node

) {

    static uint32_t order_count;

    static vector<uint32_t> low(nodes.size());

    static stack<uint32_t> stk;

    static vector<bool> on_stack(nodes.size());



    ++order_count;

    order[node] = order_count;

    low[node] = order_count;



    stk.push(node);

    on_stack[node] = true;



    uint32_t neighbour;



    for (uint32_t i = 0; i < nodes[node].size(); ++i) {

        neighbour = nodes[node][i];



        if (order[neighbour] == 0) {

            DFS(nodes, order, SCCs, neighbour);

        }



        if (on_stack[neighbour]) {

            low[node] = min(low[node], low[neighbour]);

        }

    }



    if (order[node] == low[node]) {

        Add_SCC(SCCs, stk, on_stack, node);

    }

}





void Solve(

    vector<vector<uint32_t>> const &nodes

) {

    vector<vector<uint32_t>> SCCs;

    vector<uint32_t> order(nodes.size());



    for (uint32_t i = 0; i < nodes.size(); ++i) {

        if (order[i] == 0) {

            DFS(nodes, order, SCCs, i);

        }

    }



    out << SCCs.size() << '\n';



    for (uint32_t j, i = 0; i < SCCs.size(); ++i) {

        for (j = 0; j < SCCs[i].size(); ++j) {

            out << SCCs[i][j] + 1 << ' ';

        }



        out << '\n';

    }

}





int main() {

    vector<vector<uint32_t>> nodes;



    Read(nodes);



    Solve(nodes);



    in.close();

    out.close();



    return 0;

}
