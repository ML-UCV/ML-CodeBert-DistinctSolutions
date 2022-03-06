#include <bits/stdc++.h>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int n, aib[100005];

pair <int, int> a[100005];



inline void update(int pos)

{

    for (; pos <= n; pos += (pos & -pos))

        aib[pos]++;

}



inline int Querry(int pos)

{

    int s = 0;

    for (; pos; pos -= (pos & -pos))

        s += aib[pos], s %= 9917;

    return s;

}



int main()

{

    fin >> n;

    for (int i = 1; i <= n; i++)

        fin >> a[i].first, a[i].second = i;

    sort(a + 1, a + n + 1);

    int ans = 0;

    for (int i = n; i; i--)

    {

        ans += Querry(a[i].second);

        update(a[i].second);

    }

    fout << ans % 9917;

    return 0;

}
