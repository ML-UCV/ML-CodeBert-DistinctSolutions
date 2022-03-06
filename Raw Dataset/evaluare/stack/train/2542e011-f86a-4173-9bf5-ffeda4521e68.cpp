#include <fstream>
using namespace std;

char s[100001];

int nr, k1, k2, rez, i, pr[300];

char st1[100001];

int st2[100001];

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");



int operatie(int a, int b, char sgn)

{

    if (sgn == '+') {

        return a + b;

    } else if (sgn == '*') {

        return a * b;

    } else if (sgn == '/') {

        return a / b;

    } else if (sgn == '-') {

        return a - b;

    }



    return 0;

}



int main() {

    fin >> s;

    pr['+'] = 1;

    pr['-'] = 1;

    pr['('] = 0;

    pr[')'] = 0;

    pr['*'] = 2;

    pr['/'] = 2;



    for (int i = 0; s[i] != 0; i++) {

        if (s[i] >= '0' && s[i] <= '9') {

            nr = 0;

            while (s[i] >= '0' && s[i] <= '9') {

                nr = nr * 10 + s[i] - '0';

                i++;

            }

            i--;

            st2[++k2] = nr;

        } else if (s[i] == '(') {

            st1[++k1] = '(';

        } else if (s[i] == ')') {

            while (st1[k1] != '(') {

                rez = operatie(st2[k2 - 1], st2[k2], st1[k1]);

                k1--; k2--;

                st2[k2] = rez;

            }

            k1--;

        } else {

            while (k1 > 0 && pr[st1[k1]] >= pr[s[i]]) {

                rez = operatie(st2[k2 - 1], st2[k2], st1[k1]);

                k1--; k2--;

                st2[k2] = rez;

            }

            st1[++k1] = s[i];

        }

    }



    while (k1 > 0) {

        rez = operatie(st2[k2 - 1], st2[k2], st1[k1]);

        k1--; k2--;

        st2[k2] = rez;

    }

    fout << st2[1];

    return 0;

}
