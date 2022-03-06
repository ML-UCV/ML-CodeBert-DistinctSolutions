#include <stdio.h>
#include <string.h>






using namespace std;



FILE *fin = fopen("strmatch.in", "r");

FILE *fout = fopen("strmatch.out", "w");



int lgp,n,lg,lps[2000005],nrsol,sol[1005],i;

char patt[2000005],sir[2000005];



int main()

{

    fgets(patt+1, 2000003, fin);

    fgets(sir+1, 2000003, fin);



    patt[0] = sir[0] = 'a';

    lgp = strlen(patt)-2;

    n = strlen(sir)-2;



    lg = 0;

    for(i=2; i<=lgp; ++i)

    {

        while(patt[i] != patt[lg+1] and lg > 0)

            lg = lps[lg];

        if(patt[i] == patt[lg+1])

            ++lg;

        lps[i] = lg;

    }



    lg = 0;

    for(i=1; i<=n; ++i)

    {

        while(sir[i] != patt[lg+1] and lg > 0)

            lg = lps[lg];

        if(sir[i] == patt[lg+1])

            lg++;

        if(lg == lgp)

        {

            ++nrsol;

            if(nrsol <= 1000)

                sol[nrsol] = i-lgp;

            lg = lps[lg];

        }

    }



    if(nrsol > 1000)

    {

        fprintf(fout, "%d\n", nrsol);

        for(i=1; i<=1000; ++i)

            fprintf(fout, "%d ", sol[i]);

    }

    else

    {

        fprintf(fout, "%d\n", nrsol);

        for(i=1; i<=nrsol; ++i)

            fprintf(fout, "%d ", sol[i]);

    }



    fclose(fin);

    fclose(fout);

    return 0;

}
