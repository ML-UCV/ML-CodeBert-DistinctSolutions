#include<bits/stdc++.h>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, comp = 0, id = 1;

vector<int> M[100002], sol;

bool instk[100002];

stack<int> stk;

int low[100002], ids[100002];

vector<vector<int>> Solutii;



void DFS(int k)

{

    stk.push(k);

    instk[k] = true;

    ids[k] = low[k] = id++;



    for(int y : M[k])

    {

        if(!ids[y])

            DFS(y);



        if(instk[y])

            low[k] = min(low[y], low[k]);

    }



    if(ids[k] == low[k])

    {

        comp++;

        int node;

        while(1)

        {

            node = stk.top();

            sol.push_back(node);

            instk[node] = false;

            low[node] = ids[k];

            stk.pop();

            if(node == k) break;

        }

        Solutii.push_back(sol);

        sol.clear();



    }

}





int main()

{

    int x, y;

    fin >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        fin >> x >> y;

        M[x].push_back(y);

    }



    for(int i = 1; i <= n; i++)

        if(!ids[i])

            DFS(i);



    fout << comp << '\n';

    for(int i = 0; i < comp; i++)

    {

        for(int j : Solutii[i])

            fout << j << ' ';

        fout << '\n';

    }

    return 0;

}
