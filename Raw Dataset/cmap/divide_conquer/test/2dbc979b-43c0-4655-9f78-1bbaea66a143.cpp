#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>






using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



int n,i;

pair<long long, long long> v[100005],aux[100005];



long long dist(pair<long long, long long> a, pair<long long, long long> b)

{ return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second); }



void interclasare(int st, int mid, int dr)

{

    int i = st; int j = mid+1; int k = 0;

    while (i <= mid && j <= dr)

        if (v[i].second <= v[j].second)

            aux[++k] = v[i++];

        else

            aux[++k] = v[j++];

    for (;i<=mid; i++)

        aux[++k] = v[i];

    for (;j<=dr; j++)

        aux[++k] = v[j];

    for (int i=st; i<=dr; i++)

        v[i] = aux[i-st+1];

}



long long solve(int st, int dr)

{

    int mid = (st+dr)/2;

    if (dr-st == 1)

    {

        interclasare(st, mid, dr);

        return dist(v[st], v[dr]);

    }

    if (dr-st == 2)

    {

        interclasare(st, st, mid); interclasare(st, mid, dr);

        return min(dist(v[st+1], v[st+2]), min(dist(v[st], v[st+1]), dist(v[st], v[st+2])));

    }

    long long sols = solve(st, mid);

    long long sold = solve(mid+1, dr);

    long long sol = min(sols, sold);

    interclasare(st, mid, dr);

    int k = 0;

    for (int i=st; i<=mid; i++)

        if (v[mid].first-v[i].first <= sol)

            aux[++k] = v[i];

    for (int i=mid+1; i<=dr; i++)

        if (v[i].first-v[mid].first <= sol)

            aux[++k] = v[i];

    for (int i=1; i<k; i++)

        for (int j=i+1; j<=min(k, i+7); j++)

            sol = min(sol, dist(aux[i], aux[j]));

    return sol;

}



int main()

{

    fin >> n;

    for (i=1; i<=n; i++)

        fin >> v[i].first >> v[i].second;

    sort(v+1, v+n+1);

    fout << setprecision(7) << fixed << sqrt(solve(1, n));

    return 0;

}
