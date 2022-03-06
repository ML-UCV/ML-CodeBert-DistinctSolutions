#include <fstream>


using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



long long interclasare(long long v[], long long a, long long m, long long b)

{

    long long i = a, j = m + 1, k = 0, r[100000], t, nr = 0;

    while(i <= m && j <= b)

    {

        if(v[i] <= v[j])

            r[++k] = v[i++];

        else if(v[j] < v[i])

        {

            r[++k] = v[j++];

            nr += m - i + 1;

        }

    }

    for(t = i; t <= m; t++)

        r[++k] = v[i++];

    for(t = j; t <= b; t++)

        r[++k] = v[j++];

    k = 1;

    for(t = a; t <= b; t++)

        v[t] = r[k++];

    return nr;

}



long long divide_et_impera(long long v[], long long st, long long dr)

{

    long long m = (dr + st) / 2, nr = 0;

    if(st < dr)

    {

        nr += divide_et_impera(v, st, m);

        nr += divide_et_impera(v, m + 1, dr);

        nr += interclasare(v, st, m, dr);

    }

    return nr;

}



int main()

{

    long long n, i;

    f >> n;

    long long v[100000];

    for(i = 1; i <= n; i++)

        f >> v[i];

    g << divide_et_impera(v, 1, n) % 9917;

    return 0;

}
