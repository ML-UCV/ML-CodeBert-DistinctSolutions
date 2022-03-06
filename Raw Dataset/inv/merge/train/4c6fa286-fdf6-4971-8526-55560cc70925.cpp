#include <fstream>
#include <iostream>

std::ifstream fin("inv.in");
std::ofstream fout("inv.out");

const int kMod = 9917;
const int kMaxN = 100005;

int n;
int v[kMaxN], res[kMaxN];

int merge(int a[], int b[], int a_sz, int b_sz) {
    int inv = 0;
    int a_pos = 0;
    int b_pos = 0;
    int pos = 0;

    for (a_pos = 0; a_pos < a_sz && b_pos < b_sz; ++pos) {
        if (b[b_pos] < a[a_pos]) {
            inv += a_sz - a_pos;
            res[pos] = b[b_pos];
            ++b_pos;
        }
        else {
            res[pos] = a[a_pos];
            ++a_pos;
        }
    }

    for (; b_pos < b_sz; ++b_pos, ++pos) {
        res[pos] = b[b_pos];
    }

    for (; a_pos < a_sz; ++a_pos, ++pos) {
        res[pos] = a[a_pos];
    }

    for (int i = 0; i < a_sz + b_sz; ++i) {
        a[i] = res[i];
    }

    return inv;
}

int merge_sort(int lf = 0, int rg = n - 1) {
    if (rg == lf) {
        return 0;
    }

    int med = (lf + rg) / 2;

    int lf_inv = merge_sort(lf, med);
    int rg_inv = merge_sort(med + 1, rg);

    int curr_inv = merge(v + lf, v + med + 1, med - lf + 1, rg - med);
    return (lf_inv + rg_inv + curr_inv) % kMod;
}

int main() {
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> v[i];
    }

    fout << merge_sort() << '\n';
    return 0;
}
