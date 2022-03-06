#include <bits/stdc++.h>




using namespace std;



ifstream fin("party.in") ;

ofstream fout("party.out") ;



vector<int> graf[205] ;

vector<int> graft[205] ;

vector<int> ord , sol ;

bitset<205> bt ;

int n , m , rng[205] , cmp ;



void add(int x , int y)

{

    graf[x].push_back(y) ;

    graft[y].push_back(x) ;

}



void citire()

{

    int x , y , tp , i ;

    fin >> n >> m ;

    for ( i = 1 ; i <= m ; i++ )

    {

        fin >> x >> y >> tp ;

        if ( tp == 0 )

            add(n+x,y) , add(n+y,x) ;

        else if ( tp == 1 )

            add(n+x,n+y) , add(y,x) ;

        else if ( tp == 2 )

            add(x,y) , add(n+y,n+x) ;

        else

            add(x,n+y) , add(y,n+x) ;

    }

}



void dfs(int nod)

{

    bt[nod] = 1 ;

    for ( auto vec : graf[nod] )

        if ( bt[vec] == 0 )

            dfs(vec) ;

    ord.push_back(nod);

}



void dfst(int nod)

{

    rng[nod] = cmp ;

    for ( auto vec : graft[nod] )

        if ( rng[vec] == 0 )

            dfst(vec) ;

}



int main()

{

    int i ;

    citire() ;

    for ( i = 1 ; i <= 2*n ; i++ )

        if ( bt[i] == 0 )

            dfs(i) ;

    reverse(ord.begin(),ord.end()) ;

    cmp = 1 ;

    for ( auto vv : ord )

        if ( rng[vv] == 0 )

            dfst(vv) , cmp++ ;

    for ( i = 1 ; i <= n ; i++ )

        if ( rng[i] > rng[n+i] )

            sol.push_back(i) ;

    fout << sol.size() << '\n' ;

    for ( auto vv : sol )

        fout << vv << '\n' ;

}
