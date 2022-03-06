#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int a , n;



int phi(int n)

{

    int sol = n, p;

    for(p = 2; n > 1 && p * p <= n; p++)

        if(n % p == 0)

        {

           sol = sol/p * (p - 1);

           while(n % p == 0)

            n /= p;

        }

    if(n > 1) sol = sol / n * (n - 1);

    return sol;

}



int lgput(int a, int n, int modulo)

{

    int p = 1;

    while(n)

    {

        if(n % 2 == 1) p = 1LL * p * a % modulo;

        n /= 2;

        a = 1LL * a * a % modulo;

    }

    return p;



}





int main()

{

    int b;

    fin >> a >> n;

    b = lgput(a, phi(n) - 1, n);

    fout << b;

    return 0;

}
