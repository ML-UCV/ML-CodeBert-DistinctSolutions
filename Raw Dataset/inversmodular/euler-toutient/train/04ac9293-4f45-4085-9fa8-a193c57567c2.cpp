#include <iostream>
#include <fstream>




using namespace std;



ifstream x("inversmodular.in");

ofstream y("inversmodular.out");



long long a,n;



long long get(long long M)

{

    long long cr=M;

    for(long long i=2;i*i<=M;++i)

    {

        if(M%i==0)

        {

            while(M%i==0)

            {

                M/=i;

            }

            cr=(cr/i)*(i-1);

        }

    }

    if(M!=1)

    {

        cr=cr/M*(M-1);

    }

    return cr;

}



long long inv(long long N, long long M)

{

    long long nr=N,cr=1,put=get(M)-1;

    for(long long i=1;i<=put;i<<=1)

    {

        if(i&put)

            cr=(cr*nr)%M;

        nr=(nr*nr)%M;

    }

    return cr;

}



int main()

{

    x>>a>>n;

    y<<inv(a,n);

    x.close();

    y.close();

    return 0;

}
