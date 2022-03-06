#include <fstream>
#include <string.h>
using namespace std;
ifstream fin ( "evaluare.in" );
ofstream fout ( "evaluare.out" );
const int NMAX = 1e5;
char s[NMAX + 1];
int n, k;
inline int op ( int a, int b, char ch ) {
    if ( ch == '+' )
        return a + b;
    if ( ch == '-' )
        return a - b;
    if ( ch == '*' )
        return a * b;
    if ( ch == '/' )
        return a / b;
    return -1;
}
int eval ();
int factor() {
    int rez;
    if ( s[k] == '(' ) {
        k++;
        rez = eval();
        k++;
    } else {
        rez = 0;
        while ( k <= n && isdigit ( s[k] ) )
            rez = rez * 10 + s[k++] - '0';
    }
    return rez;
}
int termen () {
    int rez = factor();
    while ( k <= n && ( s[k] == '*' || s[k] == '/' ) ) {
        char semn = s[k];
        k++;
        rez = op ( rez, factor(), semn );
    }
    return rez;
}
int eval () {
    int rez = termen();
    while ( k <= n && ( s[k] == '+' || s[k] == '-' ) ) {
        char semn = s[k++];
        rez = op ( rez, termen(), semn );
    }
    return rez;
}
int main () {
    fin >> ( s + 1 );
    n = strlen ( s + 1 );
    k = 1;
    fout << eval();

    return 0;
}
