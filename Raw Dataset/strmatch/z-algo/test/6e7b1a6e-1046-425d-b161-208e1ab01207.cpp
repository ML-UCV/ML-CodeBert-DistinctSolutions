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

    b = a + b;

    int m = b.size() - 1, n = a.size() - 1;



    vector<int> z(m + 1, 0);

    int r = 0, l = 0;

    int cnt = 0;

    vector<int> ans;

    for(int i = 2; i <= m; i ++) {

        if(i <= r)

            z[i] = min(r - i + 1, z[i - l + 1]);

        while(z[i] + i <= m && b[z[i] + 1] == b[i + z[i]])

            z[i] ++;



        if(z[i] + i - 1 > r) {

            r = z[i] + i - 1;

            l = i;

        }



        if(i > n && z[i] >= n) {

            cnt ++;

            if(ans.size() < 1000)

                ans.push_back(i - 1 - n);

        }

    }

    out << cnt << "\n";

    for(auto it : ans)

        out << it << " ";



    return 0;

}
