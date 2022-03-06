#include <bits/stdc++.h>






const int lMax = 2000005;



using namespace std;



char a[lMax], b[lMax];

int lga, k, lgb, ans1;

int pi[lMax];

vector <int> ans2;



main()

{

    ifstream cin("strmatch.in");

    ofstream cout("strmatch.out");



    cin >> a + 1 >> b + 1;

    lga = strlen(a + 1);

    lgb = strlen(b + 1);



    k = 0;



    for (int i = 2; i <= lga; ++i)

    {

        k = pi[i - 1];

        while (k && a[k + 1] != a[i])

            k = pi[k];



        if (a[k + 1] == a[i])

            ++k;

        pi[i] = k;

    }



    k = 0;



    for (int i = 1; i <= lgb; ++i)

    {

        while (k && a[k + 1] != b[i])

            k = pi[k];

        if (a[k + 1] == b[i])

            ++k;

        if (k == lga)

        {

            ++ans1;

            if (ans2.size() < 1000)

                ans2.emplace_back(i - lga);

        }

    }



    cout << ans1 << "\n";

    for (auto i : ans2)

        cout << i << " ";



    return 0;

}
