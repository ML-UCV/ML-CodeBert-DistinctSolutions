#include <stdio.h>
#include <string.h>






FILE *fin,*fout;



typedef long long LL;



char sir[2][50001 +1];



int nr[28],cp[28];

int *poz[28],scade[28],pos[28];



int scos[50001 +1];



LL num;



void proces()

{int i,j,l;

 l=strlen(sir[0]);

 for (i=1;i<='z'-'a'+1;++i) nr[i]=0;

 for (j=0;j<l;++j) ++nr[sir[0][j]-'a'+1];

 for (i=1;i<='z'-'a'+1;++i) {poz[i]=new int[nr[i]+1];nr[i]=0;}

 for (j=0;j<l;++j)

    {i=sir[0][j]-'a'+1;

     ++nr[i];

     poz[i][nr[i]]=j;

    }

}



int main()

{int i,l,j,val,p;

 fin=fopen("swap.in","r");

 fscanf(fin,"%s %s",sir[0],sir[1]);

 fclose(fin);

 proces();

 for (i=1;i<='z'-'a'+1;++i)

     {cp[i]=1;

      if (nr[i]) pos[i]=poz[i][1];

      else pos[i]=-1;

     }

 l=strlen(sir[0]);

 num=0;

 for (i=0;i<l;++i)

     {val=sir[1][i]-'a'+1;

      if (cp[val]>nr[val])

         {num=-1;break;}

      else {p=poz[val][cp[val]];

            num=num+p-scade[val];

            scos[p]=1;

            for (j=1;j<='z'-'a'+1;++j) if (pos[j]>p) ++scade[j];

            ++cp[val];

            if (cp[val]<=nr[val])

               for (;pos[val]<=poz[val][cp[val]];++pos[val])

                   scade[val]+=scos[pos[val]];

           }

     }

 fout=fopen("swap.out","w");

 fprintf(fout,"%lld\n",num);

 fclose(fout);

 return 0;

}
