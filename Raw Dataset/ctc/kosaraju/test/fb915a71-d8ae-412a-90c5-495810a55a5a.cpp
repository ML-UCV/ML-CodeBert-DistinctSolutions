#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int NMax = 100000;



vector <int> g[NMax + 5], gt[NMax + 5], sol[NMax + 5];

int n, m, nr, code;

int top[NMax + 5];

bool use[NMax + 5];



void Read(){

    fin >> n >> m;

    for (int i = 1; i <= m; i++){

        int x, y;

        fin >> x >> y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

}



void TopSort(int node){

    use[node] = 1;

    for (auto other : g[node])

        if (!use[other])

            TopSort(other);

    top[++nr] = node;

}



void DFS(int node, int code){

    use[node] = 1;

    sol[code].push_back(node);

    for (auto other : gt[node])

        if (!use[other])

            DFS(other, code);

}



void Solve(){

    for (int i = 1; i <= n; i++)

        if (!use[i])

            TopSort(i);

    memset(use, 0, sizeof use);

    for (int i = nr; i >= 1; i--)

        if (!use[top[i]]){

            ++code;

            DFS(top[i], code);

        }

}



void Print(){

    fout << code << '\n';

    for (int i = 1; i <= code; i++){

        for (auto node : sol[i])

            fout << node << ' ';

        fout << '\n';

    }

}



int main(){

    Read();

    Solve();

    Print();

    return 0;

}
