#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;



char e[100001];

int n, i;



int evalExpresie();

int evalTermen();

int evalFactor();

int formareNumar();



int main() {

    ifstream f("evaluare.in");

    f.getline(e, 100001);

    f.close();

    n = strlen(e);

    ofstream g("evaluare.out");

    g << evalExpresie();

    g.close();

    return 0;

}



int evalFactor() {

    int p;

    if (e[i] == '(') {

        i++;

        p = evalExpresie();

        i++;

    }

    else

        p = formareNumar();

    return p;

}



int evalTermen() {

    int q = evalFactor();

    while (i < n && (e[i] == '*' || e[i] == '/')) {

        i++;

        if (e[i - 1] == '*')

            q *= evalFactor();

        else q /= evalFactor();

    }

    return q;

}



int evalExpresie() {

    int t = evalTermen();

    while (i < n && (e[i] == '+' || e[i] == '-')) {

        i++;

        if (e[i - 1] == '+')

            t += evalTermen();

        else t -= evalTermen();

    }

    return t;

}



int formareNumar() {

    int nr = 0;

    while (isdigit(e[i]) && i < n) {

        nr = nr * 10 + e[i] - '0';

        i++;

    }

    return nr;

}
