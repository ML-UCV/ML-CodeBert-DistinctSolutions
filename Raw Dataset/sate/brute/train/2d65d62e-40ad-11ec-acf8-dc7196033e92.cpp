#include <fstream>

using namespace std;

ifstream fin ("sate.in");
ofstream fout ("sate.out");

const int N = 30010, M = 100025;

int n, m, a, b, v[N], x[M], y[M], z[M], i;

int main() {
    fin >> n >> m >> a >> b;
    v[a] = 1;
    for (i = 1; i <= m; ++i) {
        fin >> x[i] >> y[i] >> z[i];
    }
    while (!v[b]) {
        for (i = 1; i <= m; ++i) {
            if (v[ x[i] ] && !v[ y[i] ]) {
                v[ y[i] ] = v[ x[i] ] + z[i];
            }
            else if (!v[ x[i] ] && v[ y[i] ]) {
                v[ x[i] ] = v[ y[i] ] - z[i];
            }
        }
    }
    fout << v[b] - 1;
}
