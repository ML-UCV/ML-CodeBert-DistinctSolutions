#include <fstream>

using namespace std;

int aint[131073];
int vin[30000], vout[30000];

int mod ( int p, int st, int dr, int poz ) {
    if ( st == dr ) {
        aint[p] = 1;
        return st;
    }
    int m = ( st + dr ) / 2, r;
    int libere_st = m - st + 1 - aint[2*p];
    if ( poz <= libere_st )
        r = mod (2*p, st, m, poz);
    else
        r = mod (2*p+1, m+1, dr, poz-libere_st);
    aint[p]++;
    return r;
}

int main () {
    ifstream fin ("schi.in");
    ofstream fout ("schi.out");
    int n;
    fin>>n;
    for ( int i = 1; i <= n; i++ )
        fin>>vin[i];
    for ( int i = n; i >= 1; i-- )
        vout[mod(1,1,n,vin[i])] = i;
    for ( int i = 1; i <= n; i++ )
        fout<<vout[i]<<'\n';
    return 0;
}
