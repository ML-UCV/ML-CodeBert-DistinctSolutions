#include <fstream>

using namespace std;

ifstream cin("schi.in");
ofstream cout("schi.out");

const int N = 3e4 + 7;

int v[N], poz[N], n;
int t[N];

void update(int poz, int vall) {
    while (poz <= n) {
        t[poz] += vall;
        poz += poz&(-poz);
    }
}

int query(int poz) {
    int ans(0);
    while (poz > 0) {
        ans += t[poz];
        poz -= poz&(-poz);
    }
    return ans;
}

int cb(int lol) {
    int pas = 1<<14, r(0);
    while (pas > 0) {
        if (r + pas <= n && t[r + pas] < lol) {
            lol -= t[r + pas];
            r += pas;
        }
        pas>>=1;
    }
    return r + 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        update(i, 1);
    }
    for (int i = n; i >= 1; --i) {
        int ans = cb(v[i]);
        update(ans, -1);
        poz[ans] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cout << poz[i] << "\n";
    }
    return 0;
}
