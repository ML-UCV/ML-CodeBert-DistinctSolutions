#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>




using namespace std;

int n, m;
int cate[1550], used[1550];
double best[1550];
const double EPS = 1e-9;
struct leg
{
    int y;
    double c;
    leg(int y = 0, double c = 0) : y(y), c(c) { }
    bool operator ()(int a, int b)
    {
        return best[a] > best[b];
    }
};
bool eq(double a, double b)
{
    return (a-b) >= -EPS && (a-b) <= EPS;
}
vector<leg> graf[1550];
void citire()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y, rc;
        scanf("%d %d %d", &x, &y, &rc);
        double c = log(1.0*rc);
        graf[x].push_back(leg(y, c));
        graf[y].push_back(leg(x, c));
    }
}
priority_queue<int, vector<int>, leg> heap;
void solve()
{
    for (int i = 1; i <= n; i++) best[i] = 5e100;
    best[1] = 0, cate[1] = 1;
    heap.push(1);
    while (!heap.empty()) {
        int top = heap.top();
        heap.pop();
        if (used[top])
            continue;
        used[top] = 1;
        for (auto v : graf[top]) {
            if (eq(best[top] + v.c, best[v.y]))
                cate[v.y] = (cate[v.y] + cate[top]) % 104659;
   else if (best[top] + v.c < best[v.y]) {
                best[v.y] = best[top] + v.c;
                cate[v.y] = cate[top];
                heap.push(v.y);
            }
        }
    }
}

void afisare()
{
    for (int i = 2; i <= n; i++)
        printf("%d ", cate[i]);
}

int main()
{
    freopen("dmin.in", "r", stdin);
    freopen("dmin.out", "w", stdout);

    citire();
    solve();
    afisare();

    return 0;
}
