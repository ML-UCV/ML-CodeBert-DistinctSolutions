#include <fstream>
#include <cstring>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



char A[2000001], B[2000001];

int NA, NB;

int P = 73;



int MOD1 = 100007;

int MOD2 = 100021;

int hashA1, hashA2, P1, P2;



int sol[200001];



int main()

{



    in >> A >> B;

    NA = strlen(A);

    NB = strlen(B);

    P1 = P2 = 1;

    hashA1 = hashA2 = 0;

    for (int i = 0; i < NA; i++)

    {

        hashA1 = (hashA1 * P + A[i]) % MOD1;

        hashA2 = (hashA2 * P + A[i]) % MOD2;



        if (i != 0)

            P1 = (P1 * P) % MOD1,

            P2 = (P2 * P) % MOD2;

    }



    if (NA > NB)

    {

        out << 0;

        return 0;

    }

    int hash1 = 0, hash2 = 0;

    for (int i = 0; i < NA; i++)

        hash1 = (hash1 * P + B[i]) % MOD1,

        hash2 = (hash2 * P + B[i]) % MOD2;

    int Nr = 0;

    if (hash1 == hashA1 && hash2 == hashA2)

        sol[Nr] = 0, Nr++;



    for (int i = NA; i < NB; i++)

    {

        hash1 = ((hash1 - (B[i - NA] * P1) % MOD1 + MOD1) * P + B[i]) % MOD1;

        hash2 = ((hash2 - (B[i - NA] * P2) % MOD2 + MOD2) * P + B[i]) % MOD2;



        if (hash1 == hashA1 && hash2 == hashA2)

        {

           if(Nr <= 1000)

                sol[Nr] = i-NA+1;

            Nr++;

        }

    }

    if (NA>NB)

        out << "0";

    else {

    out <<Nr<<'\n';

    for (int i = 0; i < min(Nr,1000); ++i)

        out << sol[i] << " ";}

    return 0;

}
