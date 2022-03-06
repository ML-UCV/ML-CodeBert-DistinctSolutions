#include <fstream>
#include <vector>
#include <cstring>


using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



const int NMax = 200;



vector <int> G[NMax + 5], GT[NMax + 5], Topo;

bool Sol[NMax + 5], Use[NMax + 5];

int N, M, Nr;



inline int non(int x)

{

    return (x > N ? x - N : x + N);

}



void AddEdge(int x, int y)

{

    G[x].push_back(y);

    GT[y].push_back(x);

}



void DFSP(int Node)

{

    Use[Node] = 1;



    for(auto Next : G[Node])

        if(!Use[Next])

            DFSP(Next);



    Topo.push_back(Node);

}



void DFSM(int Node)

{

    Use[Node] = Sol[non(Node)] = 1;



    for(auto Next : GT[Node])

        if(!Use[Next])

            DFSM(Next);

}



void Kosaraju()

{

    for(int i = 1; i <= 2 * N; i++)

        if(!Use[i])

            DFSP(i);



    for(int i = 1; i <= 2 * N; i++)

        Use[i] = 0;



    while(!Topo.empty()) {

        int Node = Topo.back(); Topo.pop_back();



        if(!Use[Node] && !Use[non(Node)])

            DFSM(Node);

    }

}



int main()

{

    fin >> N >> M;



    for(int i = 1, type, x, y; i <= M; i++)

    {

        fin >> x >> y >> type;

        x += (type & 2) / 2 * N;

        y += (type & 1) * N;



        AddEdge(non(x), y);

        AddEdge(non(y), x);

    }

    Kosaraju();



    for(int i = 1; i <= N; i++)

        Nr += Sol[i];



    fout << Nr << '\n';



    for(int i = 1; i <= N; i++)

        if(Sol[i])

            fout << i << '\n';



    fin.close();

    fout.close();



    return 0;

}
