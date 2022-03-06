#include <bits/stdc++.h>







using namespace std;
    ifstream fffin("apm.in");

    ofstream fffout("apm.out");







const bool MULTIPLE_CASES = 0;

const bool PRINT_CASE_MSG = 0;



const int DOUBLE_PRECISION = 6;





using i64 = long long;

using pii = pair<int, int>;

using Graph = vector<vector<int>>;





const int INF = (1 << 30);

const int NMAX = 1e5 + 3;



struct CostGraph

{

    using Edge = pair<int, int>;

    using Graph = vector<vector<Edge>>;



    int N;

    Graph mGraph;

    vector<pair<int, Edge>> mEdges;



    CostGraph(int n) : N(n), mGraph(n + 1)

    { }



    void insertEdge(int from, Edge to)

    {

        assert(1 <= from && from <= N);

        assert(1 <= to.first && to.first <= N);



        mGraph[from].push_back(to);

        mEdges.push_back({from, to});

    }



    int getAPM(vector<pair<int, Edge>>& actualAPM)

    {

        actualAPM.clear();

        vector<int> tt(N + 1), gr(N + 1, 1);



        function<int (int)> ROOT = [&](int nod) {

            if (tt[nod] == nod)

                return nod;

            return tt[nod] = ROOT(tt[nod]);

        };



        function<bool (int, int)> UNION = [&](int x, int y) {

            x = ROOT(x), y = ROOT(y);

            if ( x == y )

                return false;

            if (gr[x] < gr[y])

                swap(x, y);



            gr[x] += gr[y];

            tt[y] = x;

            return true;

        };



        iota(tt.begin(), tt.end(), 0);

        sort(mEdges.begin(), mEdges.end(), [](const pair<int, Edge>& a, const pair<int, Edge>& b){

            return a.second.second < b.second.second;

        });



        int apmCost = 0;

        for (auto mED : mEdges) {

            int from = mED.first;

            int to = mED.second.first;

            int cost = mED.second.second;

            if (UNION(from, to))

                apmCost += cost,

                actualAPM.push_back({from, {to, cost}});

        }

        return apmCost;

    }

};



void solve()

{

    int N, M;

    cin >> N >> M;

    CostGraph graph(N);

    for (int i = 1; i <= M; ++i) {

        int x,y,c;

        cin >> x >> y >> c;

        graph.insertEdge(x, {y, c});

    }

    vector<pair<int, CostGraph::Edge>> edges;

    cout << graph.getAPM(edges) << '\n';

    cout << edges.size() << '\n';

    for (auto x : edges) {

        cout << x.first << ' ' << x.second.first << '\n';

    }

}



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);





        cin.rdbuf(fffin.rdbuf());

        cout.rdbuf(fffout.rdbuf());
    if (DOUBLE_PRECISION > 0)

        cout << setprecision(DOUBLE_PRECISION) << fixed;



    auto testMessage = [](int id) {

        return "Case #" + to_string(id) + ": ";

    };



    int T = 1;

    if (MULTIPLE_CASES)

        cin >> T;



    for (int t = 1; t <= T; ++t) {

        cout << (PRINT_CASE_MSG ? testMessage(t) : "");

        solve();

    }
}
