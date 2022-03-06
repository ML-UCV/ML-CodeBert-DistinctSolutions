#include<bits/stdc++.h>




using namespace std;



    ifstream f("cmap.in");

    ofstream g("cmap.out");



vector< pair<long long, long long> > x, y;

vector< pair<long long, long long> > v(100002);



long long getDist(pair<long long, long long> &a, pair<long long, long long> &b)

{

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



long long solve(int st, int dr)

{

    if(dr - st <= 1){

        return 10e18;

    }

    if(dr - st == 2){

        if (y[st] > y[st + 1])

            swap(y[st], y[st + 1]);

        return getDist(x[st], x[st + 1]);

    }

    long long mid = (st + dr) / 2;

    long long result = min(solve(st, mid), solve(mid, dr));



    sort(y.begin() + st, y.begin() + dr);



    long long k = 0;

    for (int i = st; i < dr; i++)

        if (abs(y[i].second - x[mid].first) <= result)

            v[k++] = y[i];

    for (int i = 0; i < k - 1; i++) {

        for (int j = i + 1; j < k && j - i < 8; j++)

            result = min(result, getDist(v[i], v[j]));

    }

    return result;

}



int main()

{

    int n;

    f>>n;

    x.resize(n); y.resize(n);

    for(int i = 0 ; i < n ; i++){

        f>>x[i].first>>x[i].second;

    }



    sort(x.begin(), x.end());



    for(int i = 0 ; i < n ; i++){

        y[i].second = x[i].first;

        y[i].first = x[i].second;

    }



    long long sol = solve(0, n);

    g<<fixed<<setprecision(6)<<sqrt(sol);



    return 0;

}
