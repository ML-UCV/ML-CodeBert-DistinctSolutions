#include <bits/stdc++.h>


using namespace std;
const int MAXN = 100005;



pair<int, int> pct[MAXN];



bool comp(pair<int, int> a, pair<int, int> b){

    return a.second < b.second;

}



long long calc(pair<int, int> a, pair<int, int> b){

    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);

}



long long divide(int st, int dr){

    if(dr - st + 1 <= 3){

        long long ret = 1LL << 60;

        for(int i = st; i <= dr; ++i){

            for(int j = i + 1; j <= dr; ++j)

                ret = min(ret, calc(pct[i], pct[j]));

        }

        return ret;

    }

    int mij = (st + dr) / 2;

    long long mindist = min(divide(st, mij), divide(mij + 1, dr));

    vector<pair<int, int> > Y;

    for(int i = st; i <= dr; ++i){

        if(abs(pct[i].first - pct[mij].first) < mindist)

            Y.push_back(pct[i]);

    }

    sort(Y.begin(), Y.end(), comp);

    for(int i = 0; i < (int)Y.size(); ++i){

        for(int j = i + 1; j < (int)Y.size() && j - i < 8; ++j)

            mindist = min(mindist, calc(Y[i], Y[j]));

    }

    return mindist;

}



int main()

{

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");

    int n;

    fin >> n;

    for(int i = 1; i <= n; ++i)

        fin >> pct[i].first >> pct[i].second;

    sort(pct + 1, pct + n + 1);

    fout << fixed << setprecision(6) << sqrt((long double)divide(1, n));

    return 0;

}
