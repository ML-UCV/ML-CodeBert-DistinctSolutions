#include <fstream>
#include <vector>
#include <stack>
#include <bitset>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m;

int nr_componente;

int viz[100005];

vector <int> graf[100005];

vector <int> graf_transpus[100005];

vector <int> sol[100005];

stack <int> a;



void citire()

{

    int x, y;

    fin >> n >> m;

    for(int i = 0; i < m; i++)

    {

        fin >> x >> y;

        graf[x].push_back(y);

        graf_transpus[y].push_back(x);

    }

}



void DFS(int i)

{

    viz[i] = 1;

    for(unsigned int j = 0; j < graf[i].size(); j++)

    {

        if(!viz[graf[i][j]])

        {

            viz[graf[i][j]] = 1;

            DFS(graf[i][j]);

        }

    }

    a.push(i);

}



void init_stack()

{

    for(int i = 1; i <= n; i++)

        if(!viz[i])

            DFS(i);

}



void DFS2(int i)

{

    viz[i] = 2;

    for(unsigned int j = 0; j < graf_transpus[i].size(); j++)

        if(viz[graf_transpus[i][j]] < 2)

        {

            viz[graf_transpus[i][j]] = 2;

            DFS2(graf_transpus[i][j]);

        }

    sol[nr_componente].push_back(i);

}





void solve()

{

    while(!a.empty())

    {

        int nod = a.top();

        a.pop();

        if(viz[nod] > 1)

            continue;

        nr_componente++;

        DFS2(nod);

    }

}



void afisare()

{

    fout << nr_componente << '\n';

    for(int i = 1; i <= nr_componente; i++)

    {

        for(auto &v : sol[i])

            fout << v << ' ';

        fout << '\n';

    }

}



int main()

{

    citire();

    init_stack();

    solve();

    afisare();

    return 0;

}
