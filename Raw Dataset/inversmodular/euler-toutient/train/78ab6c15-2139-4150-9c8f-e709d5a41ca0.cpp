#include <fstream>


using namespace std;



int GetPhi(int x)

{

    int phi = x;



    for(int i = 2; i * i <= x; i++)

        if(x % i == 0)

        {

            phi = (phi / i) * (i - 1);



            while(x % i == 0)

                x /= i;

        }



    if(x != 1)

        phi = (phi / x) * (x - 1);



    return phi;

}



int RidPut(int base, int exp, int mod)

{

    int sol = 1;

    int aux = base % mod;



    for(long long i = 1; i <= exp; i <<= 1)

    {

        if(i & exp)

            sol = 1LL * sol * aux % mod;



        aux = 1LL * aux * aux % mod;

    }



    return sol;

}



int main()

{

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");



    int A, N;



    fin >> A >> N;



    int phi = GetPhi(N);

    fout << RidPut(A, phi - 1, N);



    return 0;

}
