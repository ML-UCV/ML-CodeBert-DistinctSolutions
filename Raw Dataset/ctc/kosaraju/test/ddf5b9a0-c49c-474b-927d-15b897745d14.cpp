#include <bits/stdc++.h>




using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



stack < int > s;

vector < int > v1[100005], v2[100005], R[100005];

bitset < 100005 > viz1, viz2;

int nr;



void dfs1 ( int nod );

void dfs2 ( int nod );



int main()

{

    int n, m, x, y, i, j;



    fin >> n >> m;

    while ( m-- )

    {

        fin >> x >> y;

        v1[x].push_back ( y );

        v2[y].push_back ( x );

    }



    for ( i = 1 ; i <= n ; i++ ) if ( viz1[i] == 0 ) dfs1 ( i );



    while ( s.empty() == 0 )

    {

        x = s.top();

        if ( viz2[x] == 0 )

        {

            nr++;

            dfs2 ( x );

        }



        s.pop();

    }



    fout << nr << '\n';

    for ( i = 1 ; i <= nr ; i++ )

    {

        for ( j = 0 ; j < R[i].size() ; j++ ) fout << R[i][j] << ' ';

        fout << '\n';

    }



    return 0;

}



void dfs1 ( int nod )

{

    int i;



    viz1[nod] = 1;

    for ( i = 0 ; i < v1[nod].size() ; i++ ) if ( viz1[v1[nod][i]] == 0 ) dfs1 ( v1[nod][i] );

    s.push ( nod );

}



void dfs2 ( int nod )

{

    int i;



    viz2[nod] = 1;

    for ( i = 0 ; i < v2[nod].size() ; i++ ) if ( viz2[v2[nod][i]] == 0 ) dfs2 ( v2[nod][i] );

    R[nr].push_back ( nod );

}
