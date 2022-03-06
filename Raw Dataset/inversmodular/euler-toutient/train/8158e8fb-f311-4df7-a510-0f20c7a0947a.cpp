#include <bits/stdc++.h>


using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



int A, N;



int Fi(int n)

{

    int d;

    int fi;

    fi = n;

    d = 2;

    while (n > 1 && d * d <= n)

    {

        if (n % d == 0)

        {

            fi = (fi / d) * (d - 1);

            while (n % d == 0)

                n /= d;

        }

        d++;

    }

    if (n > 1)

        fi = fi / n * (n - 1);



    return fi;

}



int PutLog(int a, int n, int modulo)

{

    long long rez = 1;

    while (n != 0)

    {

        if (n % 2 == 1)

            rez = (1LL * rez * a) % modulo;

        n /= 2;

        a = (1LL * a * a) % modulo;

    }

    return rez;

}



int main()

{

    int fi, prod;

    fin >> A >> N;



    fi = Fi(N) - 1;



    prod = PutLog(A, fi, N);



    fout << prod << "\n";

    fin.close();

    fout.close();

    return 0;

}
