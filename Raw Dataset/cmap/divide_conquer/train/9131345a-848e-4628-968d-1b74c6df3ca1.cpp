#include <bits/stdc++.h>






using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");



typedef long long i64;



int N;

vector<pair<i64, i64>>X;

vector<pair<i64,i64>>Y;

vector<pair<i64, i64>> aux;



i64 Distance(pair<i64, i64> p1, pair<i64, i64> p2)

{

    return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);

}



i64 solve(int left, int right, vector<pair<i64,i64>> &X, vector<pair<i64, i64>> &Y)

{

    if (right - left <= 3)

    {

        i64 answ = 4e18;

        for (int i = left; i < right; ++i)

            for (int j = i + 1; j <= right; ++j)

            {

                if (Y[i] > Y[j])

                    swap(Y[i], Y[j]);

                 answ = min(answ, Distance(X[i], X[j]));

            }

        return answ;

    }



    int mid = (left + right) >> 1;

    i64 best = min(solve(left, mid, X, Y), solve(mid + 1, right, X, Y));



    merge(Y.begin() + left , Y.begin() + mid + 1, Y.begin() + mid + 1, Y.begin() + right + 1, aux.begin());

    copy(aux.begin(), aux.begin() + (right - left + 1), Y.begin() + left);



    int _size = 0;

    for (int i = left; i <= right; ++i)

        if (abs(X[mid].first - Y[i].second) <= best)

            aux[_size++ ] = Y[i];



    for (int i = 0; i < _size - 1; ++i)

        for (int j = i + 1; j < _size && (aux[j].first - aux[i].first) < sqrt(best) ; ++j)

                best = min(best, Distance(aux[i], aux[j]));

    return best;

}



int main()

{

    fin >> N;

    X.resize(N + 1);

    Y.resize(N + 1);

    aux.resize(N + 1);

    for (int i = 1; i <= N; ++i)

        fin >> X[i].first >> X[i].second;



    sort(X.begin(), X.end());

    for (int i = 1;i <= N; ++i)

        Y[i] = {X[i].second, X[i].first};



    fout << fixed << setprecision(6) << sqrt(solve(1, N, X, Y)) << "\n";

    return 0;

}
