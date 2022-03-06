#include <fstream>

int tree[1 << 16], i, n, x, v[30001], r[30001];

inline void add(int p, int st, int dr) {
    ++tree[p];
    if (st == dr) r[st] = i;
    else {
        int m = (st + dr) / 2;
        int l = m - st + 1 - tree[2 * p];
        if (l >= x) add(2 * p, st, m);
        else {
            x -= l;
            add(2 * p + 1, m + 1, dr);
        }
    }
}

int main() {
    std::ifstream in("schi.in");
    std::ofstream out("schi.out");
    in >> n;
    for (i = 1; i <= n; ++i) in >> v[i];
    for (i = n; i >= 1; --i) {
        x = v[i];
        add(1, 1, n);
    }
    for (i = 1; i <= n; ++i) out << r[i] << '\n';
    return 0;
}
