#include <bits/stdc++.h>


using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

const int nmax = 100005;

const int mod = 9917;

int n, v[nmax], L[nmax], R[nmax], temp[nmax], ans;



void solve(int st, int dr)

{

    if(st < dr)

    {

        int mid = (st + dr) / 2;

        solve(st, mid);

        solve(mid + 1, dr);

        int l1 = 0, l2 = 0;

        for(int i = st; i <= mid; ++i)

            L[++l1] = v[i];

        for(int i = mid + 1; i <= dr; ++i)

            R[++l2] = v[i];

        int a = 1, b = 1, l = 0;

        while(a <= l1 && b <= l2)

        {

            if(L[a] > R[b])

            {

                ans = (ans + l2 - b + 1) % mod;

                temp[++l] = L[a++];

            }

            else

                temp[++l] = R[b++];

        }

        while(a <= l1)

            temp[++l] = L[a++];

        while(b <= l2)

            temp[++l] = R[b++];

        for(int i = st, j = 1; i <= dr; ++i, ++j)

            v[i] = temp[j];

    }

}

int main()

{

    fin >> n;

    for(int i = 1; i <= n; ++i)

        fin >> v[i];

    solve(1, n);

    fout << ans << "\n";

    return 0;

}
