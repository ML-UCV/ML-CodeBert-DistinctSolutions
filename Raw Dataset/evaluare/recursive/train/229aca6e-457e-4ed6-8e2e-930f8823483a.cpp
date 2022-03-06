#include <fstream>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

char c[100001];

int i;

int solve();

int mul();

int num();

int solve() {

    int t = mul();

    while (c[i] == '+' || c[i] == '-') {

        if (c[i] == '+') {

            i++;

            t += mul();

        } else {

            i++;

            t -= mul();

        }

    }

    return t;

}

int mul() {

    int t = num();

    while (c[i] == '*' || c[i] == '/') {

        if (c[i] == '*') {

            i++;

            t *= num();

        } else {

            i++;

            t /= num();

        }

    }

    return t;

}

int num() {

    int t = 0;

    if (c[i] == '(') {

        i++;

        t = solve();

        i++;

    } else {

        while (isdigit(c[i])) {

            t = t * 10 + (int)c[i++] - '0';

        }

        return t;

    }

}

int main() {

    fin.getline(c, 100001);

    fout << solve();

    return 0;

}
