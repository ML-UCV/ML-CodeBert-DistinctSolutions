#include <fstream>


using namespace std;

ofstream g ("stramosi.out");

int const N = 250001 , SZ = 1e6;

int v [N][18] , p;

char s [SZ];

int getn (){

    int x = 0;

    while (! isdigit (s [p])){

        ++ p;

        if (p == SZ)

            fread (s , 1 , SZ , stdin) , p = 0;

    }

    while (isdigit (s [p])){

        x = x * 10 + (s [p] - '0');

        ++ p;

        if (p == SZ)

            fread (s , 1 , SZ , stdin) , p = 0;

    }

    return x;

}

int main()

{

    int n , m , i , j , p , cur , q , x;

    freopen ("stramosi.in" , "r" , stdin);

    scanf ("%d%d" , &n , &m);

    fread (s , 1 , SZ , stdin);

    for(i = 1 ; i <= n ; ++ i)

        v [i][0] = getn ();

    for(i = 1 ; (1 << i) <= n ; ++ i)

        for(j = (1 << i) + 1 ; j <= n ; ++ j)

            v [j][i] = v [v [j][i - 1]][i - 1];

    while (m --){

        p = getn () , q = getn ();

        cur = p , x = 0;

        while ((1 << x) < q)

            ++ x;

        for(i = x ; i >= 0 ; -- i)

            if ((1 << i) & q)

                cur = v [cur][i];

        g << cur << '\n';

    }





    return 0;

}
