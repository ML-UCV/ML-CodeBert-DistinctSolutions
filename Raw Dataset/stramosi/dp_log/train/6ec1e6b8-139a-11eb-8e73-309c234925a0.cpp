#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin ("stramosi.in");
ofstream fout ("stramosi.out");

const int N = 250002, L = 18;
int s[L][N], log[N];

int main ()
{
    int n, m;
    fin >> n >> m;
    for ( int i = 1; i <= n; i++ )
    {
        int x;
        fin >> x;
        s[0][i] = x;
    }
    for ( int i = 2; i <= n; i++ )
    {
        log[i] = log[i/2] + 1;
    }
    for ( int i = 1; i <= log[n]; i++ )
    {
        for ( int j = 1; j <= n ; j++ )
        {
            s[i][j] = s[i-1][s[i-1][j]];
        }
    }
    for ( int a = 1; a <= m ; a++ )
    {
        int p, q;
        fin >> q >> p;
        int poz = 17;
        while ( p != 0 && poz >= 0 )
        {
            if( p >= ( 1<<poz ))
            {
                q = s[poz][q];
                p -= ( 1<< poz );
            }
            poz--;

        }
        fout << q << "\n";
    }
    return 0;
}
