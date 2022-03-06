#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <bitset>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, ctc, t, T[100000 + 1], M[100000 + 1];

vector<int> G[100000 + 1], C[100000 + 1];

stack<int> N;

bitset<100000 + 1> inN;



void Df(int nod);



int main()

{

    fin >> n >> m;



    for (int i = 1, x, y; i <= m; ++i)

    {

        fin >> x >> y;

        G[x].push_back(y);

    }



    for (int i = 1; i <= n; ++i)

    {

        if (T[i] == 0)

        {

            Df(i);

        }

    }



    fout << ctc << '\n';

    for (int i = 1; i <= ctc; ++i)

    {

        for (int nod : C[i])

        {

            fout << nod << ' ';

        }

        fout << '\n';

    }



    fin.close();

    fout.close();

    return 0;

}



void Df(int nod)

{

    M[nod] = T[nod] = ++t;



    N.push(nod);

    for (int vecin : G[nod])

    {

        if (T[vecin] == 0)

        {

            Df(vecin);

            M[nod] = min(M[nod], M[vecin]);

        }

        else

        {

            if (!inN[vecin])

            {

                M[nod] = min(M[nod], T[vecin]);

            }

        }

    }



    if (T[nod] == M[nod])

    {

        ++ctc;



        while (N.top() != nod)

        {

            C[ctc].push_back(N.top());

            inN[N.top()] = true;

            N.pop();

        }



        C[ctc].push_back(N.top());

        inN[N.top()] = true;

        N.pop();

    }

}
