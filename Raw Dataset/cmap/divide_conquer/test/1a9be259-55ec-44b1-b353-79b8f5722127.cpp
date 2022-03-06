#include <bits/stdc++.h>






using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



pair<long long, long long> X[100010], Y[100010], v[100010], Z[100010];

int N;



inline long long dist(const pair<long long, long long> &a, const pair<long long, long long> &b)

{

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) ;

}



inline void interclasare(const int &left, const int &middle, const int &right)

{

    int i = left, j = middle + 1, k = 0;



    while(i <= middle && j <= right)

    {

        (Z[i] <= Z[j]) ? (Y[++ k] = Z[i ++]) : (Y[++ k] = Z[j ++]);

    }

    while(i <= middle)

        Y[++ k] = Z[i ++];



    while(j <= right)

        Y[++ k] = Z[j ++];



    for(int i = left; i <= right; i ++)

        Z[i] = Y[i - left + 1];

}



inline long long closestPoints(const int &left, const int &right)

{

    if(left >= right)

        return 20000000000000;



    if(right - left + 1 == 2)

    {

        if(Z[left] > Z[left + 1])

            swap(Z[left], Z[left + 1]);



        return dist(X[left], X[left + 1]);

    }



    int middle = (left + right) >> 1;

    long long solution = min(closestPoints(left, middle), closestPoints(middle, right));

    interclasare(left, middle, right);



    int k = 0;



    for(int i = left; i <= right; i ++)

    {

        if( abs(Z[i].second - X[middle].first) <= solution)

        {

            v[++ k] = Z[i];

        }

    }

    for(int i = 1; i <= k; i ++)

    {

        for(int j = i + 1; j <= k && j - i < 8; j ++)

        {

            solution = min(solution, dist(v[i], v[j]));

        }

    }

    return solution;

}



int main()

{

    fin >> N;

    for(int i = 1; i <= N; i ++)

    {

        fin >> X[i].first >> X[i].second;

    }



    sort(X + 1, X + N + 1);

    for(int i = 1; i <= N; i ++)

    {

        Z[i] = make_pair(X[i].second, X[i].first);

    }



    fout << setprecision(6) << fixed << sqrt( closestPoints(1, N) );





    return 0;

}
