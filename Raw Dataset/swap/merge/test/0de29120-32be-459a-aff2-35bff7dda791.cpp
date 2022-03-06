#include <bits/stdc++.h>
using namespace std;



typedef pair <int, int> pii;

typedef vector <int> vi;

typedef long long ll;

typedef unsigned long long ull;



ifstream f ("swap.in");

ofstream g ("swap.out");



const int NMAX = 50005;

const int SIGMA = 30;

int v[NMAX], ans;

string s;

queue <int> q[SIGMA];



struct Node {

    int val, lazy;

    Node() {

        val = lazy = 0;

    }

}segmTree[4 * NMAX];



void build (int node, int left, int right) {

    if (left == right) {

        segmTree[node].val = left;

        return;

    }

    int mid = left + (right - left) / 2;

    build (2 * node + 1, left, mid);

    build (2 * node + 2, mid + 1, right);

}



void update (int node, int left, int right, int x, int y) {

    if (x <= left && right <= y) {

        ++segmTree[node].lazy;

        return;

    }

    int mid = left + (right - left) / 2;

    if (x <= mid) {

        update (2 * node + 1, left, mid, x, y);

    }

    if (mid < y) {

        update (2 * node + 2, mid + 1, right, x, y);

    }

}



void propagate (int node, int left, int right) {

    if (segmTree[node].lazy) {

        segmTree[node].val += segmTree[node].lazy;

        if (left != right) {

            segmTree[2 * node + 1].lazy += segmTree[node].lazy;

            segmTree[2 * node + 2].lazy += segmTree[node].lazy;

        }

        segmTree[node].lazy = 0;

    }

}



int query (int node, int left, int right, int pos) {

    propagate (node, left, right);



    if (left == right) {

        return segmTree[node].val;

    }

    int mid = left + (right - left) / 2;

    if (pos <= mid) {

        return query (2 * node + 1, left, mid, pos);

    } else {

        return query (2 * node + 2, mid + 1, right, pos);

    }

}



int main() {

    f >> s;

    int n = s.size();

    for (int i = 0; i < n; ++i) {

        q[s[i] - 'a'].push (i);

    }

    f >> s;

    for (int i = 0; i < n; ++i) {

        if (q[s[i] - 'a'].empty()) {

            g << "-1\n";

            return 0;

        }

        v[i] = q[s[i] - 'a'].front();

        q[s[i] - 'a'].pop();

    }

    build (0, 0, n - 1);

    for (int i = 0; i < n; ++i) {

        ans += query (0, 0, n - 1, v[i]) - i;

        if (v[i] == 0) continue;

        update (0, 0, n - 1, 0, v[i] - 1);

    }



    g << ans << '\n';



    f.close();

    g.close();

    return 0;

}
