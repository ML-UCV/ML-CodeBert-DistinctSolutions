#include <fstream>
#include <string>
#include <vector>


using namespace std;



const int NMAX = 2e6 + 5;

const long long MOD = 1000000123;

const long long BASE = 62;



ifstream cin("strmatch.in");

ofstream cout("strmatch.out");



long long h2[NMAX];



long long key[150];



void FormKey()

{

    int cnt = 0;

    for(char c = '0'; c <= '9'; ++c) {

        key[c] = ++cnt;

    }

    for(char c = 'a'; c <= 'z'; ++c) {

        key[c] = ++cnt;

    }

    for(char c = 'A'; c <= 'Z'; ++c) {

        key[c] = ++cnt;

    }



}

int main()

{

    FormKey();

    string a, b;

    cin >> a >> b;

    long long h1 = 0, h2 = 0;

    long long p = 1, pk = 1;

    for(auto x: a) {



        h1 = (h1 * BASE + key[x]) % MOD;

        pk = p;

        p = (p * BASE) % MOD;

    }

    p = 1;

    int cnt = 0;

    vector <int> sol;

    for(int i = 0; i < a.size(); ++i) {

        h2 = (h2 * BASE + key[b[i]]) % MOD;

    }

    if(h1 == h2) {

        cnt++;

        sol.emplace_back(0);

    }

    for(int i = a.size(); i < b.size(); ++i) {

        h2 = h2 - key[b[i - a.size()]] * pk % MOD;

        if(h2 < 0)

            h2 += MOD;

        h2 = (h2 * BASE % MOD + key[b[i]]) % MOD;

        if(h1 == h2) {

            cnt++;

            if(cnt <= 1e3) {

                sol.emplace_back(i - a.size() + 1);

            }

        }

    }

    cout << cnt << "\n";

    for(auto x: sol)

        cout << x << " ";

    cout << "\n";

    return 0;

}
