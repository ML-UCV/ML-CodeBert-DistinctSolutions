#include <bits/stdc++.h>




using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");

const int MAXN = 30010;



int bit[MAXN], res[MAXN], in[MAXN], n;



void update(int pos, int val) {

    for (int i = pos; i <= n; i += i & (-i))

        bit[i] += val;

}



int binarySearch(int val) {

    int i, step;

    for (step = 1; step < n; step <<= 1);

    for (i = 0; step; step >>= 1)

        if (i + step <= n) {

            if (bit[i + step] < val) {

                i += step;

                val -= bit[i];

            }

        }

    return i + 1;

}



void read() {

    fin >> n;

    for (int i = 1; i <= n; ++i) {

        fin >> in[i];

        update(i, 1);

    }

}



void solve() {

    for (int i = n; i >= 1; --i) {

        int pos = binarySearch(in[i]);

        res[pos] = i;

        update(pos, -1);

    }

}



void print() {

    for (int i = 1; i <= n; ++i)

        fout << res[i] << '\n';

}



int main() {

    read();

    solve();

    print();

    return 0;

}
