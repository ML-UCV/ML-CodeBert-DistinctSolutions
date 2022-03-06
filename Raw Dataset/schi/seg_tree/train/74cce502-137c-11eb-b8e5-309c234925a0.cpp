#include <fstream>


using namespace std;



ifstream in ("schi.in");

ofstream out ("schi.out");



void update ( int nod, int left, int right, int poz, int val );



int f_find ( int nod, int left, int right, int poz );



int aint[120137];



int n;



int v[30137];



int ans[30137];



int gasit;



int main()

{

    in >> n;

    for ( register int i = 1 ; i <= n ; ++i )

        {

            in >> v[i];

            update ( 1 , 1 , n , i , 1 );

        }



    for ( register int i = n ; i >= 1 ; --i )

    {

        gasit = f_find ( 1 , 1 , n , v[i] );

        ans[gasit] = i;

        update ( 1 , 1 , n , gasit , 0 );

    }

    for ( register int i = 1 ; i <= n ; ++i )

        out << ans[i] << '\n';

    return 0;

}



void update ( int nod, int left, int right, int poz, int val )

{

    int mid = ( left + right ) / 2;

    if ( left == right )

    {

        aint[nod] = val;

        return ;

    }

    if ( poz <= mid )

        update ( nod * 2 , left , mid , poz , val );

    else

        update ( nod * 2 + 1 , mid + 1 , right , poz , val );

    aint[nod] = aint[nod * 2] + aint[nod * 2 + 1];

}



int f_find ( int nod, int left, int right, int poz )

{

    int mid = ( left + right ) / 2;

    if ( left == right )

        return left;

    if ( poz <= aint[nod * 2] )

        return f_find ( nod * 2 , left , mid , poz );

    else

        return f_find ( nod * 2 + 1 , mid + 1 , right , poz - aint[nod * 2] );

}
