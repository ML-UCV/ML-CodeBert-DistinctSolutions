#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>




using namespace std;



typedef long long ll;



ifstream in("inv.in");

ofstream out("inv.out");



const int MOD = 9917;

const int NMAX = 100005;



int aib[NMAX];



void update(int pos, int n) {

    for(; pos <= n; pos += pos & (-pos))

        aib[pos] ++;

}



int query(int pos) {

    int ans = 0;

    for(; pos; pos -= pos & (-pos))

        ans += aib[pos];

    return ans;

}



int main() {

    int n;

    in >> n;

    vector<pair<int, int> > v(n + 1, {0, 0});

    for(int i = 1; i <= n; i ++) {

        in >> v[i].first;

        v[i].second = i;

    }

    sort(v.begin() + 1, v.end());



    vector<int> tonorm(n + 1, 0);

    for(int i = 1; i <= n; i ++)

        tonorm[v[i].second] = i;



    int ans = 0;

    for(int i = 1; i <= n; i ++) {

        ans = (ans + query(n) - query(tonorm[i])) % MOD;

        update(tonorm[i], n);

    }

    out << ans;

    return 0;

}
