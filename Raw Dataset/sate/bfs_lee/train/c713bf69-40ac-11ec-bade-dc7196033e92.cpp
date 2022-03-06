#include <fstream>
#include <queue>
#include <vector>

constexpr auto max_n = 30005;

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m, x, y;
vector<pair<int, int>> graph[max_n];
int distances[max_n];

void distance()
{
    queue<int> nodes_queue;
    distances[x] = 0;

    nodes_queue.push(x);

    while (!nodes_queue.empty())
    {
        const auto& current_node = nodes_queue.front();
        nodes_queue.pop();

        const auto crt_distance = distances[current_node];

        for (const auto& neighbor : graph[current_node])
        {
            if (distances[neighbor.first] == -1)
            {
                int new_distance;
                if (neighbor.first < current_node)
                    new_distance = crt_distance - neighbor.second;
                else
                    new_distance = crt_distance + neighbor.second;

                distances[neighbor.first] = new_distance;
                nodes_queue.push(neighbor.first);
            }
        }
    }
}

int main()
{
    fin >> n >> m >> x >> y;

    for (auto i = 0; i < m; i++)
    {
        int k, j, d;
        fin >> k >> j >> d;
        graph[k].emplace_back(j, d);
        graph[j].emplace_back(k, d);
    }

    for (auto i = 0; i <= n; i++)
        distances[i] = -1;

    distance();

    fout << distances[y];

    return 0;
}