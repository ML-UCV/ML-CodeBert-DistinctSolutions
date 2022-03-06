#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;



ifstream cin("apm.in");
ofstream cout("apm.out");

const int MAXM = 4e5 + 100;
const int MAXN = 2e5 + 100;

struct muchie{
    int x , y , c;
} mat [MAXM] ;

bool cmp(muchie a , muchie b){
    return a.c < b.c;
}

int n, m, cost;
int tata [MAXN];
vector <muchie> ans;

void read() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> mat[i].x >> mat[i].y >> mat[i].c;
    for (int i = 1; i <= n; i++)
        tata[i] = i;
}

int cureCancerFunc (int node){
    if (node != tata[node])
        tata[node] = cureCancerFunc(tata[node]);
    return tata[node];
}

void unite (int a , int b){
    cureCancerFunc(b);
    cureCancerFunc(a);
    tata[tata[b]] = tata[a];
}

void solve() {
    read();
    sort(mat + 1, mat + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        muchie now = mat[i];
        int x, y;
        x = cureCancerFunc(now.x);
        y = cureCancerFunc(now.y);
        if (x != y) {
            unite(x, y);
            ans.push_back(now);
            cost += now.c;
        }
    }
    cout << cost << '\n' << ans.size() << '\n';
    for (auto& x : ans) {
        cout << x.x << " " << x.y << '\n';
     }
}

int main() {

    solve();

    return 0;
}
