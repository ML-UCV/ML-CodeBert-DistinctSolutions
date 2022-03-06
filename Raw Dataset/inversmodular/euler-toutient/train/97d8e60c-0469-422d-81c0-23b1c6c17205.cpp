#include <fstream>


using namespace std;



int GetPhi(int X)

{

    int phi = X;



    for(int i = 2; i * i <= X; i++)

        if(X % i == 0)

        {

            phi = (phi / i) * (i - 1);



            while(X % i == 0)

                X /= i;

        }



    if(X != 1)

        phi = (phi / X) * (X - 1);



    return phi;

}



int RidPut(int base, int exp, int mod)

{

    int ans = 1;

    int aux = base % mod;



    for(long long i = 1; i <= exp; i <<= 1)

    {

        if(i & exp)

            ans = 1LL * ans * aux % mod;



        aux = 1LL * aux * aux % mod;

    }



    return ans;

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
