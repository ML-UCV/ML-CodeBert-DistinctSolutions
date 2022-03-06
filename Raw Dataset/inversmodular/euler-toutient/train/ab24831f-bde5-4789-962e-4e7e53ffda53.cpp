#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long A,N,EulerTotient;

long long Phi(long long L)

{

    long long Prod=1;

    for(int i=2; i*i<=L; i++)

        if(L%i==0)

        {

            Prod=Prod*(i-1);

            L/=i;

            while(L%i==0)

            {

                Prod*=i;

                L/=i;

            }

        }



    if(L!=1)

        Prod*=(L-1);



    return Prod;

}

long long logPow()

{

    long long rez=1;

    while(EulerTotient)

    {

        if(EulerTotient%2)

            rez=(rez*A)%N;

        A=(A*A)%N;

        EulerTotient/=2;

    }

    return rez%N;

}

int main()

{

    f>>A>>N;

    EulerTotient=Phi(N)-1;

    g<<logPow();



    return 0;

}
