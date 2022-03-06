#include <fstream>


using namespace std;



ifstream in ("inversmodular.in");

ofstream out("inversmodular.out");



long long n, mod;



long long GetPhi(long long n){

    long long prod = n;

    for(int d = 2; d * d <= n; ++ d){

        if(n % d == 0){

            prod = prod / d;

            prod = prod * (d - 1);

        }

        while(n % d == 0)

            n /= d;

    }

    if(n > 1){

        prod = prod / (n);

        prod = prod * (n - 1);

    }



    return prod;

}



long long LogPow(long long n, long long pow){

    long long aux = 1;

    while(pow){

        if(pow % 2){

            aux = (aux * n) % mod;

            -- pow;

        }

        else{

            n = (n * n) % mod;

            pow /= 2;

        }

    }

    return aux;

}



int main()

{

    in>>n>>mod;

    long long pow = GetPhi(mod) - 1;

    long long answer = LogPow(n, pow);

    out<<answer;

    return 0;

}
