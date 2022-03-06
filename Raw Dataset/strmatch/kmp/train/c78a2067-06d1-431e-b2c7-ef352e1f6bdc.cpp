#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

using ll = long long;

using pii = pair<int, int>;

using pll = pair<ll, ll>;



template <typename T>

ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }

template <typename A, typename B>

ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }



const int INF = INT_MAX;

const int MOD = 1e9 + 7;

const double EPS = 1e-9;

const double PI = acos(-1);



ll n, ans, t;
namespace KMP {

    vector<int> pattern_prefix(string pattern, int n) {

        vector<int> res(n, 0);



        int i = 0, j = 1;

        while (j < n) {

            if (pattern[i] == pattern[j]) {

                res[j] = i + 1;

                i++, j++;

            } else {

                if (i != 0) {

                    i = res[i - 1];

                } else {

                    res[j] = 0;

                    j++;

                }

            }

        }



        return res;

    }





    bool check(string pattern, string text) {

        if (pattern.length() > text.length() or (pattern.length() == text.length() and pattern != text))

            return false;

        return true;

    }





    vector<int> match(string pattern, int n, string text, int m) {

        vector<int> res;



        vector<int> pref_suf = pattern_prefix(pattern, n);

        int i = 0, j = 0;

        while (j < m) {

            if (pattern[i] == text[j]) {

                i++, j++;

                if (i == n) {

                    res.push_back(j - n);

                    i = pref_suf[i - 1];

                }

            } else {

                if (i != 0) {

                    i = pref_suf[i - 1];

                } else {

                    j++;

                }

            }

        }



        return res;

    }

}



int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ifstream cin("strmatch.in");

    ofstream cout("strmatch.out");



    string a, b;

    cin >> a >> b;

    int n = (a).length(), m = (b).length();



    if (not KMP::check(a, b)) {

        cout << 0 << "\n";

        return 0;

    }



    vector<int> ans = KMP::match(a, n, b, m);



    cout << ans.size() << "\n";

    for (int i = 0; i < min(1000, (int) ans.size()); i++)

        cout << ans[i] << " ";



    return 0;

}
