#include <fstream>
#include <queue>
#include <string>


using namespace std;



ifstream fin ("swap.in");

ofstream fout ("swap.out");



int n, sol, sum, Nrc[30], P[50010], ARBI[50010 * 3];

string S1, S2;

queue < int > V[30];



void Update(int nod, int left, int right, int poz, int value)

{

    if (left == right)

    {

        ARBI[nod] = value;

        return;

    }



    int mid = (left + right) >> 1;

    if (poz <= mid)

    {

        Update(nod * 2, left, mid, poz, value);

    }

    else

    {

        Update(nod * 2 + 1, mid + 1, right, poz, value);

    }

    ARBI[nod] = ARBI[nod * 2] + ARBI[nod * 2 + 1];

}



void Query(int nod, int left, int right, int st, int dr)

{

    if (st <= left && right <= dr)

    {

        sum += ARBI[nod];

        return;

    }



    int mid = (left + right) >> 1;

    if (st <= mid)

    {

        Query(nod * 2, left, mid, st, dr);

    }

    if (dr > mid)

    {

        Query(nod * 2 + 1, mid + 1, right, st, dr);

    }

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



    Update(1, 1, n, P[n], 1);

    for (int i = n - 1; i >= 1; i --)

    {

        sum = 0;

        Query(1, 1, n, 1, P[i]);

        sol += sum;

        Update(1, 1, n, P[i], 1);

    }



    fout << sol << '\n';

    fout.close();

    return 0;

}
