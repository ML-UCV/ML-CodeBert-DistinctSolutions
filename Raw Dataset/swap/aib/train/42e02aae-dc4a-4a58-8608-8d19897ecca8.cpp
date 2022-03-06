#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>




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

    int sum = 0;

    for(; pos; pos -= pos & -pos)

        sum += aib[pos];

    return sum;

}



int main() {



    string a, b;

    in >> a >> b;



    vector<int> fr(30, 0);

    for(auto it : a)

        fr[it - 'a'] ++;

    for(auto it : b)

        fr[it - 'a'] --;

    bool havesol = 1;

    for(int i = 0; i < 30; i ++)

        if(fr[i] != 0)

            havesol = 0;

    if(!havesol)

        out << -1;

    else {

        a = " " + a;

        b = " " + b;

        vector<deque<int>> pos(30);

        for(int i = 1; i < a.size(); i ++)

            pos[a[i] - 'a'].push_back(i);

        int ans = 0;

        for(int i = 1; i < a.size(); i ++) {

            int j = pos[b[i] - 'a'].front();

            pos[b[i] - 'a'].pop_front();



            ans += (j - 1 - query(j));

            update(1, j, a.size());

        }

        out << ans;

    }



    return 0;

}
