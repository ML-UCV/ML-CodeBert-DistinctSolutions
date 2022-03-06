#include <fstream>


using namespace std;



const int N = 1e5;



char s[N + 1];

int p;



int expresie();

int termen();

int factor();



int expresie() {

    int sum = termen();

    while (s[p] == '+' || s[p] == '-') {

        if (s[p] == '+') {

            ++p;

            sum += termen();

        }

        else {

            ++p;

            sum -= termen();

        }

    }

    return sum;

}



int termen() {

    int prod = factor();

    while (s[p] == '*' || s[p] == '/') {

        if (s[p] == '*') {

            ++p;

            prod *= factor();

        }

        else {

            ++p;

            prod /= factor();

        }

    }

    return prod;

}



int factor() {

    int semn = 1, val = 0;

    if (s[p] == '-') {

        semn = -1;

        ++p;

    }

    if (s[p] == '(') {

        ++p;

        val = expresie();

        ++p;

        return val * semn;

    }

    while (isdigit(s[p])) {

        val = val * 10 + (s[p] - '0');

        ++p;

    }

    return semn * val;

}



int main() {

    ifstream in("evaluare.in");

    ofstream out("evaluare.out");



    in >> s;

    out << expresie();



    in.close();

    out.close();

    return 0;

}
