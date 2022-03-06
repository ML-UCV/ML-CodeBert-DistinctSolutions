#include <fstream>
#include <vector>
#include <bitset>


std::ifstream in("ctc" ".in");

std::ofstream out("ctc" ".out");

const int N = 100000;

std::vector<int> L[N], S;

int LL[N], ID[N], nId;

std::bitset<N> E, pS;

std::vector<std::vector<int>> CTC;

void dfs(int t)

{

    pS[t] = true;

    ID[t] = LL[t] = nId++;

    S.push_back(t);

    for (int f: L[t])

        if (not E[f])

        {

            if (not pS[f])

                dfs(f);

            LL[t] = std::min(LL[t], LL[f]);

        }

    if (ID[t] == LL[t])

    {

        CTC.emplace_back();

        int back;

        do

        {

            back = S.back();

            S.pop_back();

            CTC.back().push_back(back);

            E[back] = true;

        }

        while (back != t);

    }

}

int main()

{

    int n, m;

    in >> n >> m;

    while (m--)

    {

        int a, b;

        in >> a >> b;

        L[--a].push_back(--b);

    }

    for (int i = 0; i < n; i++)

        if (not E[i])

            dfs(i);

    out << CTC.size() << '\n';

    for (auto ctc: CTC)

    {

        for (int i: ctc)

            out << i + 1 << ' ';

        out << '\n';

    }

}
