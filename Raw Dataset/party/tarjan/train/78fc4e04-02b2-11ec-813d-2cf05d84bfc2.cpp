#include <cstdio>
#include <vector>


using namespace std;



const int N = 2005;



vector <int> L[N], LT[N];



int n, v[N];



bool sol[N], viz[N];



int non(int x) {

    return x > n ? (x - n) : (x + n);

}



void trage_muchii(int x, int y) {

    L[non(x)].push_back(y);

    L[non(y)].push_back(x);

    LT[x].push_back(non(y));

    LT[y].push_back(non(x));

}



void read() {

    int type, x, y, m;



    scanf("%d%d", &n, &m);



    for (int i = 1; i <= m; ++ i) {

        scanf("%d%d%d", &x, &y, &type);



        if (type == 0) {

            trage_muchii(x, y);

            continue;

        }



        if (type == 1) {

            trage_muchii(x, non(y));

            continue;

        }



        if (type == 2) {

            trage_muchii(non(x), y);

            continue;

        }



        trage_muchii(non(x), non(y));

    }

}



void make_vec(int nod) {

    viz[nod] = 1;



    for (int i = 0; i < L[nod].size(); ++ i)

        if (! viz[L[nod][i]])

            make_vec(L[nod][i]);



    v[++ v[0]] = nod;

}



void init() {

    for (int i = 1; i <= 2 * n; ++ i)

        if (! viz[i])

            make_vec(i);

}



void reset(bool f[N]) {

    for (int i = 1; i <= 2 * n; ++ i)

        f[i] = false;

}



void ctc(int nod) {

    viz[nod] = 1;

    sol[non(nod)] = 1;

    for (int i = 0; i < LT[nod].size(); ++ i)

        if (! viz[LT[nod][i]])

            ctc(LT[nod][i]);

}



void solve() {

    reset(viz);



    for (int i = 2 * n; i >= 1; -- i)

        if ((! viz[v[i]]) && (! viz[non(v[i])]))

            ctc(v[i]);

}



void afis() {

    int rez = 0;



    for (int i = 1; i <= n; ++ i)

        if (sol[i])

            ++ rez;



    printf("%d\n", rez);



    for (int i = 1; i <= n; ++ i)

        if (sol[i])

            printf("%d\n", i);

}



int main() {

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    read();



    init();



    solve();



    afis();



    return 0;

}
