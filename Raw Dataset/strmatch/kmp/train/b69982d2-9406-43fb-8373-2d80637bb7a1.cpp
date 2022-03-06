#include <bits/stdc++.h>
using namespace std;
ifstream fin ("strmatch.in");

ofstream fout("strmatch.out");
int n, m;

string a, b;

int dp[2000005];

vector < int > sol;



void init() {

    int j = 0;

    dp[1] = 0;

    for(int i = 2; i <= n; i++) {

        while(j && a[j + 1] != a[i]) {

            j = dp[j];

        }

        if(a[j + 1] == a[i]) {

            j++;

        }

        dp[i] = j;

    }

}



void fao() {

    int j = 0;

    for(int i = 1; i <= m; i++) {

        while(j && a[j + 1] != b[i]) {

            j = dp[j];

        }

        if(a[j + 1] == b[i]) {

            j++;

        }

        if(j == n) {

            j = dp[n];

            sol.push_back(i - n);

        }

    }

}



void solve() {

    fin >> a >> b;

    n = a.size();

    m = b.size();



    a = '.' + a;

    b = '.' + b;



    init();

    fao();



    fout << sol.size() << "\n";

    if(sol.size() <= 1000) {

        for(auto it : sol) {

            fout << it << " ";

        }

    } else {

        for(int i = 0; i < 1000; i++) {

            fout << sol[i] << " ";

        }

    }



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
