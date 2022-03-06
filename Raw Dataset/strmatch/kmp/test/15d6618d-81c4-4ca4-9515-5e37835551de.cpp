#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in") ;

ofstream fout("strmatch.out") ;



vector<int> prefix(string sir)

{

    int n , i , j ;

    n = sir.size() ;

    vector<int> pr(n) ;

    pr[0] = 0 ;

    for ( i = 1 ; i < n ; i++ )

    {

        j = pr[i-1] ;

        while ( j && sir[i] != sir[j] )

            j = pr[j-1] ;

        if ( sir[i] == sir[j] )

            j++ ;

        pr[i] = j ;

    }

    return pr ;

}





int main()

{

    string sir,sir1,sir2;

    int n1,n2,i,p;

    vector<int> v;

    vector<int> sol;

    fin >> sir1 ;

    fin >> sir2 ;

    sir = sir1+'#'+sir2 ;

    n1 = sir1.size() ;

    n2 = sir2.size() ;

    sir1.clear() ;

    sir2.clear() ;

    v = prefix(sir) ;



    for ( i = n1+1 ; i <= n1+n2 ; i++ )

    {



        if ( v[i] == n1 )

            sol.push_back(i-2*n1) ;

    }

    p = min(1000,(int)sol.size()) ;

    fout << sol.size() << '\n' ;

    for ( i = 0 ; i < p ; i++ )

        fout << sol[i] << " " ;

}
