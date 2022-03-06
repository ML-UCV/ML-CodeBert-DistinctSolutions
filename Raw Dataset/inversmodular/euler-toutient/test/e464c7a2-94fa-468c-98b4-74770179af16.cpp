#include <fstream>


using namespace std;



ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");

int euler(int n){

     long long d = 2, p, prod = n;

    while ( d * d <= n ) {

        p = 0;

        while ( n % d == 0 ) {

            n /= d;

            p ++;

        }

        if ( p )

            prod = prod / d * ( d - 1 );

        d ++;

    }

    if ( n > 1 )

        prod = prod / n * ( n - 1 );

    return prod;

}

int putere(int a,int n,int m){

    int prod = 1;

    do{

        if(n%2 != 0){

            prod = (long long)prod * a % m;

        }

        a = 1LL * a * a % m;

        n /= 2;

    }while(n != 0);

    return prod;

}

int main()

{

    int a,n,x;

    cin >> a >> n;

    x = putere(a,euler(n) - 1,n);

    cout << x;

    return 0;

}
