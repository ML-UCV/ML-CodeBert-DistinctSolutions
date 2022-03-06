#include <bits/stdc++.h>


using namespace std;



ifstream f ("strmatch.in");

ofstream g ("strmatch.out" );



vector <int> searchh ( string pat, string s )

{

    int mod1 = 100007, mod2 = 100021, d = 73, h1 = 1, h2 = 1, p1 = 0, p2 = 0, t1 = 0, t2 = 0, i;



    vector < int > sol;



    int m = pat.size();

    int n = s.size();



    for ( i = 0 ; i < m-1 ; i++ )

    {

        h1 = (h1*d) % mod1;

        h2 = (h2*d) % mod2;

    }



    for ( i = 0 ; i < m; i++ )

    {

        p1 = (p1 * d + pat[i]) % mod1;

        p2 = (p2 * d + pat[i]) % mod2;

        t1 = (t1 * d + s[i]) % mod1;

        t2 = (t2 * d + s[i]) % mod2;

    }





    if ( p1 == t1 && p2 == t2 )

        sol.push_back(0);



    for ( i = m ; i < n ; i++ )

    {

        t1 = ((t1 - (s[i-m]*h1)%mod1 +mod1 ) * d + s[i]) % mod1;

        t2 = ((t2 - (s[i-m]*h2)%mod2 +mod2 ) * d + s[i]) % mod2;



        if ( t1 == p1 && t2 == p2 )

            sol.push_back(i-m+1);

    }







    return sol;





}



int main ()

{



    string a, b;



    vector <int> sol;



    f >> a >> b;



    if (a.size() > b.size())

    {

        g<<0;

        return 0;

    }



    sol = searchh ( a, b );



    g << sol.size() << '\n';



    for ( int i = 0 ; i < sol.size() && i < 1000 ; i++ )

        g<<sol[i]<<" ";

}
