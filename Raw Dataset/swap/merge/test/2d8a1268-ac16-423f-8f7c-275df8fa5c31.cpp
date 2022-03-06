#include <fstream>
#include <string>


using namespace std;



int N, v[50005];

string A, B;



void Citire () {

    ifstream fin ("swap.in");

    fin >> A >> B;

    fin.close ();

    N = A.size ();

}



int alfa[30], beta[30];



int Good () {

    for (int i = 0; i < N; i++)

    {

        alfa[A[i] - 'a']++;

        beta[B[i] - 'a']++;

    }

    for (int i = 0; i <= 30; i++)

        if (!(alfa[i] == beta[i])) return 0;

    return 1;

}



void Initializare () {

    int k;

    for (char i = 'a'; i <= 'z'; i++)

    {

        k = -1;

        for (int j = 0; j < N; j++)

        {

            if (A[j] == i)

            {

                for (++k; k < N; k++)

                {

                    if (B[k] == i)

                    {

                        v[k] = j;

                        break;

                    }

                }

            }

        }

    }

}



int aux[50005];



int Business (int L, int R) {

    int cnt = 0, mij = (L + R) >> 1, k = L - 1, i, j;

    if (L >= R) return 0;

    cnt += Business (L, mij);

    cnt += Business (mij + 1, R);

    for (i = L, j = mij + 1; i <= mij && j <= R;)

    {

        if (v[i] <= v[j]) aux[++k] = v[i++];

        else

        {

            aux[++k] = v[j++];

            cnt += mij - i + 1;

        }

    }

    while (i <= mij)

    {

        aux[++k] = v[i++];

    }

    while (j <= R)

    {

        aux[++k] = v[j++];

    }

    for (int i = L; i <= R; i++)

        v[i] = aux[i];

    return cnt;

}



int main () {

    Citire ();

    ofstream fout ("swap.out");

    if (!Good ())

    {

        fout << "-1";

        fout.close ();

        return 0;

    }

    Initializare ();

    fout << Business (0, N - 1);

    fout.close ();

    return 0;

}
