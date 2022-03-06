#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;



const int NMAX = 4e6 + 5;



ifstream cin("strmatch.in");

ofstream cout("strmatch.out");



int z[NMAX];



int main()

{

    string a, b;

    cin >> a >> b;

    string s = a;

    s += "#";

    s += b;

    int r = 0, pozr = 0;

    for(int i = 1; i < s.size(); ++i) {

        if(i > r) {

            while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) {

                z[i]++;

            }

        } else {

            int rest = min(z[i - pozr], r - i);

            z[i] = rest;

            while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) {

                z[i]++;

            }

        }

        if(i + z[i] > r) {

            r = i + z[i];

            pozr = i;

        }

    }

    int cnt = 0;

    vector <int> sol;

    for(int i = 1; i < s.size(); ++i) {

        if(z[i] == a.size()) {

            cnt++;

            if(cnt <= 1000) {

                sol.push_back(i - a.size() - 1);

            }

        }

    }

    cout << cnt << "\n";

    for(auto x: sol) {

        cout << x << " ";

    }

    cout << "\n";

    return 0;

}
