#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");







long long A,N,E,Sol;



void EulerTotient(long long n, long long &ans)

{

    ans=1;

    long long d=2,p=0;

    while(n>1)

        {

            p=0;

            while(n%d==0)

                {

                    n/=d;

                    p++;

                }

            if(p)

                {

                    ans=ans*(d-1);

                    for(int i=1;i<p;i++)

                        ans*=d;

                }

            d++;

            if(n>1 && d*d>n)

                d=n;

        }

}



void Pow(long long a, long long power)

{

    if(power<=1)

        {

            if(power==1)

                Sol=a;

            else

                Sol=0;

            return;

        }

    else

        {

            if(power%2==0)

                {

                    Pow(a,power/2);

                    Sol=(Sol*Sol)%N;

                }

            else

                {

                    Pow(a,power-1);

                    Sol=(Sol*a)%N;

                }

        }

}



int main()

{

    fin>>A>>N;

    EulerTotient(N,E);

    Pow(A,E-1);

    fout<<Sol<<'\n';

}
