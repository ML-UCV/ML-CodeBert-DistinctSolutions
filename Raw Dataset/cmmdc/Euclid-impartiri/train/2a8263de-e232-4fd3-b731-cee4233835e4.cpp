#include <stdio.h>


inline int cmmdc (int a, int b) {

    if (!b) return a;

    return cmmdc(b, a%b);

}



int main () {

    FILE *fin=fopen ("cmmdc.in", "r"),

         *fout=fopen ("cmmdc.out", "w");

    int a, b;

    fscanf (fin, "%d%d", &a, &b);

    a=cmmdc(a, b);

    fprintf (fout, "%d", a==1?0:a);

    return 0;

}
