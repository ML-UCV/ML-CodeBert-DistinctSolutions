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



int sum(int pos) {

    int s = 0;

    for (int i = pos; i >= 1; i -= i & (-i))

        s += bit[i];

    return s;

}



int binarySearch(int val) {

    int left = 1, right = n, pos = 0;

    while (left <= right) {

        int middle = left + (right - left) / 2, s;

        s = sum(middle);

        if (val == s) {

            pos = middle;

            right = middle - 1;

        }

        else if (val < s)

            right = middle - 1;

        else

            left = middle + 1;

    }

    return pos;

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
