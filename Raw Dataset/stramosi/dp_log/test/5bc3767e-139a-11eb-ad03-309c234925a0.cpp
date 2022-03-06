#include <stdio.h>


int d[18][250001];

int main(){

  FILE *fin=fopen("stramosi.in","r");

  FILE *fout=fopen("stramosi.out","w");

  int n,m,i,j,q,p;



  fscanf(fin,"%d%d",&n,&m);

  for(i=1; i<=n; i++)

    fscanf(fin,"%d",&d[0][i]);

  for(i=1; i<18; i++)

    for(j=1; j<=n; j++)

      d[i][j]=d[i-1][d[i-1][j]];

  for(i=0; i<m; i++){

    fscanf(fin,"%d%d",&q,&p);

    j=0;

    while(p){

      if(p%2!=0)

        q=d[j][q];

      p/=2;

      j++;

    }

    fprintf(fout,"%d\n",q);

  }

  fclose(fin);

  fclose(fout);

  return 0;

}
