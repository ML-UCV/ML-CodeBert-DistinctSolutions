#include <fstream>
#include <vector>
#include <queue>
using namespace std;



vector<int> Go[256], Gi[256], discovered, part;

vector< vector < int > > v;

int where[256], value[256], n, m, a, b, c, first, second;

bool used[256];



inline int getOpposite(int a)

{

    if(a <= n) return a + n;

    else return a - n;

}



void Citire()

{

    ifstream in("party.in");

    in>>n>>m;

    for(int i = 1; i <= m; i++)

    {

        in>>a>>b>>c;

        switch(c)

        {

            case 0: first = getOpposite(a); second = getOpposite(b); break;

            case 1: first = getOpposite(a); second = b; b = getOpposite(b); break;

            case 2: first = a; second = getOpposite(b); a = getOpposite(a);break;

            case 3: first = a; second = b; a = getOpposite(a); b = getOpposite(b); break;

        }

        Go[first].push_back(b);

        Go[second].push_back(a);

        Gi[a].push_back(second);

        Gi[b].push_back(first);

    }

    in.close();

}



void DFF(int nod)

{

    used[nod] = true;

    for(int i = 0; i < Go[nod].size(); i++)

        if(!used[Go[nod][i]])

            DFF(Go[nod][i]);

    discovered.push_back(nod);

}



void DFS(int nod, int value)

{

    where[nod] = value;

    part.push_back(nod);

    for(int i = 0; i < Gi[nod].size(); i++)

        if(!where[Gi[nod][i]])

            DFS(Gi[nod][i], value);

}



void Kosaraju()

{

    for(int i = 1; i <= 2 * n; i++)

        if(!used[i]) DFF(i);

    int contor = 1;

    for(; discovered.size(); discovered.pop_back())

        if(!where[discovered.back()])

        {

            part.clear();

            DFS(discovered.back(), contor++);

            v.push_back(part);

        }

}



void Assign()

{

    for(int i = 0; i < v.size(); i++)

    {

        if(!value[i + 1])

            value[i + 1] = 2;

        for(int j = 0; j < v[i].size(); j++)

        {

            int nod = v[i][j];

            if(!value[where[getOpposite(nod)]])

                value[where[getOpposite(nod)]] = 3 - value[i + 1];

        }

    }

}



void Afisare()

{

    ofstream out("party.out");

    int contor = 0;

    for(int i = 1; i <= n; i++)

        if(value[where[i]] == 1) contor++;

    out<<contor<<"\n";

    for(int i = 1; i <= n; i++)

        if(value[where[i]] == 1)

            out<<i<<"\n";

    out.close();

}



int main()

{

    Citire();

    Kosaraju();

    Assign();

    Afisare();

    return 0;

}
