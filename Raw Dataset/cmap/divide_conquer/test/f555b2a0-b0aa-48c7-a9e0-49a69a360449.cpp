#include <bits/stdc++.h>






using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



int N;

pair<long long, long long> X[100010], Y[100010], v[100010];



inline long long dist(const pair<long long, long long> &a, const pair<long long, long long> &b)

{

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) ;

}



inline void interclasare(const int &left, const int &middle, const int &right)

{

    int i = left, k = 0;

    int j = middle + 1;



    while(i <= middle && j <= right)

    {

        (X[i].first <= X[j].first) ? (Y[++ k] = X[i ++]) : (Y[++ k] = X[j ++]);

    }

    while(i <= middle)

    {

        Y[++ k] = X[i ++];

    }

    while(j <= right)

    {

        Y[++ k] = X[j ++];

    }

    for(int i = left; i <= right; i ++)

    {

        X[i] = Y[i - left + 1];

    }

}



inline long long closestPoints(int left, int right, pair<long long, long long> X[100010])

{

    if(left >= right - 1)

        return 20000000000000000;



    if(right - left == 2)

    {

        if(X[left] > X[left + 1])

            swap(X[left], X[left + 1]);



        return dist(X[left], X[left + 1]);

    }



    int middle = (left + right) >> 1;

    long long solution = min( closestPoints(left, middle, X), closestPoints(middle, right, X) );



    interclasare(left, middle, right);



    int k = 0;

    for(int i = left; i < right; i ++)

    {

        if( abs(X[i].first - X[middle].first) <= solution)

        {

            v[++k] = X[i];

        }

    }



    for(int i = 1; i < k; i ++)

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



    fout << setprecision(6) << fixed << sqrt( closestPoints(0, N, X) );



    return 0;

}
