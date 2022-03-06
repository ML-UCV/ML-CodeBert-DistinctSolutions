#include <stdio.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

FILE *fin = fopen("strmatch.in", "r");

FILE *fout = fopen("strmatch.out", "w");







const int DIM = 2e6 + 7;

int p,t,i,j,lps[2000005],nrap,ap[DIM],k,lg;

char patt[2000005],txt[2000005];

int main()



{

 fgets(patt+1, 2000005, fin);

    fgets(txt+1, 2000005, fin);





       p = strlen( patt + 1 )-1;

       t = strlen( txt + 1 )-1;







    lps[0] = -1;lps[1]=0;

 lg=0;



    for(i=2; i<=p; ++i){

        while(lg>0 and patt[i]!=patt[lg+1])

            lg=lps[lg];

        if(patt[i]==patt[lg+1])

            lg++;

        lps[i]=lg;

    }



    i = 1; j = 1;lg=0;



    while(i<=t )

    {

       while(lg>0 and txt[i]!=patt[lg+1])

        lg=lps[lg];

       if(txt[i]==patt[lg+1])

        lg++;

       if(lg==p)

       {

           ap[++nrap]=i-p;

           lg=lps[p];

       }

     i++;

    }



    fprintf(fout, "%d\n", nrap);



   if(nrap>1000) nrap=1000;

    for(i=1; i<=nrap; ++i)

        fprintf(fout,"%d ",ap[i]);



    fclose(fin);

    fclose(fout);

    return 0;

}
