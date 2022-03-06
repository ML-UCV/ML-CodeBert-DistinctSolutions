#include <fstream>


using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

int expresie(), termen(), factor();

int i;

char s[100010];



int expresie(){

    int r = termen();

    while ( s[i] == '+' || s[i] == '-' ) {

        if ( s[i] == '+' ){

            i++;

            r += termen();

        } else {

            i++;

            r -= termen();

        }

    }

    return r;

}



int termen(){

    int r = factor();

    while ( s[i] == '*' || s[i] == '/' ){

        if ( s[i] == '*' ){

            i++;

            r *= factor();

        } else {

            i++;

            r /= factor();

        }

    }

    return r;

}



int factor(){

    int r;

    if ( s[i] == '(' ){

        i++;

        r = expresie();

        i++;

    } else {

        r = 0;

        while ( s[i] >= '0' && s[i] <= '9' )

            r = r*10+s[i++]-'0';

    }

    return r;

}



int main()

{

    f>>s; i = 0;

    g<<expresie();

    return 0;

}
