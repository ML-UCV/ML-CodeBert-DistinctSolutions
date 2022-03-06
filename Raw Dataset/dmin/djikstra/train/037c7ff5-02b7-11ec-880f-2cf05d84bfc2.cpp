#include <bits/stdc++.h>


using namespace std;



ifstream in("dmin.in");

ofstream out("dmin.out");



const int NMAX = 1501,

          MOD = 104659;

const double EPS = 1e-10;



struct muchie {

    int y;

    double cst;

};



class cmp {

    public: bool operator()(const muchie& a, const muchie& b) {

        return a.cst > b.cst;

    }

};



double distMin[NMAX];

int nrDrum[NMAX];

bool v[NMAX];

vector<muchie> A[NMAX];

priority_queue<muchie, vector<muchie>, cmp> PQ;

int N, M;



void dijkstra() {

    PQ.push({1, 0});

    for(int i = 2; i <= N; i++)

        distMin[i] = (1 << 25);



    nrDrum[1] = 1;

    distMin[1] = 0.0;

    while(!PQ.empty()) {

        int U = PQ.top().y;



        PQ.pop();

        if(v[U]) continue;



        for(const auto& vec: A[U]) {

            int V = vec.y;

            double W = vec.cst;

            if(distMin[V] - distMin[U] - W > EPS) {

                distMin[V] = distMin[U] + W;

                nrDrum[V] = nrDrum[U] % MOD;

                PQ.push({V, distMin[V]});

            } else if(abs(distMin[V] - distMin[U] - W) <= EPS)

                nrDrum[V] = (nrDrum[U] + nrDrum[V]) % MOD;

        }

        v[U] = 1;

    }

}



int main()

{

    in >> N >> M;



    int x, y;

    double c;

    for(int i = 1; i <= M; i++) {

        in >> x >> y >> c;

        c = log(c);

        A[x].push_back({y, c});

        A[y].push_back({x, c});

    }



    dijkstra();



    for(int i = 2; i <= N; i++)

        out << nrDrum[i] << ' ';

    return 0;

}
