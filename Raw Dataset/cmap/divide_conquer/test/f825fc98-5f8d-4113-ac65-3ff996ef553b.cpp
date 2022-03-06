#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>


using namespace std;

ifstream f("cmap.in");
ofstream g("cmap.out");

int const NMax = 100005;
long long const oo = 1LL*1<<60;

pair <int, int> P[NMax], Aux[NMax];
int n;

void Read()
{
    int i, x, y;

    f>>n;
    for(i=1; i<=n; i++){
        f>>x>>y;
        P[i] = make_pair(x, y);
    }
    sort(P + 1, P + n + 1);
}

long long dist(pair<int, int> A, pair<int, int> B)
{
    return 1LL*(B.first-A.first)*(B.first-A.first)+1LL*(B.second-A.second)*(B.second-A.second);
}

long long DEI(int st, int dr)
{
    if(st == dr)
        return oo;
    if(st == dr - 1)
        return dist(P[st], P[dr]);

    int mid = (st + dr)/2, k = 0, i, j;
    long long a = DEI(st, mid);
    long long b = DEI(mid+1, dr);
    long long mini = min(a, b);

    for(i=st; i<=dr; i++)
        if(abs(P[i].first - P[mid].first) < mini)
            Aux[++k] = make_pair(P[i].second, P[i].first);

    sort(Aux + 1, Aux + k + 1);

    for(i = 1; i<k; i++)
        for(j = i+1; j<=k && j<=i+8; j++)
            mini = min(mini, dist(Aux[i], Aux[j]));

    return mini;
}

int main()
{
    Read();
    g<<fixed<<setprecision(6)<<sqrt(DEI(1, n))<<"\n";
    return 0;
}
