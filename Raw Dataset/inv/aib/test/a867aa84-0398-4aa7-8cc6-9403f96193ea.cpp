#include <bits/stdc++.h>






using namespace std;





ifstream fin("inv.in");

ofstream fout("inv.out");
int n;

int aib[100010];

int a[100010];

int b[100010];



int cb(int val, int left, int right) {

    if(left > right) {

        return -1;

    }

    int mijl = (left+right) / 2;

    if(b[mijl] == val && b[mijl -1] < val) {

        return mijl;

    }

    if(b[mijl] < val) {

        return cb(val, mijl + 1, right);

    } else {

        return cb(val, left, mijl);

    }

}



void adauga(int x) {

    for(int i = x; i <= n; i += i & (-i)) {

        aib[i]++;

    }

}



int scoate(int x) {

    int sol = 0;

    for(int i=x; i >= 1; i -= i & (-i)) {

        sol += aib[i];

    }

    return sol;

}



void solve() {

    fin >> n;



    for(int i=1; i <=n; i++) {

        fin >> a[i];

        b[i] = a[i];

    }

    sort(b + 1, b + n + 1);



    int sol = 0;



    for(int i=1; i <= n; i++) {

        int x =cb(a[i], 1, n);

        sol = (sol + i - 1 - scoate(x)) % 9917;

        adauga(x);

    }

    fout << sol;

}





int main() {

    ios_base::sync_with_stdio(0);

    fin .tie(0);

    fout.tie(0);



    int testCases = 1;



    while(testCases--) {

        solve();

    }

}
