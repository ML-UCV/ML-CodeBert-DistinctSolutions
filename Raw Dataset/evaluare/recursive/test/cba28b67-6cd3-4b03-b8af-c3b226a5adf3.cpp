#include <fstream>
using namespace std;

char s[100010];

int i;



int expresie();

int termen();

int factor();



int main() {

    ifstream fin ("evaluare.in");

    ofstream fout("evaluare.out");



    fin>>s;

    i = 0;

    fout<<expresie();



}
int expresie() {







    int r = termen();

    while (s[i] == '+' || s[i] == '-') {

        if (s[i] == '+') {

            i++;

            r += termen();

        } else {

            i++;

            r -= termen();

        }

    }

    return r;

}



int termen() {

    int r = factor();

    while (s[i] == '*' || s[i] == '/') {

        if (s[i] == '*') {

            i++;

            r *= factor();

        } else {

            i++;

            r /= factor();

        }

    }

    return r;

}



int factor() {

    if (s[i] == '(') {

        i++;

        int r = expresie();

        i++;

        return r;

    } else {



        int r = 0;

        while (s[i] >= '0' && s[i] <= '9') {

            r = r*10 + s[i]-'0';

            i++;

        }

        return r;

    }

}
