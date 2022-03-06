#include <stdio.h>
#include <ctype.h>




char s[2000001], t[2000001];

int pi[2000001];

void compute () {

    int i=1, len=0;

    while (isalnum(t[i])){

        if (t[i]==t[len])

            pi[i++]=++len;

        else

            if (len)

                len=pi[len-1];

            else

                pi[i++]=0;

    }

}

int main (void) {

    FILE *fin=fopen ("strmatch.in", "r"),

         *fout=fopen ("strmatch.out", "w");

    fgets(t, sizeof t, fin);

    fgets(s, sizeof s, fin);



    fprintf(fout, "             \n");

    compute();

    int i=0, j=0, ct=0;

    while (isalnum(s[i]))

        if (s[i]==t[j]) {

            ++i, ++j;

            if (!isalnum(t[j])) {

                ++ct;

                if (ct<=1000)

                    fprintf (fout, "%d ", i-j);

                j=pi[j-1];

            }

        }

        else

            if (j)

                j=pi[j-1];

            else

                ++i;

    fseek(fout, 0, SEEK_SET);

    fprintf(fout, "%d", ct);

    return 0;

}
