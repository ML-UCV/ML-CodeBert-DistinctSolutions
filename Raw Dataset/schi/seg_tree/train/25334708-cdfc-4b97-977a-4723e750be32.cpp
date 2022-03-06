#include <fstream>

using namespace std;

const int Nmax = 30005;

int finishes[Nmax];
int segTree[3 * Nmax];
ifstream cin ("schi.in");
ofstream cout ("schi.out");
void build(int node, int left, int right) {
    if (left == right) {
        segTree[node] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(2* node, left, mid);
    build(2*node+1, mid+1, right);
    segTree[node] = segTree[2*node] + segTree[2*node+1];
}

void update(int node, int left, int right, int position) {
    if (left == right) {
        segTree[node] = 0;
        return;
    }
    int mid = (left + right) / 2;
    if (position <= mid) {
        update(2 * node, left, mid, position);
    } else {
        update(2 * node + 1, mid + 1, right, position);
    }
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int query(int node, int left, int right, int value) {
    if (left == right) {
        return left;
    }
    int mid = (left + right) / 2;
    if (value <= segTree[2*node]) {
        return query(2 * node, left, mid, value);
    } else {
        return query(2 * node + 1, mid + 1, right, value - segTree[2 * node]);
    }
}

int leaderboard[Nmax];

int main() {
    int n;
    cin >> n;
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        cin >> finishes[i];
    }
    for (int i = n; i >= 1; --i) {
        int pos = query(1, 1, n, finishes[i]);
        leaderboard[pos] = i;
        update(1, 1, n, pos);
    }
    for (int i = 1; i <= n; ++i) {
        cout << leaderboard[i] << "\n";
    }
    return 0;
}
