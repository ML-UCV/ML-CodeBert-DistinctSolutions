#include <bits/stdc++.h>


using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



const int NMAX = 100000,

          MOD = 9917;



struct elem {

    int poz, val;

};

int N, AIB[NMAX+1];

elem V[NMAX+1];



bool comp(const elem& a, const elem& b) {

    if(a.val == b.val) return a.poz < b.poz;

    else return a.val < b.val;

}



void update(int p) {

    while(p <= N) {

        AIB[p]++;

        p += p & (-p);

    }

}



int query(int p) {

    int s = 0;

    while(p > 0) {

        s += AIB[p];

        p -= p & (-p);

    }

    return s;

}



int main()

{

    int x, nrInv = 0;

    in >> N;

    for(int i = 1; i <= N; i++) {

        in >> x;

        V[i] = {i, x};

    }

    sort(V+1, V+N+1, comp);



    for(int i = 1; i <= N; i++) {

        x = V[i].poz;

        nrInv = (nrInv + x - query(x) - 1) % MOD;

        update(x);

    }



    out << nrInv;

    return 0;

}
