#include <bits/stdc++.h>


using namespace std;

typedef long long LL;



LL ridicare(LL baza, LL exp, LL n)

{

    LL ans = 1;



    while(exp)

    {

        if(exp % 2)

            ans = ans * baza % n;



        baza = baza * baza % n;

        exp /= 2;

    }



    return ans;

}



LL phi(LL n)

{

    LL ans = n;



    LL div = 2;



    while(div * div <= n)

    {

        if(n % div == 0)

        {

            while(n % div == 0)

                n /= div;



            ans = ans / div * (div - 1);

        }



        div++;

    }



    if(n > 1)

        ans = ans / n * (n - 1);



    return ans;

}



int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");



    LL a, n;



    fin >> a >> n;

    cout << phi(n);



    fout << ridicare(a, phi(n) - 1, n);



    fin.close();

    fout.close();



    return 0;

}
