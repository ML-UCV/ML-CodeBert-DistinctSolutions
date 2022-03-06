#include <bits/stdc++.h>




using namespace std;



ifstream fin("swap.in") ;

ofstream fout("swap.out") ;



string sir1,sir2 ;

int ax[50005] , nrpr[50005] ;

int n , p[50005] , t[50005] ,inv , v[50005] ;

vector<int> graf[50005] , graf2[50005] ;



void mergemerge(int lft,int rght)

{

    int i , x , y ;

    if ( lft == rght )

        return ;

    int mij = (lft+rght)/2 ;

    mergemerge(lft,mij) ;

    mergemerge(mij+1,rght) ;

    x = lft ;

    y = mij+1 ;

    i = lft ;

    while ( x <= mij && y <= rght )

    {

        if ( p[x] <= p[y] )

            t[i++] = p[x++] ;

        else

        {

            t[i++] = p[y++] ;

            inv = inv +mij-x+1 ;

        }

    }

    while ( x <= mij )

        t[i++] = p[x++] ;

    while ( y <= rght )

        t[i++] = p[y++] ;

    for ( i = lft ; i <= rght ; i++ )

        p[i] = t[i] ;

}



int main()

{

    int i , j ,m;

    fin >> sir1 ;

    fin >> sir2 ;

    sir1 = '#' + sir1 ;

    sir2 = '#' + sir2 ;

    n = sir1.size()-1 ;

    m = sir2.size()-1 ;

    if ( n!= m )

    {

            fout << "-1" ;

            return 0 ;

    }

    for ( i = 1 ; i <= n ; i++ )

        nrpr[sir1[i]-'a'+1]++ , nrpr[sir2[i]-'a'+1]-- ;

    for ( i = 1 ; i <= n ; i++ )

    {

        if ( nrpr[i] != 0 )

        {

            fout << "-1" ;

            return 0 ;

        }

    }

    for ( i = 1 ; i <= n ; i++ )

    {

        graf[sir1[i]-'a'+1].push_back(i) ;

        graf2[sir2[i]-'a'+1].push_back(i) ;

    }

    for ( i = 1 ; i <= 27 ; i++ )

        for ( j = 0 ; j < graf[i].size() ; j++ )

            p[graf[i][j]] = graf2[i][j] ;

    mergemerge(1,n) ;

    fout << inv ;

}
