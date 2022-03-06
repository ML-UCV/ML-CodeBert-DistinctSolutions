#include <iostream>
#include <fstream>


using namespace std;



long long a,n,rez,p;



long long indicator()

{

    rez=n;

    if(n%2==0)

    {

        while(n%2==0)

            n/=2;

        rez/=2;

    }

    for(long long i=3;i*i<=n;i+=2)

        if(n%i==0)

        {

            rez=rez/i*(i-1);

            while(n%i==0)

                n/=i;

        }

    if(n!=1)

        rez=rez/n*(n-1);

}



void putere()

{

    ofstream fout("inversmodular.out");

    long long sol=1;

    while(rez)

    {

        if(rez%2)

        {

            rez--;

            sol=(sol*a)%p;

        }

        else

        {

            rez/=2;

            a=(a*a)%p;

        }

    }

    while(sol<0)

        sol=(sol+n)%p;

    fout<<sol%p;

}



int main()

{

    ifstream fin("inversmodular.in");

    fin>>a>>n;

    p=n;

    indicator();

    rez--;

    putere();

    return 0;

}
