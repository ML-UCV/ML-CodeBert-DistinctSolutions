#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <assert.h>
#include <fstream>






using namespace std;

using ll = long long;





ifstream cin("strmatch.in"); ofstream cout("strmatch.out");
vector <int> ans;







void rabin_karp(string const& s, string const& t) {

    const long long p = 167;

    int S = s.size(), T = t.size();



    unsigned long long pow = 1;

    for (auto x : s) pow *= p;



    vector<long long> h(T + 1);

    for (int i = 0; i < T; i++)

        h[i + 1] = h[i] * p + t[i];

    long long h_s = 0;

    for (int i = 0; i < S; i++)

        h_s = h_s * p + s[i];



    vector<int> occurences;

    for (int i = 0; i + S - 1 < T; i++) {

        long long cur_h = h[i + S] - h[i] * pow;

        if (cur_h == h_s)

            ans.push_back(i);

    }

}







int main() {



    string a, b; cin >> a >> b;





    rabin_karp(a, b);



    cout << ans.size() << '\n';

    for (int i = 0; i < min((int)ans.size(), 1000); i++) {

        cout << ans[i] << ' ';

    }



    return 0;

}
