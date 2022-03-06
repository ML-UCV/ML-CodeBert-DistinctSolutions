#include<cstdio>
#include<vector>

using namespace std;

const int N = 30005;
const int M = 100050;

int n, m, x, y, dist[N], xx[M];
vector< pair<int, int> > vecin[N];

void citire() {
//    n = sate, m = relatii, x = nodul de start, y = nodul de stop
    scanf("%d%d%d%d", &n, &m, &x, &y);

    for (int i = 1; i <= m; ++i) {
        int x1, y1, c;
        scanf("%d%d%d", &x1, &y1, &c);

        vecin[x1].push_back(make_pair(y1, c));
        vecin[y1].push_back(make_pair(x1, -c));
    }
}

inline void schimb(int &x, int &y) {
    int aux = x;
    x = y;
    y = aux;
}

//  la finalul functiei o sa am vectorul de distante
void bfs() {
    xx[0] = x;

    int p = 0, q = 0;
//  cat timp coada nu e vida
    while (p <= q) {
//        ma uit la toti vecinii primului nod
        for (int i = 0; i < (int) vecin[xx[p]].size(); ++i) {
//            first = nod, second = cost
            int xc = vecin[xx[p]][i].first;
//  daca nodul xc(nodul vecin) este diferit de nodul de start si daca vecinul asta e ori nevizitat, ori noua distanta < dist la care era
// seamana cu Bellman-Ford ( din cauza if-ului de distante)
// pentru ca am costuri pe muchii, am nevoie de if
            if (xc != x && (dist[xc] == -1 || dist[xc] > dist[xx[p]] + vecin[xx[p]][i].second) ) {
//                actualizez distanta
                dist[xc] = dist[xx[p]] + vecin[xx[p]][i].second;
//  pun acest vecin in coada
                xx[++q] = xc;
            }

            if (dist[y] != -1)
                return;
        }

        ++p;
    }
}

int main() {
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);

    citire();
// distanta intre satele x si y
    if (x > y)
        schimb(x, y);
// toate distantele sunt -1 pentru ca la inceput sunt nevizitate
    for (int i = 0; i < N; ++i)
        dist[i] = -1;

//    marchez primul sat (x) cu 0
    dist[x] = 0;

    bfs();

    printf("%d\n", dist[y]);

    return 0;
}