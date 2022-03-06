#include <bits/stdc++.h>


using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int NMax = 1505;

const int MOD = 104659;

const double Eps = 1e-6;



int Count[NMax];

double D[NMax];

bool Used[NMax];



vector < pair < int, double > > G[NMax];



inline void Dijkstra(){

    set < pair < double, int > > T;

    T.insert(make_pair(0, 1));

    D[1] = 0;

    while(!T.empty()){

        auto R = *T.begin();

        T.erase(R);

        for(auto it : G[R.second]){

            if(D[it.first] > it.second + D[R.second]){

                D[it.first] = it.second + D[R.second];

                T.insert(make_pair(D[it.first], it.first));

            }

        }

    }

}





int Solve(const int k){

    if(Used[k]) return Count[k];

    Used[k] = 1;

    for(auto it : G[k]){

        if((max(D[it.first] - D[k] + it.second, -D[it.first] - D[k] + it.second)) < Eps){

            Count[k] += Solve(it.first);

            Count[k] %= MOD;

        }

    }

    return Count[k];

}



int main(){

    int n, m, a, b, c;

    fin >> n >> m;

    for(int i = 1; i <= m; i++){

        fin >> a >> b >> c;

        G[a].push_back(make_pair(b, log(c)));

        G[b].push_back(make_pair(a, log(c)));

    }

    for(int i = 1; i <= n; i++){

        D[i] = INFINITY;

    }

    Dijkstra();

    Count[1] = 1;

    Used[1] = 1;

    for(int i = 2; i <= n; i++) Count[i] = Solve(i);

    for(int i = 2; i <= n; i++) {

        fout << Count[i] << " ";

    }

    return 0;

}
