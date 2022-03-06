#include <bits/stdc++.h>




using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");



const int NMAX = 30005;

int v[NMAX], aint[4 * NMAX];



void update(int pos, int state, int node, int le, int ri) {

    if(le == ri) {

        aint[node] = state;

    } else {

        int mid = (le + ri) / 2;

        if(pos <= mid)

            update(pos, state, node * 2, le, mid);

        else

            update(pos, state, node * 2 + 1, mid + 1, ri);

        aint[node] = aint[node * 2] + aint[node * 2 + 1];

    }

}



int query(int pos, int node, int le, int ri) {

    if(le == ri)

        return le;

    int mid = (le + ri) / 2;

    if(aint[node * 2] >= pos)

        return query(pos, node * 2, le, mid);

    else

        return query(pos - aint[node * 2], node * 2 + 1, mid + 1, ri);

}



int main() {

    int n;

    in >> n;

    for(int i = 1; i <= n; i ++) {

        in >> v[i];

        update(i, 1, 1, 1, n);

    }

    vector<int> sol(n + 1, 0);

    for(int i = n; i >= 1; i --) {

        int pos = query(v[i], 1, 1, n);

        sol[pos] = i;

        update(pos, 0, 1, 1, n);

    }

    for(int i = 1; i <= n; i ++)

        out << sol[i] << "\n";

    return 0;

}
