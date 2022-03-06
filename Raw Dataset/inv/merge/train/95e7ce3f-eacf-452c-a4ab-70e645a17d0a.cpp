#include <iostream>
#include <fstream>

using namespace std;

int inv = 0;

int w[100001];

void interclasare(int v[], int st, int dr) {
    int m, i, j, k;
    m = (st + dr) / 2;
    k = 0;
    i = st;
    j = m + 1;
    while (i <= m && j <= dr) {
        if (v[i] <= v[j]) w[++k] = v[i++];
        else {
            w[++k] = v[j++];
            inv = inv + m - i + 1;
            inv = inv % 9917;
        }
    }
    while (i <= m) w[++k] = v[i++];
    while (j <= dr) w[++k] = v[j++];
    for (i = st, j = 1; i <= dr; i++, j++) v[i] = w[j];
}


void mergeSort(int v[], int st, int dr) {
    if (st < dr) {
        int m = (st + dr) / 2;
        mergeSort(v, st, m);
        mergeSort(v, m + 1, dr);
        interclasare(v, st, dr);
    }
}

int main() {
    ifstream fin("inv.in");
    ofstream fout("inv.out");
    int v[100001];
    int n, i;
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> v[i];
    mergeSort(v, 1, n);
    fout << inv % 9917;
    return 0;
}
