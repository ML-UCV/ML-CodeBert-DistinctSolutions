#include <iostream>
#include <fstream>

using namespace std;

ifstream in("stramosi.in");
ofstream out("stramosi.out");

const int N =250005;

int n, m;
int p[25][N];
int afis;

void citire(){
    in >> n >> m;

    for (int i = 1; i <= n; ++i) {
        in >> p[0][i];
    }
}

void init(){
    for (int i = 1; (1<<i) <= n ; ++i) {
        for (int j = 1; j <= n; ++j){
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
}

void interg(){
    while (m--){
        int q, r;
        in >> q >> r;
        for (int i = 0; i <= 18; ++i) {
            if ((1<<i) & r)
                 q = p[i][q];
        }
        out << q << "\n";
    }
}

int main() {
    ios::sync_with_stdio (false);

    citire ();
    init();
    interg ();
    return 0;
}
