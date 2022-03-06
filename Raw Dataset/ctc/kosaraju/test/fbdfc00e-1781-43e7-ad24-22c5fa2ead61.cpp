#include <iostream>
#include <fstream>
#include <vector>
#include <stack>






using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int vf, muchii;



int Vizitat[100005];

vector < int > Numbers[100005];

vector < int > Numbers_SensInversMuchii[100005];

vector < int > SalvamCTC[100005];



stack < int > Stiva;



int compconex, ctc;



inline void DFS( int Nod )

{

    int Vecin;



    Vizitat[Nod] = 1;

    for( unsigned int i = 0; i < Numbers[Nod].size(); ++ i )

    {

        Vecin = Numbers[Nod][i];

        if( !Vizitat[Vecin] )

            DFS(Vecin);

    }

    Stiva.push(Nod);



}



inline void DFS_2( int Nod )

{

    int Vecin;



    SalvamCTC[ctc].push_back(Nod);

    Vizitat[Nod] = 2;



    for( unsigned int i = 0; i < Numbers_SensInversMuchii[Nod].size(); ++ i )

    {

        Vecin = Numbers_SensInversMuchii[Nod][i];

        if( Vizitat[Vecin] == 1 )

            DFS_2(Vecin);

    }



}



int main()

{

    fin >> vf >> muchii;

    for( int i = 1; i <= muchii; ++ i )

    {

        int x, y;

        fin >> x >> y;

        Numbers[x].push_back(y);

        Numbers_SensInversMuchii[y].push_back(x);

    }



    for( int i = 1; i <= vf; ++ i )

        if( !Vizitat[i] )

            DFS(i);



    while( !Stiva.empty() )

    {

        int Numar = Stiva.top();

        if( Vizitat[Numar] == 1 )

        {

            ctc++;

            DFS_2(Numar);

        }

        Stiva.pop();

    }

    fout << ctc << "\n";

    for( int i = 1; i <= ctc; ++ i )

    {

        for( unsigned int j = 0; j < SalvamCTC[i].size(); ++ j )

        {

            fout << SalvamCTC[i][j] << " ";

        }

        fout << "\n";

    }

    return 0;

}
