#include <fstream>
#include <queue>
#include <vector>






using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct pereche {

    int y, c;

};



struct muchie {

    int x, y, c;

};



struct comp {

    bool operator() (muchie u, muchie v) {

        return u.c > v.c;

    }

};



int viz[200001], t[200001], d[200001];

int n, m, x, y, cost, nr, dm, im, ct, i, j;



vector<pereche> G[200001];

priority_queue<muchie, vector<muchie>, comp> q;





int main() {

    fin >> n >> m;



    for (int i = 1; i <= m; i++) {

        fin >> x >> y >> cost;

        G[x].push_back({ y, cost });

        G[y].push_back({ x, cost });

    }



    for (int i = 2; i <= n; ++i) {

        d[i] = 1001;

        t[i] = 1;

    }



    for (int i = 0; i < G[1].size(); i++) {

        pereche pt = G[1][i];

        d[pt.y] = pt.c;

        q.push({ 1, pt.y, pt.c });

    }



    viz[1] = 1;

    nr = 1;

    ct = 0;



    while (nr < n)

    {

        muchie e;



        e = q.top(); q.pop();



        if (viz[e.y] == 0) {

            dm = e.c;





            im = e.y;



            nr++;

            viz[im] = 1;

            ct = ct + dm;



            pereche pt;

            for (int i = 0; i < G[im].size(); ++i) {

                pt = G[im][i];

                if (viz[pt.y] == 0 && d[pt.y] > pt.c) {

                    d[pt.y] = pt.c;

                    t[pt.y] = im;

                    q.push({ im, pt.y, pt.c });

                }

            }

        }

    }



    fout << ct << '\n';

    fout << n - 1 << '\n';

    for (i = 2; i <= n; i++)

        fout << i << ' ' << t[i] << '\n';

}
