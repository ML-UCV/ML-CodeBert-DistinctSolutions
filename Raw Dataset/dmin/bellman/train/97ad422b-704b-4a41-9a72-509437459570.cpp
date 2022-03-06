#include <fstream>
#include <vector>
#include <cmath>


using namespace std;



const int MAX_N = 1502;

const int MOD = 104659;

const double EPS = 0.000001;



typedef int Heap[MAX_N];



int N, M, Nr;

int pos[MAX_N], S[MAX_N];

vector < pair < int, double > > v[MAX_N];

double D[MAX_N];

Heap H;



inline int double_cmp(double a, double b) {

    if(a - b < -EPS)

        return -1;

    if(a - b > EPS)

        return 1;

    return 0;

}



inline void percolate(Heap H, int N, int K) {

    int temp = H[K];

    while(K > 1 && double_cmp(D[temp], D[H[K/2]]) < 0)

        H[K] = H[K/2], pos[H[K]] = K, K /= 2;

    H[K] = temp, pos[temp] = K;

}



inline void sift(Heap H, int N, int K) {

    int son;

    do {

        son = 0;

        if(K*2 <= N) {

            son = K*2;

            if(K*2+1 <= N && double_cmp(D[H[K*2+1]], D[H[son]]) < 0)

                son = K*2+1;

        }

        if(double_cmp(D[H[son]], D[H[K]]) >= 0)

            son = 0;

        if(son) {

            int temp = H[K];

            H[K] = H[son], H[son] = temp;

            pos[H[K]] = K, pos[H[son]] = son;

            K = son;

        }

    } while(son);

}



int main() {

    ifstream f("dmin.in");

    ofstream g("dmin.out");



    f >> N >> M;

    for(int i = 1, x, y; i <= M; ++i) {

        double c;

        f >> x >> y >> c;

        c = log10(c);

        v[x].push_back(make_pair(y,c));

        v[y].push_back(make_pair(x,c));

    }



    H[++Nr] = 1, pos[1] = S[1] = 1;

    for(int i = 2; i <= N; ++i)

        D[i] = 9999999999;

    while(Nr) {

        int x = H[1];

        H[1] = H[Nr--];

        if(Nr)

            pos[H[1]] = 1, sift(H, Nr, 1);

        for(size_t i = 0; i < v[x].size(); ++i) {

            int y = v[x][i].first;

            double c = v[x][i].second;

            int t = double_cmp(D[x]+c, D[y]);

            if(t < 0) {

                D[y] = D[x] + c, S[y] = S[x];

                if(pos[y])

                    percolate(H, Nr, pos[y]);

                else H[++Nr] = y, pos[y] = Nr, percolate(H, Nr, Nr);

            }

            else if(!t)

                S[y] += S[x], S[y] %= MOD;



        }

    }



    for(int i = 2; i <= N; ++i)

        g << S[i] << ' ';

    g << '\n';



    f.close();

    g.close();



    return 0;

}
