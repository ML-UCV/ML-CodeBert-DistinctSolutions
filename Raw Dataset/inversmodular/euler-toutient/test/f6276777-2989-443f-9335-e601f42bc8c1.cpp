#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int Phi(int n)

{

    int sol = n , i;

    for (i = 2 ; i * i <= n && n > 1 ; i++)

    {

        if (n % i == 0)

            sol = sol / i * (i - 1);

        while (n % i == 0)

            n /= i;

    }

    if (n > 1) sol = sol / n * (n - 1);

    return sol;

}



long long log(int a , int n , int mod)

{

    long long p = 1;

    while (n > 0)

    {

        if (n % 2 == 1) p = 1LL*p * a % mod;

        n /= 2;

        a = 1LL*a * a % mod;

    }

    return p;

}



int main()

{

    cout << Phi(12);

    int a , n;

    fin >> a >> n;

    fout << log(a , Phi(n) - 1 , n);

    return 0;

}
