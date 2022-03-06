#include <fstream>
#include <string>
#include <vector>
#include <iostream>


using namespace std;



const int maxn = 50002;

const int maxa = 27;



ifstream in("swap.in");

ofstream out("swap.out");



string a, b;



int poz1[maxa];

vector <int> poz2[maxa];



int perm[maxn];



void read()

{

    in >> a >> b;

}



int v1[maxa];

int v2[maxa];

int valid()

{

    for ( int i = 0; i < a.size(); ++i )

        ++v1[ a[i] - 'a' ], ++v2[ b[i] - 'a' ];



    for ( int i = 0; i <= 'z' - 'a'; ++i )

        if ( v1[i] != v2[i] )

            return 0;



    return 1;

}



void init()

{

    for ( int i = 0; i < a.size(); ++i )

        poz2[ b[i] - 'a' ].push_back(i);



    for ( int i = 0; i < a.size(); ++i )

        perm[i + 1] = 1 + poz2[ a[i] - 'a' ][ poz1[ a[i] - 'a' ]++ ];

}



int answ;



int tmp[maxn];

void merge(int st, int m, int dr)

{

    int i = st;

    int j = m+1;

    int k = 0;



    while ( i <= m && j <= dr )

        if ( perm[i] <= perm[j] )

            tmp[++k] = perm[i++];

        else

        {

            answ += m - i + 1;

            tmp[++k] = perm[j++];

        }



    while ( i <= m )

        tmp[++k] = perm[i++];

    while ( j <= dr )

        tmp[++k] = perm[j++];



    k = 0;

    for ( int i = st; i <= dr; ++i )

        perm[i] = tmp[++k];

}



void sort(int st, int dr)

{

    if ( st < dr )

    {

        int m = (st + dr) >> 1;



        sort(st, m);

        sort(m+1, dr);



        merge(st, m, dr);

    }

}



int main()

{

    read();



    if ( !valid() )

    {

        out << -1 << endl;

        return 0;

    }



    init();
    sort(1, a.size());

    out << answ << endl;



    return 0;

}
