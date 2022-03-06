#include <bits/stdc++.h>
#define Nmax 30005
using namespace std;
ifstream f("sate.in"); ofstream g("sate.out");
int n, m, dist[Nmax], start, fin, viz[Nmax];
char s[1005];
vector <pair <int, int> > G[Nmax];
void read()
{   f >> n >> m >> start >> fin;
    f.get();
    int x, y, c, nr, cnt;
    for (int k = 1; k <= m; ++k)
    {   cnt = 0;
        f.getline(s, 1001);
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                nr = 0;
                cnt++;
                while (s[i] >= '0' && s[i] <= '9') {
                    nr = nr * 10 + s[i] - '0';
                    ++i;
                }
                if (cnt == 1) x = nr;
                if (cnt == 2) y = nr;
                if (cnt == 3) c = nr;
            }
        }
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, -c));
    }
}
void bfs(int start)
{   queue <int> Coada;
    Coada.push(start);
    dist[start] = 0;
    viz[start] = 1;
    while (!Coada.empty()) {
        int node = Coada.front();
        Coada.pop();
        for (auto pos : G[node]) {
            int newNode = pos.first;
            int newCost = pos.second;
            if (!viz[newNode]) {
                viz[newNode] = 1;
                dist[newNode] = dist[node] + newCost;
                if (newNode == fin)
                    break;
                Coada.push(newNode);
            }
        }
    }
    g << dist[fin];
}
int main()
{   read();
    bfs(start);
    return 0;
}
