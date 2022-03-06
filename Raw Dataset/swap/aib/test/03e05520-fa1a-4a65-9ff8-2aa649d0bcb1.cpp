#include <fstream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

ifstream f("swap.in");
ofstream g("swap.out");
const int LETTERS = 26;

int N;
vector < int > frA(LETTERS, 0), frB(LETTERS, 0);
vector < int > perm, bit;
deque < int > fromA[LETTERS], fromB[LETTERS];

inline int lsb(int nr) {
    return (nr & -nr);
}

int query(int index) {
    int ret{};

    for(;index;index -= lsb(index))
        ret += bit[index];

    return ret;
}

void update(int index) {
    for(;index <= N;index += lsb(index))
        bit[index]++;
}

int main() {

    string a, b;
    f >> a >> b;

    for (char &c : a)
        frA[c - 'a']++;

    for (char &c : b)
        frB[c - 'a']++;

    for (int i = 0; i < LETTERS; ++i) {
        if (frA[i] != frB[i]) {
            g << "-1";
            return 0;
        }
    }

    a = " " + a;
    b = " " + b;

    N = a.size() - 1;

    perm.resize(N + 1, 0);

    for(int i = 1;i <= N;++i)
        fromA[ a[i] - 'a' ].push_back(i);

    for(int i = 1;i <= N;++i)
        fromB[ b[i] - 'a' ].push_back(i);

    for(int i = 1;i <= N;++i) {
        int pos = fromA[a[i] - 'a'].front();
        fromA[ a[i] - 'a' ].pop_front();

        perm[pos] = fromB[ a[i] - 'a' ].front();
        fromB[ a[i] - 'a' ].pop_front();
    }

    int ans{};
    bit.resize(N + 1, 0);

    for(int i = N;i;--i) {
        ans += query(perm[i] - 1);
        update(perm[i]);
    }

    g << ans;

    return 0;
}
