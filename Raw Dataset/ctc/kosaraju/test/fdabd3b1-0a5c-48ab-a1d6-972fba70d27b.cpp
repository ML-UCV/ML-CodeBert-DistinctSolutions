#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <stack>


using namespace std;



const int N = 1e5 + 5;



vector <int> L[N], T[N], scc[N];

int n, nr_scc;



void Read ()

{

    ifstream fin ("ctc.in");

    int m;

    fin >> n >> m;

    while (m--)

    {

        int x, y;

        fin >> x >> y;

        L[x].push_back(y);

        T[y].push_back(x);

    }

    fin.close();

}



stack <int> st;

bitset <N> seen;



void DFS1(int vertex)

{

    seen[vertex] = 1;

    for (auto next : L[vertex])

        if (!seen[next])

            DFS1(next);

    st.push(vertex);

}



void DFS2(int vertex)

{

    seen[vertex] = 0;

    for (auto next : T[vertex])

        if (seen[next])

            DFS2(next);

    scc[nr_scc].push_back(vertex);

}



void Kosaraju ()

{

    for (int i = 1; i <= n; i++)

        if (!seen[i])

            DFS1(i);

    while (!st.empty())

    {

        if (seen[st.top()])

        {

            nr_scc++;

            DFS2(st.top());

        }

        st.pop();

    }

    ofstream fout ("ctc.out");

    fout << nr_scc << "\n";

    for (int i = 1; i <= nr_scc; i++)

    {

        for (auto j : scc[i])

            fout << j << " ";

        fout << "\n";

    }

    fout.close();

}



int main()

{

    Read();

    Kosaraju();

    return 0;

}
