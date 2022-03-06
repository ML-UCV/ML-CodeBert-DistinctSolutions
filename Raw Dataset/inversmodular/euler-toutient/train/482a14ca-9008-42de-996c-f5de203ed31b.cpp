#include <iostream>
#include <fstream>
using namespace std;





ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



long long n, m, k, l, euler, auxm;



void solve_euler()

{

    euler=m;

    if (m%2==0)

    {

        euler/=2;

        while (m%2==0)

        {

            m/=2;

        }

    }

    int aux=m;

    for (int d=3; d*d<=m; d+=2)

    {

        if (m%d==0)

        {

            euler*=(d-1);

            euler/=d;

            while (m%d==0)

                m/=d;

        }

    }

    if (m>1)

    {

        euler*=(m-1);

        euler/=m;

    }



}



long long ridicare_putere(long long a, long long p)

{

    long long x=a, y=1;

    while (p)

    {

        if (p%2==1)

        {

            y*=x;

            --p;

            y%=auxm;

        }

        else

        {

            x*=x;

            x%=auxm;

            p/=2;

        }

    }

    return y;

}



int main()

{

    f >> n >> m;

    auxm=m;

    solve_euler();

    g << ridicare_putere(n,euler-1);

    return 0;

}
