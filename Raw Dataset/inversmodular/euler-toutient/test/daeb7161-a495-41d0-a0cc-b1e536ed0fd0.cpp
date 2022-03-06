#include <iostream>
#include <fstream>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



long long indicatoreuler(long long N)

{

    long long S = N;



    if(N % 2 == 0)

    {

     S /= 2;

     while(N % 2 == 0)

       N /= 2;

    }

    for(long long i = 3; i * i <= N; i++)

    {

        if(N % i == 0)

        {

            S /= i;

            S *= i - 1;

            while(N % i == 0)

                N /= i;

        }

    }

    if(N!=1)

     {

        S /= N;

        S *= N-1;

     }

     return S;

}



long long lgput(long long A, long long S, long long N)

{

  long long rez = 1;

  while(S > 0)

  {

      if(S & 1)

      {

          rez *= A;

          rez %= N;

          S--;

      }

      A *=A;

      A %=N;

      S>>=1;

  }

  return rez;

}

int main()

{

    long long A,N;

    in >> A >> N;

    long long S = indicatoreuler(N);

    S--;

    out << lgput(A, S, N);

    return 0;

}
