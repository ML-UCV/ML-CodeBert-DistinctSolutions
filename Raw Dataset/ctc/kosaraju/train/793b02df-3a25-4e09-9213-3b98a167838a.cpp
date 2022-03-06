#include <iostream>
#include <stack>
#include <vector>
#include <fstream>


using namespace std;

int N, M, viz[100001], comp;

vector <int> l[100001],lT[100001],rez[100001];

stack <int> s;



void DFS(int nod)

{

    viz[nod] = 1;

    for (int i = 0; i < l[nod].size(); i++)

    {

        if (viz[l[nod][i]] == 0)

            DFS(l[nod][i]);

    }

    s.push(nod);

}



void DFS2(int nod)

{

    viz[nod] = 1;

    rez[comp].push_back(nod);



    for (int i = 0; i < lT[nod].size(); i++)

        if (viz[lT[nod][i]] == 0)

            DFS2(lT[nod][i]);

}



int main()

{

    ifstream fin("ctc.in");

    ofstream fout("ctc.out");



    int i, j, k;



    fin >> N >> M;

    for (i = 0; i < M; i++)

    {

        fin >> j >> k;

        l[j].push_back(k);

        lT[k].push_back(j);

    }



    for (i = 1; i <= N; i++)

    {

        if (viz[i] == 0)

            DFS(i);

    }



    for (i = 1; i <= N; i++)

        viz[i] = 0;



    while(!s.empty())

    {

        int nod = s.top();

        if(viz[nod] == 0)

        {

            comp++;

            DFS2(nod);

        }

        s.pop();

    }



    fout << comp << "\n";

    for (i = 1; i <= comp; i++)

    {

        for (j = 0; j < rez[i].size(); j++)

            fout << rez[i][j] << " ";

        fout << "\n";

    }



    fin.close();

    fout.close();



    return 0;

}
