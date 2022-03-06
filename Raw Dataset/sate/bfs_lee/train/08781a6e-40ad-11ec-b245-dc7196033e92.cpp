#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string.h>
#define dMAX 30005

using namespace std;

typedef pair<int, int> pi;

int n, m, x, y;
int a, b, c;
int dist[dMAX];
bool viz[dMAX];
vector<pi> graf[dMAX];
deque<int> d;
int pVerif, newV;

char str[20];

ifstream fin("sate.in");
ofstream fout("sate.out");

void GetInt() {
    int i, j, t;
    i = j = t = 0;
    fin.getline(str, 20);
    while (isdigit(str[i])) {
        t *= 10;
        t += (str[i] - '0');
        i++;
    }
    i++;
    a = t;
    t = 0;
    while (isdigit(str[i])) {
        t *= 10;
        t += (str[i] - '0');
        i++;
    }
    i++;
    b = t;
    t = 0;
    while (isdigit(str[i])) {
        t *= 10;
        t += (str[i] - '0');
        i++;
    }
    c = t;
    //cout << a << ' ' << b << ' ' << c << '\n';
}

int main()
{
    int i, j;
    fin >> n >> m >> x >> y;
    fin.get();
    for (i = 1; i <= m; i++) {
        //fin >> a >> b >> c;
        GetInt();
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    if (y < x) swap(x, y);
    d.push_back(x);
    dist[x] = 1;
    while (!d.empty()) {
        pVerif = d.front();
        viz[pVerif] = true;
        d.pop_front();
        for (i = 0; i < graf[pVerif].size(); i++) {
            newV = graf[pVerif][i].first;
            if (!viz[newV]) {
                if (newV > pVerif) {
                    dist[newV] = dist[pVerif] + graf[pVerif][i].second;
                } else {
                    dist[newV] = dist[pVerif] - graf[pVerif][i].second;
                }
                d.push_back(newV);
            }
        }
    }
    fout << dist[y] - 1;
    return 0;
}
