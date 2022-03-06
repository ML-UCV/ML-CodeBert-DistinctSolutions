#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



vector < int > v1[100005], v2[100005], a[100005];

stack < int > s;

int nr;

bool viz1[100005], viz2[100005];



void bfs1 ( int nod );

void bfs2 ( int nod );



int main()

{

    int n, m, i, j, x, y;



    fin >> n >> m;

    for ( i = 1 ; i <= m ; i++ )

    {

        fin >> x >> y;

        v1[x].push_back ( y );

        v2[y].push_back ( x );

    }



    for ( i = 1 ; i <= n ; i++ ) if ( viz1[i] == 0 ) bfs1 ( i );



    while ( s.empty() == 0 )

    {

        if ( viz2[s.top()] == 0 )

        {

            nr++;

            bfs2 ( s.top() );

        }



        s.pop();

    }



    fout << nr << '\n';

    for ( i = 1 ; i <= nr ; i++ )

    {

        for ( j = 0 ; j < a[i].size() ; j++ ) fout << a[i][j] << ' ';

        fout << '\n';

    }



    return 0;

}



void bfs1 ( int nod )

{

    int i;



    viz1[nod] = 1;

    for ( i = 0 ; i < v1[nod].size() ; i++ ) if ( viz1[v1[nod][i]] == 0 ) bfs1 ( v1[nod][i] );

    s.push ( nod );

}



void bfs2 ( int nod )

{

    int i;



    viz2[nod] = 1;

    for ( i = 0 ; i < v2[nod].size() ; i++ ) if ( viz2[v2[nod][i]] == 0 ) bfs2 ( v2[nod][i] );

    a[nr].push_back ( nod );

}
