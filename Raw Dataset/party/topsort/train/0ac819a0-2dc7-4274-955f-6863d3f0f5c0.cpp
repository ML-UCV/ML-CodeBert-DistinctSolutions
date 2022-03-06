#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");







int n, m ;

vector<int> graf[201], trans[201] ;

bool sel[201] ;



bool sol[201] ;

int nrinv ;



int lista[201], nr ;



int functie(int x)

{

    if( x <= n )

        return x + n ;

    return x - n ;

}



void citire_si_initializare()

{

    fin >> n >> m ;



    for(int i = 1; i <= m; ++i )

    {

        int a, b, tip ;



        fin >> a >> b >> tip ;



        if( tip == 0 )

        {

            graf[ functie(a) ].push_back(b) ;

            graf[ functie(b) ].push_back(a) ;



            trans[a].push_back( functie(b) ) ;

            trans[b].push_back( functie(a) ) ;



            continue ;

        }



        if( tip == 1 )

        {

            graf[ functie(a) ].push_back( functie(b) ) ;

            graf[b].push_back(a) ;



            trans[ functie(b) ].push_back( functie(a) ) ;

            trans[a].push_back(b) ;



            continue ;

        }



        if( tip == 2 )

        {

            graf[ functie(b) ].push_back( functie(a) ) ;

            graf[a].push_back(b) ;



            trans[ functie(a) ].push_back( functie(b) );

            trans[b].push_back(a) ;



            continue ;

        }



        if( tip == 3 )

        {

            graf[a].push_back( functie(b) ) ;

            graf[b].push_back( functie(a) ) ;



            trans[ functie(a) ].push_back(b) ;

            trans[ functie(b) ].push_back(a) ;



            continue ;

        }

    }

}



void sortare_topologica(int nod)

{

    sel[nod] = true ;



    for(size_t i = 0; i < graf[nod].size(); ++i )

        if( sel[ graf[nod][i] ] == false )

            sortare_topologica( graf[nod][i] ) ;



    lista[ --nr ] = nod ;

}



void dfs(int nod)

{

    sel[nod] = false ;



    sol[ functie(nod) ] = true ;



    if( nod > n )

        ++nrinv ;



    for(size_t i = 0; i < trans[nod].size(); ++i )

        if( sel[ trans[nod][i] ] == true )

            dfs( trans[nod][i] ) ;

}



void rezolvare()

{

    nr = 2 * n + 1 ;

    int lim = 2 * n ;



    for(int i = 1 ;i <= lim; ++i )

        if( sel[i] == false )

            sortare_topologica(i) ;



    for(int i = 1; i <= lim; ++i )

        if( sel[ lista[i] ] == true && sel[ functie( lista[i] ) ] == true )

            dfs( lista[i] ) ;

}



void afisare()

{

    fout << nrinv << "\n" ;



    for(int i = 1 ;i <= n ; ++i )

        if( sol[i] == true )

            fout << i << "\n" ;

}



int main()

{

    citire_si_initializare() ;



    rezolvare() ;



    afisare() ;



    return 0 ;

}
