#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <cstring>




using namespace std;



ifstream in("swap.in");

ofstream out("swap.out");



const int NMAX = 50005;

int aib[NMAX];



void update(int toadd, int pos, int n) {

    for(; pos <= n; pos += pos & -pos)

        aib[pos] += toadd;

}



int query(int pos) {

    int ans = 0;

    for(; pos; pos -= pos & -pos)

        ans += aib[pos];

    return ans;

}



int main() {

    string a, b;

    in >> a >> b;



    vector<int> fr(30, 0);

    for(int i = 0; i < a.size(); i ++)

        fr[a[i] - 'a'] ++;

    for(int i = 0; i < b.size(); i ++)

        fr[b[i] - 'a'] --;

    bool havesol = 1;

    for(int i = 0; i < 30; i ++)

        if(fr[i] != 0)

            havesol = 0;



    if(havesol) {

        vector<deque<int>> pos(30);

        a = " " + a;

        b = " " + b;

        for(int i = 1; i < a.size(); i ++) {

            pos[a[i] - 'a'].push_back(i);

            update(1, i, a.size());

        }



        int ans = 0;

        for(int i = 1; i < a.size(); i ++) {

            int x = pos[b[i] - 'a'].front();

            pos[b[i] - 'a'].pop_front();



            ans += (query(x) - 1);

            update(-1, x, a.size());

        }

        out << ans;



    } else {

        out << -1;

    }



    return 0;

}
