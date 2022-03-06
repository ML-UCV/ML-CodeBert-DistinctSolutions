#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;



const char iname[] = "ctc.in";

const char oname[] = "ctc.out";
vector <int> adj[100005], con, idx, lowlink, in_stack;



vector < vector <int> > C;



stack <int> S;



int indecs;



void read_in(vector <int>* adj, int& n, const char iname[])

{

    ifstream in(iname);

    int cnt_edges, x, y;



    in >> n;

    for (in >> cnt_edges; cnt_edges > 0; -- cnt_edges)

        in >> x >> y,

        adj[x - 1].push_back(y - 1);

    in.close();

}



void print_out(const vector < vector <int> >& G, const char oname[])

{

    ofstream out(oname);



    out << G.size() << "\n";

    for (size_t i = 0; i < G.size(); ++ i) {

        for (size_t j = 0; j < G[i].size(); ++ j)

            out << G[i][j] + 1 << " ";

        out << "\n";

    }

    out.close();

}



void tarjan(const int n, const vector <int>* adj)

{

    idx[n] = lowlink[n] = indecs;

    indecs ++;

    S.push(n), in_stack[n] = 1;



    vector <int>::const_iterator it;

    for (it = adj[n].begin(); it != adj[n].end(); ++ it) {

        if (idx[*it] == -1)

            tarjan(*it, adj),

            lowlink[n] = ((lowlink[n]) < (lowlink[*it]) ? (lowlink[n]) : (lowlink[*it]));

        else if (in_stack[*it])

            lowlink[n] = ((lowlink[n]) < (lowlink[*it]) ? (lowlink[n]) : (lowlink[*it]));

    }

    if (idx[n] == lowlink[n]) {

        con.clear();

        int node;

        do {

            con.push_back(node = S.top());

            S.pop(), in_stack[node] = 0;

        }

        while (node != n);

        C.push_back(con);

    }

}



int main(void)

{

    int n;

    read_in(adj, n, iname);



    idx.resize(n), lowlink.resize(n), in_stack.resize(n);

    idx.assign(n, -1), in_stack.assign(n, 0);

    for (int i = 0; i < n; ++ i) if (idx[i] == -1)

        tarjan(i, adj);



    print_out(C, oname);



    return 0;

}
