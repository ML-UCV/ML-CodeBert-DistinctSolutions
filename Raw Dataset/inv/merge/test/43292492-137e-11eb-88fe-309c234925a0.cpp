#include <iostream>
#include <fstream>
using std::cin;
using std::cout;


    std::ifstream fin("inv.in");
    std::ofstream fout("inv.out");




int s[100000], aux[100000];

int merge (int st, int dr, int v[]) {
    int i, j, k, m = (st + dr) >> 1, nr;
    i = k = st;
    j = m + 1;
    nr = 0;
    while (i <= m && j <= dr)
        if (v[i] <= v[j]) aux[k++] = v[i++];
        else {
            aux[k++] = v[j++];
            nr += m - i + 1;
        }

    while (i <= m) aux[k++] = v[i++];
    while (j <= dr) aux[k++] = v[j++];

    for (k = st ; k <= dr ; k++) v[k] = aux[k];

    return nr;
}

int msort (int st, int dr, int v[]) {
    if (st == dr) return 0;
    int m = (st + dr) >> 1;
    return (msort(st, m, v) + msort(m + 1, dr, v) + merge(st, dr, v)) % 9917;
}

int main (int argc, const char * argv[]) {
    int n;
    fin >> n;
    for (auto i = 0 ; i < n ; i++) fin >> s[i];
    fout << msort (0, n - 1, s);
    return 0;
}
