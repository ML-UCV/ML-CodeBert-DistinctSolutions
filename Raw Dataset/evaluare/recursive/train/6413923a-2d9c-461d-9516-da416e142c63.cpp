#include <iostream>
#include <fstream>


using namespace std;



const int NMAX = 100000;



int v[NMAX];

int poz;



static inline void inainteaza() {

    poz ++;

}

static inline char current_Char() {

    return v[poz];

}

inline int numar() {

    char ch;

    int nr = 0;

    while ( isdigit( ch = current_Char() ) ) {

        nr = nr * 10 + ch - '0';

        inainteaza();

    }

    return nr;

}

int termen();

int expresie();

int factor();



int factor() {

    int semn = 1, val;

    while ( current_Char() == '-' ) {

        semn = -semn;

        inainteaza();

    }

    if ( current_Char() == '(' ) {

        inainteaza();

        val = expresie();

        inainteaza();

    } else {

        val = numar();

    }

    return val;

}

int termen() {

    int val = factor();

    while ( current_Char() == '*' || current_Char() == '/' ) {

        if ( current_Char() == '*' ) {

            inainteaza();

            val *= factor();

        } else {

            inainteaza();

            val /= factor();

        }

    }

    return val;

}

int expresie() {

    int val = termen();

    while ( current_Char() == '+' || current_Char() == '-' ) {

        if ( current_Char() == '+' ) {

            inainteaza();

            val += termen();

        } else {

            inainteaza();

            val -= termen();

        }

    }

    return val;

}

int main() {

    FILE *fin = fopen( "evaluare.in", "r" ), *fout = fopen( "evaluare.out", "w" );

    char ch;

    int i = 0;

    while ( ( ch = fgetc( fin ) ) != '\n' ) {

        v[i ++] = ch;

    }

    fprintf( fout, "%d", expresie() );

    fclose( fin );

    fclose( fout );

    return 0;

}
