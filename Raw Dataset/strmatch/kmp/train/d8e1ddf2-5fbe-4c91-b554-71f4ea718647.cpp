#include <bits/stdc++.h>


using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");



string a,b;

int pi[2000005], poz[2000],nr,n,m;

void prefix()

{

    int q = 0;

    pi[1] = 0;

    for(int i = 2; i <= n; ++i)

    {

        while(q && a[q+1] != a[i])

           q = pi[q];

        if(a[q+1] == a[i])

            ++q;

        pi[i] = q;

    }

}

void pattern()

{

    int q = 0;

    for(int i = 1; i <= m; ++i)

    {

        while(q && a[q+1] != b[i])

           q = pi[q];

        if(a[q+1] == b[i])

            ++q;

        if(q == n)

        {

            q = pi[n];

            ++nr;

            if(nr <= 1000)

                poz[nr] = i - n;

        }

    }

}

int main()

{

    in >> a >> b;

    n = a.size();

    m = b.size();

    for(int i = n; i > 0; --i) a[i] = a[i-1];

    for(int i = m; i > 0; --i) b[i] = b[i-1];

    a[0] = ' ';

    b[0] = ' ';

    prefix();

    pattern();

    out << nr << '\n';

    for(int i = 1; i <= min(nr,1000); ++i)

        out << poz[i] << " ";

    return 0;

}
