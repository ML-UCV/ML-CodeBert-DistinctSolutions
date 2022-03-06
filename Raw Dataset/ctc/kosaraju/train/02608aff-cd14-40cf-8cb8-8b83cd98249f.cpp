#include <fstream>
#include <vector>


using namespace std;



vector<vector<int> > G, GT,sol;



int n, m;



vector<bool> V;

vector<int> S,ans;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



void read()

{

    fin >> n >> m;

    G = GT = vector<vector<int>>(n + 1);

    for (int i = 1; i <= m; i++)

    {

        int a, b;

        fin >> a >> b;

        G[a].push_back(b);

        GT[b].push_back(a);

    }



}



void dfs(int k)

{

    V[k] = true;

    for (auto x : G[k])

        if (!V[x])

            dfs(x);

    S.push_back(k);

}



void dfsGT(int k)

{

    V[k] = 1;

    for (auto x : GT[k])

        if (!V[x])

            dfsGT(x);

    ans.push_back(k);



}



int main()

{

    ios_base::sync_with_stdio(false);

    fin.tie(0);

    read();



    V = vector<bool>(n + 1, false);

    for (int i = 1; i <= n; i++)

        if (!V[i])

        {

            dfs(i);



        }



    V = vector<bool>(n + 1, false);

    for (vector<int>::reverse_iterator it = S.rbegin(); it != S.rend(); it++)

        if (!V[*it]) {

            ans.clear();

            dfsGT(*it);

            sol.push_back(ans);



        }



    fout << sol.size()<<'\n';

    for (auto it : sol)

    {

        for (auto ij : it)

            fout << ij << " ";

        fout << '\n';

    }

    return 0;

}
