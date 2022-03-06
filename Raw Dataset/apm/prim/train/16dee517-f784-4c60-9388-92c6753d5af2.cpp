#include <fstream>
#include <vector>
#include <queue>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



vector <pair <int, pair<int, int>>> G[200003];

priority_queue <pair <int, pair<int, int>>, vector<pair <int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;

vector <pair<int, int>> sol;



int N, M, X, Y, C;

long long sum;

bool sel[200003];



void solve() {

    for (int i = 0; i < G[1].size(); i++)

        H.push(G[1][i]);



    sel[1] = true;



    for (int i = 1; i < N; i++) {

        while (sel[H.top().second.second]) H.pop();



        auto curr = H.top();

        sol.push_back({ curr.second.first, curr.second.second });

        sum += curr.first;

        sel[curr.second.second] = true;



        for (int j = 0; j < G[curr.second.second].size(); j++) {

            if (sel[G[curr.second.second][j].second.second] == 0) {

                H.push(G[curr.second.second][j]);

            }

        }

    }

}

int main()

{

    f >> N >> M;



    for (int i = 1; i <= M; i++) {

        f >> X >> Y >> C;

        G[X].push_back({ C, {X, Y} });

        G[Y].push_back({ C, {Y, X } });

    }



    solve();



    g << sum << "\n" << sol.size() << "\n";



    for (auto i : sol)

        g << i.first << " " << i.second << "\n";

    return 0;

}
