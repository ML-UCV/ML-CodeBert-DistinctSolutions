#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>




using namespace std;



const int MOD = 1e9;

const int BASE = 997;



int main() {



    ifstream in("strmatch.in");

    ofstream out("strmatch.out");



    string a, b;

    in >> a >> b;

    a = " " + a;

    b = " " + b;

    int n = a.size() - 1, m = b.size() - 1, needle_hash = 0;

    for(int i = 1; i <= n; i ++)

        needle_hash = (1LL * needle_hash * BASE + 1LL * (a[i] - '0')) % MOD;



    vector<int> p(m + 1, 1);

    for(int i = 1; i <= m; i ++)

        p[i] = (1LL * BASE * p[i - 1]) % MOD;



    vector<int> hs(m + 1, 0);

    int cnt = 0;

    vector<int> ans;

    for(int i = 1; i <= m; i ++) {

        hs[i] = (1LL * hs[i - 1] * BASE + 1LL * (b[i] - '0')) % MOD;

        if(i < n)

            continue;

        int pretender = (MOD + hs[i] - ((1LL * hs[i - n] * p[n]) % MOD)) % MOD;

        if(pretender == needle_hash) {

            cnt ++;

            if(ans.size() < 1000)

                ans.push_back(i - n);

        }

    }

    out << cnt << "\n";

    for(auto it : ans)

        out << it << " ";



    return 0;

}
