#include <iostream>
#include <cstdio>#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;







int N;

vector <pair <long long, long long> > X, Y, V(100005);



long long dist(pair <long long, long long> a, pair <long long, long long> b) {

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



long long solve(int st, int dr, vector <pair <long long, long long> > &X, vector <pair <long long, long long> > &Y) {

    if(st >= dr - 1) {

        return 4e18;

    }



    if(dr - st == 2) {

        if(Y[st] > Y[st + 1]) {

            swap(Y[st], Y[st + 1]);

        }

        return dist(X[st], X[st + 1]);

    }



    int m = (st + dr) / 2;

    long long bst = min(solve(st, m, X, Y), solve(m, dr, X, Y));



    merge(Y.begin() + st, Y.begin() + m, Y.begin() + m, Y.begin() + dr, V.begin());

    copy(V.begin(), V.begin() + (dr - st), Y.begin() + st);



    int ts = 0;

    for(int i = st; i < dr; ++i) {

        if(abs(Y[i].second - X[m].first) <= bst) {

            V[ts++] = Y[i];

        }

    }



    for(int i = 0; i < ts; ++i) {

        for(int j = i + 1; j < ts && j - i < 8; ++j) {

            bst = min(bst, dist(V[j], V[i]));

        }

    }



    return bst;

}



int main() {

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);



    scanf("%d\n", &N);



    int x, y;

    for(int i = 1; i <= N; ++i) {

        scanf("%d %d", &x, &y);



        X.push_back({x, y});

    }



    sort(X.begin(), X.end());



    for(int z = 0; z < N; ++z) {

        Y.push_back({X[z].second, X[z].first});

    }



    cout << setprecision(6) << fixed << sqrt(1.0 * solve(0, X.size(), X, Y)) << '\n';



    return 0;

}
