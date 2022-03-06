#include <fstream>

const std :: string programName = "inv";
std :: ifstream f(programName + ".in");
std :: ofstream g(programName + ".out");

const int MAX = 100005, MOD = 9917;

int N, nr, v[MAX], b[MAX];

void read(void);
void merge(int, int, int);
void mergeSort(int, int);

int main(void) {
    read();
    mergeSort(0, N - 1);
    g << nr;
    return 0x0;
}

void read(void) {
    f >> N;
    for (int i = 0; i < N; ++i)
        f >> v[i];
}

void merge(int l, int r, int mid) {
    int i = l, j = mid + 1, k = 1;
    while (i <= mid and j <= r){
        if (v[i] <= v[j])
            b[k++] = v[i++];
        else {
            b[k++] = v[j++];
            nr = (nr + mid - i + 1) % MOD;
        }
    }
    while (i <= mid)
        b[k++] = v[i++];
    while (j <= r)
        b[k++] = v[j++];
    for (i = l, k = 1; i <= r; i++, k++)
        v[i] = b[k];
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, r, mid);
    }
}
