#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int GetPhi(int x)

{

    int phi = x;



    for(long long i = 2; 1LL * i * i <= x; i++)

        if(x % i == 0)

        {

            phi /= i;

            phi *= (i - 1);



            while(x % i == 0)

                x /= i;

        }



    if(x != 1)

    {

        phi /= x;

        phi *= (x - 1);

    }



    return phi;

}



long long RidPut(int base, int exp, int mod)

{

    long long ans = 1;

    long long aux = base % mod;



    for(long long i = 1; 1LL * i <= exp; i <<= 1)

    {

        if(i & exp)

            ans = (1LL * ans * aux) % mod;



        aux = (1LL * aux * aux) % mod;

    }



    return ans % mod;

}



int main()

{

    int A, N;



    fin >> A >> N;



    int phi = GetPhi(N);



    fout << RidPut(A, phi - 1, N) << '\n';



    return 0;

}
