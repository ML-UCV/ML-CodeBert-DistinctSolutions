#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int GetPhi(int nr)

{

    int phi = nr;



    for(int i = 2; i * i <= nr; i++)

        if(nr % i == 0)

        {

            phi /= i;

            phi *= (i - 1);



            while(nr % i == 0)

                nr /= i;

        }



    if(nr != 1)

    {

        phi /= nr;

        phi *= (nr - 1);

    }



    return phi;

}



int lgput(int base, int exp, int N)

{

    int ans = 1;

    int aux = base;



    for(long long i = 1; i <= exp; i <<= 1)

    {

        if(i & exp)

            ans = (1LL * ans * aux) % N;



        aux = (1LL * aux * aux) % N;

    }



    return ans;

}



int main()

{

    int A, N; fin >> A >> N;



    int phi = GetPhi(N);



    fout << lgput(A, phi - 1, N);



    return 0;

}
