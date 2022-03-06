#include <bits/stdc++.h>




using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int ans[30000 + 5], v[30000 + 5], n, Sum[30000 + 5];



void Update(int i, int j)

{

    for (int k = i; k <= n; k += (k ^ (k & (k - 1))))

        Sum[k] += j;

}



int Query(int i)

{

    int rez = 0;

    for (int k = i; k >= 1; k -= (k ^ (k & (k - 1))))

        rez += Sum[k];

    return rez;

}



int main()

{

    fin >> n;

    for (int i = 1; i <= n; ++i)

        fin >> v[i], Update(i, 1);

    for (int i = n; i >= 1; --i)

    {

        int st = 1, dr = n, sol = -1;

        while (st <= dr)

        {

            int mid = (st + dr) / 2;

            if (Query(mid) >= v[i])

            {

                sol = mid;

                dr = mid - 1;

            }

            else

            {

                st = mid + 1;

            }

        }

        Update(sol, -1);

        ans[sol] = i;

    }

    for (int i = 1; i <= n; ++i)

        fout << ans[i] << "\n";

    fin.close();

    fout.close();

    return 0;

}
