#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>




using namespace std;



int main() {



    ifstream in("strmatch.in");

    ofstream out("strmatch.out");



    string a, b;

    in >> a >> b;

    a = " " + a;

    b = " " + b;

    int n = a.size() - 1, m = b.size() - 1;



    vector<int> kmp(n + 1, 0);

    int k = 0;

    for(int i = 2; i <= n; i ++) {

        while(k > 0 && a[k + 1] != a[i])

            k = kmp[k];

        if(a[k + 1] == a[i])

            k ++;

        kmp[i] = k;

    }



    int cnt = 0;

    vector<int> ans;

    for(int i = 1; i <= m; i ++) {

        while(k > 0 && a[k + 1] != b[i])

            k = kmp[k];

        if(a[k + 1] == b[i])

            k ++;

        if(k == n) {

            k = kmp[k];

            if(i >= n) {

                cnt ++;

                if(ans.size() < 1000)

                    ans.push_back(i - n);

            }

        }

    }

    out << cnt << "\n";

    for(auto it : ans)

        out << it << " ";



    return 0;

}
