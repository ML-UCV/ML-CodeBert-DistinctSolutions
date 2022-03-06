#include <bits/stdc++.h>


using namespace std;



int id_n[100005], low_link[100005];

bool inStack[100005];

vector<int> edge[100005];

vector<vector<int>> ctc;

vector<int> conex;

stack<int> stk;

int dist = 0;

int n,m;





void Tarjan(int node){



    id_n[node] = dist;

    inStack[node] = true;

    low_link[node] = dist;

    stk.push(node);

    dist ++;



    for (int i = 0 ; i < edge[node].size(); i++)

    {

        if (id_n[edge[node][i]] == -1)

        {



            Tarjan(edge[node][i]);



            low_link[node] = min(low_link[node],

                                 low_link[edge[node][i]]);

        }

        else if (inStack[edge[node][i]])

        {

            int aux = edge[node][i];

            low_link[node] = min (low_link[node], low_link[aux]);

        }

    }

    if(id_n[node] == low_link[node])

    {

        conex.clear();

        int aux;

        do

        {

            aux = stk.top();

            conex.push_back(aux);

            stk.pop();

            inStack[aux] = 0;

        }

        while (node != aux);

        ctc.push_back(conex);

    }



}



int main()

{

    ifstream fin("ctc.in");

    ofstream fout("ctc.out");



    int x, y;

    fin >> n >> m ;



    for (int i = 1; i <= m; i++)

    {

        fin >> x >> y;

        edge[x].push_back(y);

    }



    for (int i = 1; i<= n; i++)

    {

        inStack[i] = 0;

        id_n[i] = -1;

    }



    for (int i = 1; i <= n; i++)

        if (id_n[i] == -1)

            Tarjan(i);





    fout << ctc.size();

    for (int i = 0 ; i < ctc.size(); i++)

    {

        fout << "\n";

        for (int j = 0; j < ctc[i].size(); j++)

            fout << ctc[i][j] <<" ";

    }







    return 0;

}
