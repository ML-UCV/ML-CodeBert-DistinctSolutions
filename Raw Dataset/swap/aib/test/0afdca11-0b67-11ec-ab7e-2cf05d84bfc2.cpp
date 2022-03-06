#include <fstream>
#include <queue>
#include <string>


using namespace std;



ifstream fin ("swap.in");

ofstream fout ("swap.out");



int n, sol, Nrc[30], P[50010], AIB[50010];

string S1, S2;

queue < int > V[30];



inline int zeros(int x)

{

    return (x ^ (x - 1) & x);

}



void Update(int poz, int value)

{

    while (poz <= n)

    {

        AIB[poz] += value;

        poz += zeros(poz);

    }

}



int Query(int poz, int sum = 0)

{

    while (poz)

    {

        sum += AIB[poz];

        poz -= zeros(poz);

    }



    return sum;

}



int main()

{

    fin >> S1 >> S2;

    n = S1.size();

    for (int i = 0; i < n; i ++)

    {

        Nrc[S1[i] - 'a'] ++;

        Nrc[S2[i] - 'a'] --;

        V[S2[i] - 'a'].push(i);

    }

    for (int i = 0; i < 30; i ++)

    {

        if (Nrc[i] != 0)

        {

            fout << "-1\n";

            fout.close();

            return 0;

        }

    }

    for (int i = 0; i < n; i ++)

    {

        P[i + 1] = V[S1[i] - 'a'].front() + 1;

        V[S1[i] - 'a'].pop();

    }



    Update(P[n], 1);

    for (int i = n - 1; i >= 1; i --)

    {

        sol += Query(P[i]);

        Update(P[i], 1);

    }



    fout << sol << '\n';

    fout.close();

    return 0;

}
