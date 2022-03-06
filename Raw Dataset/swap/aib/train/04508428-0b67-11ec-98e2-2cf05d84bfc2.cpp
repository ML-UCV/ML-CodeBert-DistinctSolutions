#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cstring>
#include <string>


using namespace std;







vector <deque <int> > Veq;

string sir1, sir2;

vector <int> freq, aib;



void update(int pos) {

    for(;pos < 50005; pos += pos & (-pos)) {

        aib[pos]++;

    }

}



int query(int pos) {

    int ans = 0;



    for(;pos;pos -= pos & (-pos)) {

        ans += aib[pos];

    }



    return ans;

}



int main() {

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);



    cin >> sir1;

    cin >> sir2;



    int lg1 = sir1.length();

    int lg2 = sir2.length();



    if(lg1 != lg2) {

        cout << -1 << '\n';

        return 0;

    }



    freq.resize(30);

    for(int i = 0; i < lg1; ++i) {

        freq[sir1[i] - 'a']++;

        freq[sir2[i] - 'a']--;

    }



    for(int i = 0; i < 26; ++i) {

        if(freq[i] != 0) {

            cout << -1 << '\n';

            return 0;

        }

    }



    Veq.resize(30);

    aib.resize(50005);



    for(int i = 0; i < lg1; ++i) {

        Veq[sir1[i] - 'a'].push_back(i);

    }



    int ans = 0;

    for(int i = 0; i < lg2; ++i) {

        ans += max(0, Veq[sir2[i] - 'a'].front() - query(1 + Veq[sir2[i] - 'a'].front()));

        update(Veq[sir2[i] - 'a'].front() + 1);

        Veq[sir2[i] - 'a'].pop_front();

    }



    cout << ans << '\n';



    return 0;

}
