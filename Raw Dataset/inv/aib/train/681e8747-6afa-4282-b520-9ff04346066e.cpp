#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <stack>



using namespace std;




string name = "inv";


ifstream fin(name + ".in");
ofstream fout(name + ".out");




int n;
vector<int> a;

int f[100005];

inline int nrz(int x) {
    return x & -x;
}

int query(int x) {
    int s = 0;

    while (x > 0) {
        s += f[x];
        x -= nrz(x);
    }

    return s;
}

int query(int a, int b) {
    return query(b) - query(a - 1);
}

void update(int x) {
    while (x <= n) {
        f[x]++;
        x += nrz(x);
    }
}

struct Item {
    int v;
    int i;
};

int main() {

    fin >> n;

    auto compare = [](Item lhs, Item rhs) {
        return lhs.v > rhs.v;
    };

    priority_queue<Item, vector<Item>, decltype(compare)> pq(compare);

    for (int i = 0; i <n ; ++i) {
        int x;
        fin >> x;
        a.push_back(x);
        pq.push({x, i});
    }

    int v = 0;
    int last = -0x3f3f3f3f;

    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        if (x.v != last) {
            last = x.v;
            v++;
        }

        a[x.i] = v;
    }

    int result = 0;

    for (int i = 0; i < n; ++i) {
        int x = a[i];

        if (x < n) {
            result += query(x + 1, n);
            result %= 9917;
        }

        update(x);
    }

    fout << result;

    return 0;
}
