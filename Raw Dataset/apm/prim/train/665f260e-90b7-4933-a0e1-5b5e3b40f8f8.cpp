#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
const int N_MAX = 1000005;

std :: vector <std :: pair <int, int> > graph[N_MAX], apm;
std :: priority_queue <std :: pair < int, std :: pair <int, int> > > pq;
bool vis[N_MAX];
int n, m, t_cost;
int start;

int main(){

    std :: ifstream fin("apm.in");
    std :: ofstream fout("apm.out");

    fin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        fin >> x >> y >> c;
        graph[x].push_back(std :: make_pair(y, c));
        graph[y].push_back(std :: make_pair(x, c));

    }

    start = 1;
    vis[start] = true;
    for (auto i : graph[start]) {
        pq.push({-i.second, {start, i.first }});
    }


    while(!pq.empty()) {
        std :: pair <int, std :: pair <int, int> > best_cost = pq.top();

        pq.pop();

        int cost = best_cost.first;
        int next = best_cost.second.second;

        if (!vis[next]) {
            vis[next] = true;
            apm.push_back(best_cost.second);

            t_cost += -cost;

            for (auto i : graph[next]) {
                pq.push({-i.second, {next, i.first}});
            }
        }
    }

    fout << t_cost << "\n" << n-1 << '\n';
    for (auto i : apm) fout << i.first << " " << i.second << '\n';
    return 0;
}
