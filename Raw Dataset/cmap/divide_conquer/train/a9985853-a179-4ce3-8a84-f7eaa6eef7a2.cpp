#include <bits/stdc++.h>
using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



int N;

const long long INF = unsigned(-1);

pair <long long, long long> A[100010], V[100010];



inline long long euclid(pair <long long, long long> a, pair <long long, long long> b) {

    return (b.second-a.second)*(b.second-a.second) + (b.first-a.first)*(b.first-a.first);

}



long long solve(int st, int dr) {

    long long p, p1, p2;

    if (dr-st == 0) {

        return INF;

    }

    if (dr-st == 1) {

        p = euclid(A[st], A[dr]);

        return p;

    } else if (dr-st == 2) {

        p = min(euclid(A[st], A[st+1]), euclid(A[st+1], A[st+2]));

        p = min(p, euclid(A[st], A[st+2]));

        return p;

    }

    int mid = (st+dr)/2;

    p1 = solve(st, mid);

    p2 = solve(mid+1, dr);

    p = min(p1, p2);

    long long e = A[mid].first;

    int k = 0;

    for(int i = st; i <= dr; ++i) {

        if(abs(A[i].second - e) <= p) {

            V[++k] = A[i];

        }

    }



    for(int i = 1; i <= k; ++i) {

        for(int j = i + 1; j <= k and j - i <= 8; ++j) {

            p = min(p, euclid(V[i],V[j]));

        }

    }

    return p;

}



int main()

{

    fin>>N;

    for(int i = 1; i <= N; ++i) {

        fin>>A[i].first>>A[i].second;

    }

    sort(A+1, A+N+1);

    fout<<fixed<<setprecision(9)<<sqrt(solve(1, N));

    return 0;

}
