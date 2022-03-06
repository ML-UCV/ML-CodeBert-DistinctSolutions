#include <fstream>
#include <vector>
#include <cstring>


using namespace std;



const int MAX_N = 102;



int N, M, ans;

int c[2 * MAX_N], sol[2 * MAX_N];

vector < int > v[2 * MAX_N], w[2 * MAX_N], scc[2 * MAX_N], a;

bool m[2 * MAX_N], s[2 * MAX_N];



inline int neg(int x) {

    if(x <= N)

        return x + N;

    return x - N;

}



void DFS1(int x) {

    m[x] = 1;

    for(size_t i = 0; i < v[x].size(); ++i)

        if(m[v[x][i]] == 0)

            DFS1(v[x][i]);

    a.push_back(x);

}



void DFS2(int x, int nr) {

    m[x] = 1;

    c[x] = nr;

    scc[nr].push_back(x);

    for(size_t i = 0; i < w[x].size(); ++i)

        if(m[w[x][i]] == 0)

            DFS2(w[x][i], nr);

}



int main() {

    ifstream f("party.in");

    ofstream g("party.out");



    f >> N >> M;

    for(int i = 1, x, y, t; i <= M; ++i) {

        f >> x >> y >> t;



        if(t == 1)

            y = neg(y);

        else if(t == 2)

            x = neg(x);

        else if(t == 3)

            x = neg(x), y = neg(y);



        v[neg(x)].push_back(y);

        v[neg(y)].push_back(x);



        w[x].push_back(neg(y));

        w[y].push_back(neg(x));

    }



    for(int i = 1; i <= 2 * N; ++i)

        if(m[i] == 0)

            DFS1(i);



    memset(m, 0, sizeof(m));

    int nr = 0;

    for(int i = a.size() - 1; i >= 0; --i)

        if(m[a[i]] == 0) {

            ++nr;

            DFS2(a[i], nr);

        }



    for(int i = nr; i >= 1; --i) {

        if(s[i])

            continue;



        for(size_t j = 0; j < scc[i].size(); ++j) {

            int x = scc[i][j];



            sol[x] = 1;

            s[c[neg(x)]] = 1;

        }

    }



    for(int i = 1; i <= N; ++i)

        ans += sol[i];



    g << ans << "\n";

    for(int i = 1; i <= N; ++i)

        if(sol[i])

            g << i << "\n";



    f.close();

    g.close();



    return 0;

}
