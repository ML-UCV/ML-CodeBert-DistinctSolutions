#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
const long double EPS = 1e-8;

const int NMAX = 1505;

const int MOD = 104659;



using namespace std;



long double D[NMAX];

int P[NMAX];

int T[NMAX];

vector<int> A[NMAX];

vector<long double> C[NMAX];

int N, M;

queue<pair<int, long double> > Q;



int comp(long double x, long double y) {

    double rez = x-y;

    if (rez < -EPS)

        return -1;

    if (rez > EPS)

        return 1;

    return 0;

}



void dijkstra() {

    D[1] = 0;

    for ( int i = 2; i <= N; i++) {

        D[i] = 250000;

    }

    Q.push(make_pair(1, (long double)0));

    while (!Q.empty()) {

        int idx; double dist;

        idx = Q.front().first;

        dist = Q.front().second;

        Q.pop();

        for ( int i = 0; i < A[idx].size(); i++) {

            if (comp(dist + C[idx][i], D[A[idx][i]]) < 0) {

                D[A[idx][i]] = C[idx][i] + dist;

                P[A[idx][i]] = 1;

                T[A[idx][i]] = idx;

                Q.push(make_pair(A[idx][i], D[A[idx][i]]));

            } else if (comp(dist + C[idx][i], D[A[idx][i]]) == 0) {

                P[A[idx][i]]++;



            }

        }

    }

}



int compute(int idx) {

    int sol = 1;

    while(idx != 1) {

        sol = (sol * P[idx])%MOD;

        idx = T[idx];

    }

    return sol;

}



int main() {

    freopen("dmin.in", "r", stdin);

    freopen("dmin.out", "w", stdout);



    scanf("%d %d", &N, &M);



    for ( int i = 1, x, y, c; i <= M; i++) {

        scanf("%d %d %d", &x, &y, &c);

        A[x].push_back(y); C[x].push_back(log10l(c));

        A[y].push_back(x); C[y].push_back(log10l(c));

    }



    dijkstra();



    for ( int i = 2; i <= N; i++) {

        printf("%d ", compute(i));

    }

    printf("\n");



    return 0;

}
