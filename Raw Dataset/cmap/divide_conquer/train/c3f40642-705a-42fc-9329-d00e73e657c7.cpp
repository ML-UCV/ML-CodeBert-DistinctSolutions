#include<bits/stdc++.h> 

using namespace std;





int const N = 100010;
long long const oo = ((long long )1 << 60);

pair<int,int> puncte[N], vec[N];
int n;


long long dist( pair<int,int> A, pair<int,int> B)
{
    return ((long long )B.first - A.first) * (B.first-A.first) + ((long long ) B.second - A.second) * (B.second - A.second);
}

long long dETi(int st, int dr)
{
    if(st == dr)
        return oo;
    if(st == dr - 1)
        return dist(puncte[st], puncte[dr]);

    int mij = (st + dr)/2, k = 0, i, j;
    long long x = dETi(st, mij);
    long long y = dETi(mij + 1, dr);
    long long mini = min(x, y);

    for(i = st; i <= dr; i++)
        if(abs(puncte[i].first - puncte[mij].first) < mini)
            vec[++k] = {puncte[i].second, puncte[i].first};

    sort(vec + 1, vec + k + 1);

    for(i = 1; i < k; i++)
        for(j = i + 1; j <= k && j <= i + 8; j++)
            mini = min(mini, dist(vec[i], vec[j]));

    return mini;
}


int main()
{
 ifstream in("cmap.in");
 ofstream out("cmap.out");



    int i, x, y;

    in >> n;

    for(i=1; i<=n; i++){
        in >> x >> y;
        puncte[i] = make_pair(x, y);
    }

    sort(puncte + 1, puncte + n + 1);

    in.close();

    out << fixed << setprecision(6) << sqrt(dETi(1, n)) << "\n";

    out.close();

    return 0;
}
