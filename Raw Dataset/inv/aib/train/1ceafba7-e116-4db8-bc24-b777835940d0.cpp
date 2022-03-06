#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;



const int INF = 2e9;

const int N = 1e5;

const int MOD = 9917;



int n;



class AIB {

    private:

        int a[5 + N];



        int lsb(int i) {

            return (i & (-i));

        }



    public:

        void Update(int pos) {

            for(int i = pos; i <= n; i += lsb(i))

                a[i]++;

        }



        int Query(int pos) {

            int s(0);



            for(int i = pos; i >= 1; i -= lsb(i))

                s += a[i];

            return s;

        }

};

AIB Fenw;

pair <int, int> v[5 + N];



bool cmp(pair <int, int> a, pair <int, int> b) {

    if(a.first == b.first) return a.second < b.second;

    return a.first < b.first;

}



int main() {

    freopen("inv.in", "r", stdin);

    freopen("inv.out", "w", stdout);



    int inv(0), nr;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {

        scanf("%d", &nr);

        v[i] = make_pair(nr, i);

    }

    sort(v + 1, v + n + 1);



    for(int i = n; i >= 1; i--) {

        inv += Fenw.Query(v[i].second);

        Fenw.Update(v[i].second);



        inv %= MOD;

    }



    printf("%d\n", inv);

    return 0;

}
