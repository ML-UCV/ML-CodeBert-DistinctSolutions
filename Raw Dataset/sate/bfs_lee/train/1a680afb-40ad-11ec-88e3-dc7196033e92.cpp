#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int MAXN = 30005;
int n, m;
int c1, c2;
vector< pair<int, int> > v[MAXN];
queue<int> q;
int s[MAXN];

int main() {

    fin >> n >> m;
    fin >> c1 >> c2;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        fin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, -c));

    }

    q.push(c1);
    while (!q.empty()) {
        int k = q.front();
        for (int i = 0; i < v[k].size(); ++i) {
            pair<int, int> p = v[k][i];
            if (s[p.first] == 0 || s[p.first] > s[k] + p.second) {
                s[p.first] = s[k] + p.second;
                q.push(p.first);
            }
        }
        q.pop();
    }

    fout << s[c2];


    fout.close();
    return 0;
}
