#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;



const int nmax = 200000;

const int mmax = 400000;

const int INF = 2000000007;



vector <pair<int, int> > g[nmax + 1], sol;

int h[nmax + 1], u[nmax + 1];

int v[nmax + 1], last[nmax + 1];

int h_size;

bool viz[nmax + 1];





void heap_swap(int a, int b){

    swap(u[h[a]], u[h[b]]);

    swap(h[a], h[b]);

}



void heap_up(int p) {

    int f = p / 2;

    while (p > 1 && v[h[p]] < v[h[f]]) {

        heap_swap(p, f);

        p = p / 2;

        f = p / 2;

    }

}



void heap_down(int p) {

    int best, l, r;

    while (2 * p <= h_size) {

        l = 2 * p;

        best = l;



        r = 2 * p + 1;

        if (r <= h_size && v[h[r]] < v[h[l]]) {

            best = r;

        }



        if (v[h[p]] > v[h[best]]) {

            heap_swap(p, best);

        } else {

            break;

        }



        p = best;

    }



}



void heap_insert(int x) {

    ++h_size;

    h[h_size] = x;

    u[x] = h_size;



    heap_up(h_size);

}



void heap_erase(int x) {

    int p = u[x];

    heap_swap(p, h_size);

    --h_size;



    heap_up(p);

    heap_down(p);



    u[x] = -1;

}



void heap_update(int x) {

    int p = u[x];



    heap_up(p);

    heap_down(p);

}



int main()

{

    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w", stdout);



    int n, m, ans = 0, x, y, c;

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; ++i) {

        scanf("%d%d%d", &x, &y, &c);

        g[x].push_back(make_pair(y, c));

        g[y].push_back(make_pair(x, c));

    }



    v[1] = 0;

    heap_insert(1);

    for (int i = 2; i <= n; ++i) {

        v[i] = INF;

        heap_insert(i);

    }



    for (int i = 1; i <= n; ++i) {

        x = h[1];

        heap_erase(x);



        ans += v[x];

        sol.push_back(make_pair(x, last[x]));



        for (int j = 0; j < g[x].size(); ++j) {

            y = g[x][j].first;

            c = g[x][j].second;

            if (u[y] != -1 && v[y] > c) {

                v[y] = c;

                last[y] = x;

                heap_update(y);

            }

        }



    }

    printf("%d\n", ans);

    printf("%d\n", n - 1);

    for (int i = 1; i < sol.size(); ++i) {

        printf("%d %d\n", sol[i].first, sol[i].second);

    }

    return 0;

}
