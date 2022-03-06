#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
using namespace std;
vector < pair <long long, long long> > V(100005), X, Y;



long long dist(const pair <long long, long long > &a, const pair <long long, long long> &b) {

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



long long go(int st, int dr, vector < pair <long long, long long > >& X, vector < pair <long long , long long > >& Y) {





         if (dr - st == 1 )

    {

        if (Y[st] > Y[st + 1])

        swap(Y[st], Y[st + 1]);

        return dist(X[st], X[st + 1]);





    }



        if (dr - st == 2)

    {

        sort(Y.begin() + st ,Y.begin() + dr + 1);



        return min(dist(X[st], X[st + 1]),min(dist(X[st],X[dr]),dist(X[st+1],X[dr])));

    }







    int mid = (st + dr + 1) / 2;



    long long solution1=go(st, mid, X, Y);

    long long solution2=go(mid, dr, X, Y);

    long long solution=min(solution1,solution2);







    merge(Y.begin() + st, Y.begin() + mid, Y.begin() + mid, Y.begin() + dr + 1 , V.begin());

    copy(V.begin(), V.begin() + (dr - st) + 1, Y.begin() + st);







    int v_size = 0;

    for (int i = st; i <= dr; ++ i) if (abs(Y[i].second - X[mid].first) <= solution)

        V[v_size ++] = Y[i];



    for (int i = 0; i < v_size - 1; ++ i) {

        for (int j = i + 1; j < v_size && j - i < 8; ++ j)

            solution = min(solution, dist(V[i], V[j]));

    }

    return solution;

}



int main(void) {

    int n;

    ifstream in("cmap.in");

    in>>n;



    X.resize(n), Y.resize(n);

    for (int i = 0; i < X.size(); ++ i)

        in>>X[i].first>>X[i].second;



    in.close();



    sort(X.begin(), X.end());

    for (int i = 0; i < X.size(); ++ i)

        Y[i] = make_pair(X[i].second, X[i].first);



    ofstream out("cmap.out");



    out << fixed << setprecision(6) << sqrt(go(0, X.size() - 1, X, Y)) << "\n";

    out.close();

    return 0;

}
