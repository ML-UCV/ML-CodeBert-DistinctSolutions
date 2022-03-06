# include <fstream>
# include <vector>
# include <set>
# include <cmath>
using namespace std;



vector <long long> a[1501];

vector <double> b[1501];

long long n, m, i, j, x, y, sol[1501], ap[1501];

double cost, dm[1501];

set < pair <double, long long> > st;



double modul (double a)

{

    if (a < 0) return a * (-1.0);

    else return a;

}



double rest (double a)

{

    while (a >= 104659.0) a -= 104659.0;

    return a;

}

void dijkstra ()

{

    st.insert (make_pair (1, 1));

    sol[1] = 1;

    dm[1] = 0;

    for (long long i = 2; i <= n; ++i) dm[i] = 2000000000;

    for (; st.size () > 0; )

    {

        double cost = (*st.begin ()).first;

        int nod = (*st.begin ()).second;

        ap[nod] = 0;

        vector <long long> :: iterator it1;

        vector <double> :: iterator it2;

        st.erase ((*st.begin ()));

        for (it1 = a[nod].begin (), it2 = b[nod].begin (); it1 != a[nod].end (); ++it1, ++it2)

            if (dm[*it1] - cost - (*it2) > 0.000001)

            {

                dm[*it1] = rest (cost + (*it2)), sol[*it1] = sol[nod];

                if (!ap[*it1])

                {

                    ap[*it1] = 1;

                    st.insert (make_pair (dm[*it1], (*it1)));

                }

            }

            else

            if (modul (dm[*it1] - cost - (*it2)) < 0.000001)

                sol[*it1] = rest (sol[*it1] + sol[nod]);

    }

}

int main ()

{

    ifstream f ("dmin.in");

    ofstream g ("dmin.out");



    f >> n >> m;

    for (i = 1; i <= m; ++i)

    {

        f >> x >> y >> cost;

        cost = log (cost);

        a[x].push_back (y);

        a[y].push_back (x);

        b[x].push_back (cost);

        b[y].push_back (cost);

    }



    dijkstra ();

    for (i = 2; i <= n; ++i)

        g << sol[i] << ' ';

    g << '\n';

    g.close ();

    return 0;

}
