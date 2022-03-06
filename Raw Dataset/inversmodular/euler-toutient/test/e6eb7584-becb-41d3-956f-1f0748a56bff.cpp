#include <iostream>
#include <fstream>


using namespace std;

long long n,rez,a,x=1,p;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long putere()

{

   while(rez)

   {

       if(rez%2==1)

       {

           x=(x*a)%p;

           rez--;

       }

       else

       {

           rez/=2;

           a=(a*a)%p;

       }

   }

   return x%n;

}

void desc(int n)

{

    rez=n;

    if(n%2==0)

        rez=rez/2;

    while(n%2==0)

    {

        n/=2;

    }

    for(long long d=3; d*d<=n; d+=2)

    {

        if(n%d==0)

            rez=(rez/d)*(d-1);

        while(n%d==0)

        {

            n/=d;

        }

    }

    if(n!=1)

        rez=(rez/n)*(n-1);

}

int main()

{

    fin>>a>>n;

    p=n;

    desc(n);

    rez--;

    fout<<putere()%p;

    return 0;

}
