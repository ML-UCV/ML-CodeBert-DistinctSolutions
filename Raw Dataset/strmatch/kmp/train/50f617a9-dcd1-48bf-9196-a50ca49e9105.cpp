#include <bits/stdc++.h>


using namespace std;

ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");

string N, M;

int v[2000001];

vector <int> sol;

void make_prefix (string N)

{

    int n = N.size ();

    int j = 0;

    for (int i = 1; i < n; i++)

    {

        if (N[i] != N[j])

            while (j > 0 && N[j] != N[i])

                j = v[j - 1];

        if (N[j] == N[i])

            ++j;

        v[i] = j;

    }

}

void match (string N, string M)

{

    int m = M.size ();

    int n = N.size ();

    int i = 0;

    for (int j = 0; j < m; j++)

    {

        if (N[i] != M[j])

            while (i > 0 && M[j] != N[i])

                i = v[i - 1];

        if (N[i] == M[j])

            i++;

        if (i == n)

        {

            sol.push_back (j - i + 1);

            i = v[i - 1];

        }

    }

}

int main ()

{

    fin >> N >> M;

    make_prefix (N);

    match (N, M);

    fout << sol.size () << "\n";

    int n = sol.size ();

    for (int i = 0; i < min (n , 1000); i++)

            fout << sol[i] << " ";

}
