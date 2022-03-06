#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int Nmax = 2e6 + 5;

const int p = 73;

const int Mod1 = 1e5 + 21;

const int Mod2 = 1e5 + 7;



bitset <Nmax> viz;

char a[Nmax], b[Nmax];



int main()

{

    fin >> a;

    fin >> b;



    int n, m, contor = 0;

    n = strlen(a);

    m = strlen(b);



    int hash_a1 = 0, hash_a2 = 0, pLg1 = 1, pLg2 = 1;



    for(int i = 0; i < n; i++)

    {

        hash_a1 = (hash_a1 * p + a[i]) % Mod1;

        hash_a2 = (hash_a2 * p + a[i]) % Mod2;

        if(i != 0)

        {

            pLg1 = pLg1 * p % Mod1;

            pLg2 = pLg2 * p % Mod2;

        }

    }



    int hash_b1 = 0, hash_b2 = 0;



    for(int i = 0; i < n; i++)

    {

        hash_b1 = (hash_b1 * p + b[i]) % Mod1;

        hash_b2 = (hash_b2 * p + b[i]) % Mod2;

    }



    if(hash_a1 == hash_b1 && hash_a2 == hash_b2)

    {

        contor ++;

        viz[0] = 1;

    }



    for(int i = n; i < m; i++)

    {



        hash_b1 = ((hash_b1 - (pLg1 * b[i - n]) % Mod1 + Mod1) * p + b[i]) % Mod1;

        hash_b2 = ((hash_b2 - (pLg2 * b[i - n]) % Mod2 + Mod2) * p + b[i]) % Mod2;



        if(hash_a1 == hash_b1 && hash_a2 == hash_b2)

        {

            contor++;

            viz[i - n + 1] = 1;

        }

    }



    fout << contor << "\n";



    contor = 0;

    for(int i = 0; i < m && contor < 1000; i++)

        if(viz[i])

        {

            fout << i << " ";

            contor++;

        }



    fout << "\n";



    fin.close();

    fout.close();

    return 0;

}
