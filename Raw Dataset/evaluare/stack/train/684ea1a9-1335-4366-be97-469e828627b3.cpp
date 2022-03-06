#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;



const int NMAX = 100005;

int fp[NMAX], st[NMAX], s[NMAX];

char sh[NMAX];



int main() {



    freopen ("evaluare.in", "r", stdin);

    freopen ("evaluare.out", "w", stdout);



    int n, nfp, nst, x, i, nr, dei;



    scanf ("%s", sh);



    n = strlen(sh);

    for (i = 0; i < n; i++) {

        if (sh[i] == '*')

            s[i] = -1;

        if (sh[i] == '/')

            s[i] = -2;

        if (sh[i] == '+')

            s[i] = -3;

        if (sh[i] == '-')

            s[i] = -4;

        if (sh[i] == '(')

            s[i] = -5;

        if (sh[i] == ')')

            s[i] = -6;

        if (sh[i] >= '0' && sh[i] <= '9')

            s[i] = sh[i] - '0';

    }

    nfp = 0;

    nst = 0;

    i = 0;

    while (i < n) {

        x = s[i];

        if (x >= 0) {

            nr = 0;

            while (i < n && s[i] >= 0) {

                nr = nr * 10 + s[i];

                i++;

            }

            nfp++;

            fp[nfp] = nr;

        }

        else {

            while (i < n && s[i] < 0) {

                x = s[i];

                if (x == -5) {

                    nst++;

                    st[nst] = x;

                }

                else if (x >= -2) {

                    while (nst > 0 && st[nst] >= -2) {

                        nfp++;

                        fp[nfp] = st[nst];

                        nst--;

                    }

                    nst++;

                    st[nst] = x;

                }

                else if (x >= -4) {

                    while (nst > 0 && st[nst] >= -4) {

                        nfp++;

                        fp[nfp] = st[nst];

                        nst--;

                    }

                    nst++;

                    st[nst] = x;

                }

                else {

                    while (nst > 0 && st[nst] != -5) {

                        nfp++;

                        fp[nfp] = st[nst];

                        nst--;

                    }

                    nst--;

                }

                i++;

            }

        }

    }

    while (nst > 0) {

        nfp++;

        fp[nfp] = st[nst];

        nst--;

    }







    nst = 0;

    for (i = 1; i < NMAX; i++)

        st[i] = 0;

    nfp++;

    fp[nfp] = -3;
    for (i = 0; i <= nfp; i++) {

        if (fp[i] >= 0) {

            nst++;

            st[nst] = fp[i];

            dei = 1;

        }

        else {

            nst--;

            if (fp[i] == -1)

                st[nst] *= st[nst + 1];

            if (fp[i] == -2)

                st[nst] /= st[nst + 1];

            if (fp[i] == -3)

                st[nst] += st[nst + 1];

            if (fp[i] == -4)

                st[nst] -= st[nst + 1];

        }

    }

    if (st[0] != 0)

        printf ("%d", st[0]);

    else

        printf ("%d", st[1]);







    return 0;

}
