#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;






const string problemName = "dmin";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";


typedef long long int lld;
typedef pair<int, int> PII;
typedef pair<int, lld> PIL;
typedef pair<lld, int> PLI;
typedef pair<lld, lld> PLL;
typedef pair<int, double> PID;
typedef pair<double, int> PDI;

const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int NMAX = 1500 + 5;
const int MOD = 104659;
const double EPS = 1e-10;

int comp(double a, double b) {
    if(fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * EPS))
        return 0;
    if((a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPS))
        return 1;
    return -1;
}

int N, M;
vector<PID> V[NMAX];
int sol[NMAX];
double D[NMAX];
bitset<NMAX> viz;
deque<int> Q;

void bf(int x) {
    int i, y;
    double z;

    for(i = 2; i <= N; i++)
        D[i] = INF;

    sol[x] = 1;
    Q.push_back(x);
    viz[x] = 1;

    while(!Q.empty()) {
        x = Q.front();
        Q.pop_front();

        viz[x] = 0;

        for(auto nod : V[x]) {
            y = nod.first;
            z = nod.second;

            if(comp(D[x] + z, D[y]) < 0) {
                D[y] = D[x] + z;
                sol[y] = 0;

                if(!viz[y]) {
                    Q.push_back(y);
                    viz[y] = 1;
                }
            }

            if(comp(D[x] + z, D[y]) == 0)
                sol[y] = (sol[y] + sol[x]) % MOD;
        }
    }
}

int main() {
    int i, x, y, z;


    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);


    scanf("%d%d", &N, &M);

    while(M--) {
        scanf("%d%d%d", &x, &y, &z);
        V[x].push_back(make_pair(y, log2(z)));
        V[y].push_back(make_pair(x, log2(z)));
    }

    bf(1);

    for(i = 2; i <= N; i++)
        printf("%d ", sol[i]);

    return 0;
}
