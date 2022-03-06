#include <bits/stdc++.h>

using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");

const int NMax = 250005;
const int LMax = 20;

int v[LMax][NMax];

int main(){
    int n, m, p, node;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> v[0][i];
    }
    for(int i = 1; i < LMax; i++){
        for(int j = 1; j <= n; j++){
            v[i][j] = v[i - 1][v[i - 1][j]];
        }
    }
    for(int i = 1; i <= m; i++){
        fin >> node >> p;
        for(int i = 0; i < LMax; i++){
            if((p >> i) % 2 == 1){
                node = v[i][node];
            }
        }
        fout << node << "\n";
    }
    return 0;
}
