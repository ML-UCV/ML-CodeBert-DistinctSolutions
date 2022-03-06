#include <fstream>


using namespace std;



ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");





long long MOD;



long long phi(long long a)

{

    long long ca = a;

    int phi = a;

    if(a % 2 == 0)

        phi /= 2 , phi *= 1;

    while(ca % 2 == 0)

        ca /= 2;

    for(int i = 3; i * i <= a; i+=2)

    {

        if(ca % i == 0)

            phi /= i , phi *= (i - 1);

        while(ca % i == 0)

            ca /= i;

    }

    if(ca > 1)

        phi /= ca , phi *= (ca - 1);

    return phi;





}



long long lgput(long long a , long long b)

{

    long long r = 1;

    while(b > 1)

    {

        if(b % 2)

            r = (r * a) % MOD , b--;

        a = (a * a) % MOD , b/=2;

    }

    a = (a * r) % MOD;

    return a;

}



long long im(long long a)

{

     return lgput(a , phi(MOD) - 1) % MOD;

}



int main()

{

    long long a;

    cin >> a >> MOD;

    cout << im(a);

    return 0;

}
