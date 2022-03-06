#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

ifstream in("inversmodular.in");
ofstream out("inversmodular.out");



int mod(unsigned long long int a, unsigned long long int b, unsigned long long int modulo )
{
    return ((a%modulo)*(b%modulo))%modulo;

}

int totient(unsigned long long int n)
{
    int tot =n;
    for(unsigned long long int i =2 ; i*i <= n ; i++ )
    {
        if(n%i==0)
            tot -= tot/i;
        while(n%i == 0)
            n /=i;

    }

    if (n > 1)
        tot -=tot/n;

    return tot;

}

int main ( )
{
    unsigned long long int a,n,modulo,base=a,res=1 ;

    in>>base>>n;
    modulo = n;
    unsigned long long int powertot = totient(n)-1;

    while(powertot)
    {
        if(powertot&1)
            res= mod(res,base, modulo);

        base = mod(base,base, modulo);
        powertot >>=1;
    }
    out<<res;

    return 0;
}
