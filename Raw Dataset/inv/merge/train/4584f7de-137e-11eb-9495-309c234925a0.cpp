#include <bits/stdc++.h>


using namespace std;



ifstream fin("inv.in") ;

ofstream fout("inv.out") ;



int t[100005] , v[100005] , nrpm ;



void mergemerge(int lft,int rght)

{

    int i , x , y ;

    if ( lft >= rght )

        return ;

    int mij = (lft+rght)/2 ;

    mergemerge(lft,mij) ;

    mergemerge(mij+1,rght) ;

    x = lft ;

    y = mij+1 ;

    i = lft ;

    while ( x <= mij && y <= rght )

    {

        if ( v[x] <= v[y] )

            t[i++] = v[x++] ;

        else

        {

            nrpm = (nrpm+mij-x+1)%9917 ; ;

            t[i++] = v[y++] ;

        }

    }

    while ( x <= mij )

        t[i++] = v[x++] ;

    while ( y <= rght )

        t[i++] = v[y++] ;

    for ( i = lft ; i <= rght ; i++ )

        v[i] = t[i] ;

}



int main()

{

    int n , i ;

    fin >> n ;

    for ( i = 1 ; i <= n ; i++ )

        fin >> v[i] ;

    nrpm = 0 ;

    mergemerge(1,n) ;

    fout << nrpm ;

}
