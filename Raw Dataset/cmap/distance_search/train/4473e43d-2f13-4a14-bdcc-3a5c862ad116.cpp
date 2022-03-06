#include <bits/stdc++.h>






using namespace std;



ifstream f ("cmap.in");

ofstream g ("cmap.out");



typedef pair <int, int> PI;



constexpr int NMAX = 1e5 + 5;



int N;

PI a[NMAX];



set <PI> R;



void Read ()

{

    f >> N;



    for (int i = 1; i <= N; ++i)

        f >> a[i].first >> a[i].second;



    sort(a+1, a+N+1);

}



double Distance (PI a, PI b)

{

    return sqrt(1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second));

}



void Solve ()

{

    double sol = 2e9;

    int ind_Left = 1;



    for (int i = 1; i <= N; ++i)

    {

        while (!R.empty() && a[i].first - a[ind_Left].first >= sol)

        {

            R.erase({a[ind_Left].second, a[ind_Left].first});



            ++ind_Left;

        }



        int y_Down = a[i].second - (int)(sol);

        int y_Up = a[i].second + (int)(sol);



        set <PI> :: iterator d = R.lower_bound({y_Down, 1e9});

        set <PI> :: iterator u = R.lower_bound({y_Up, 1e9});



        for (set <PI> :: iterator it = d; it != u; ++it)

        {

            PI nr = *it;



            swap(nr.first, nr.second);



            double ans = Distance(nr, a[i]);



            sol = min(sol, ans);

        }



        R.insert({a[i].second, a[i].first});

    }



    g << setprecision(6) << fixed;

    g << sol << '\n';

}



int main()

{

    Read();



    Solve();

    return 0;

}
