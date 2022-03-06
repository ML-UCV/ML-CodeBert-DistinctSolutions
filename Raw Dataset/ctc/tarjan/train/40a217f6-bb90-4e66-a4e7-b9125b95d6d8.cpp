#include <fstream>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>




using namespace std;



ifstream cin("ctc.in");

ofstream cout("ctc.out");



vector <int> adj[100005], con, idx, lowlink, in_stack;

vector < vector <int> > C;

stack <int> S;

int index;



void read_in(vector <int>* adj, int& n)

{

    int cnt_edges, x, y;



    cin >> n;

    for (cin >> cnt_edges; cnt_edges > 0; -- cnt_edges)

        cin >> x >> y,

        adj[x - 1].push_back(y - 1);

    cin.close();

}



void print_out()

{

    cout << C.size() << "\n";

    for (size_t i = 0; i < C.size(); ++ i)

    {

        for (size_t j = 0; j < C[i].size(); ++ j)

            cout << C[i][j] + 1 << " ";

        cout << "\n";

    }

    cout.close();

}



void tarjan(const int n, const vector <int>* adj)

{

    idx[n] = lowlink[n] = index;

    index ++;

    S.push(n), in_stack[n] = 1;





    for (int i = 0; i < adj[n].size(); i++)

    {

        int it = adj[n][i];



        if (idx[it] == -1)

            tarjan(it, adj),

                   lowlink[n] = min(lowlink[n], lowlink[it]);





        else if (in_stack[it])

            lowlink[n] = min(lowlink[n], lowlink[it]);

    }



    if (idx[n] == lowlink[n])

    {

        con.clear();

        int node;

        do

        {

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

    read_in(adj, n);



    idx.resize(n), lowlink.resize(n), in_stack.resize(n);

    idx.assign(n, -1), in_stack.assign(n, 0);

    for (int i = 0; i < n; ++ i)

        if (idx[i] == -1)

            tarjan(i, adj);



    print_out();



    return 0;

}
