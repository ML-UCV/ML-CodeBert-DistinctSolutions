#include <fstream>
#include <iomanip>
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




string name = "schi";


ifstream fin(name + ".in");
ofstream fout(name + ".out");

struct Event {
    int p;
    int v;
};

vector<Event> q;


int aib[30005];
int n;
int result[30005];

int nrz(int x) {
    return x & (~x + 1);
}

void update(int x, int v) {
    while (x <= n ) {
        aib[x] += v;
        x += nrz(x);
    }
}

int query(int x) {
    int result = 0;

    while (x > 0) {
        result += aib[x];
        x -= nrz(x);
    }

    return result;
}

int binSearch(int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    int q = query(mid);

    if (q == target && (mid == low || query(mid - 1) != target)) {
        return mid;
    }

    if (q >= target) {
        return binSearch(low, mid - 1, target);
    }

    return binSearch(mid + 1, high, target);
}

int main() {

    fin >> n;

    for (int i = 1; i <= n; ++i) {
        int x;
        fin >> x;
        q.push_back({x, i});
    }

    reverse(q.begin(), q.end());

    for (int i = 1; i <= n; ++i) {
        update(i, 1);
    }

    for (auto x: q) {
        int ndx = binSearch(1, n, x.p);
        update(ndx, -1);
        result[ndx] = x.v;
    }

    for (int i = 1; i <= n; ++i) {
        fout << result[i] << "\n";
    }

    return 0;
}
