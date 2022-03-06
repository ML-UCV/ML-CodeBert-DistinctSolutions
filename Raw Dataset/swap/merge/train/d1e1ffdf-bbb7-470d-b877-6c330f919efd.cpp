#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 50100;
ifstream fin("swap.in");
ofstream fout("swap.out");
int alf[27][MAX_N];
int alfIt[27];
int v[MAX_N];
int merge_sort(int, int);
int main() {
    string a1, a2;
    getline(fin, a1);
    getline(fin, a2);
    for (unsigned int i = 0; i < a2.size(); ++i) {
        int ch = a2[i] - 'a';
        alf[ch][++alf[ch][0]] = i + 1;
    }
    for (unsigned int i = 0; i < a1.size(); ++i) {
        int ch = a1[i] - 'a';
        ++alfIt[ch];
        if (alfIt[ch] > alf[ch][0]) {
            fout << -1;
            return 0;
        }
        v[i+1] = alf[ch][alfIt[ch]];
    }
    int N = a1.size();
    fout << merge_sort(1, N);
    return 0;
}

int merge_sort(int lo, int hi) {
    if (lo == hi) return 0;
    int mid = lo + (hi - lo) / 2, numInv;
    numInv = merge_sort(lo, mid) + merge_sort(mid + 1, hi);
    int aux[MAX_N];
    for (int i = lo, j = mid + 1, k = lo; i <= mid || j <= hi; ++k) {
        if ((i <= mid && v[i] < v[j]) || j > hi) {
            aux[k] = v[i++];
        } else {
            aux[k] = v[j++];
            numInv += (mid - i + 1);
        }
    }
    for (int k = lo; k <= hi; ++k) {
        v[k] = aux[k];
    }
    return numInv;
}
