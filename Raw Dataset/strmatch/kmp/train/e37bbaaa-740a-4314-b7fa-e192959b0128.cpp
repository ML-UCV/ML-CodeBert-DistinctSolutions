#include <stdio.h>
#include <string.h>
#include <iostream>






using namespace std;



FILE *fin = fopen("strmatch.in", "r");

FILE *fout = fopen("strmatch.out", "w");



char patt[2000005],txt[2000005];

int p,t,i,lg,lps[2000005],ap[1005],nrap;



int main()

{

    fgets(patt+1, 2000005 -2, fin);

    fgets(txt+1, 2000005 -2, fin);

    patt[0] = txt[0] = '.';

    p = strlen(patt)-2;

    t = strlen(txt)-2;



    for(i=2; i<=p; ++i)

    {

        while(patt[i] != patt[lg+1] and lg>0)

            lg = lps[lg];

        if(patt[i] == patt[lg+1])

            lg++;

        lps[i] = lg;

    }



    lg = 0;

    for(i=1; i<=t; ++i)

    {

        while(txt[i] != patt[lg+1] and lg>0)

            lg = lps[lg];



        if(txt[i] == patt[lg+1])

            ++lg;



        if(lg == p)

        {

            ++nrap;

            if(nrap <= 1000)

                ap[nrap] = i-p;

            lg = lps[lg];

        }

    }



    fprintf(fout, "%d\n", nrap);

    nrap = min(nrap, 1000);

    for(i=1; i<=nrap; ++i)

        fprintf(fout, "%d ", ap[i]);



    fclose(fin);

    fclose(fout);

    return 0;

}
