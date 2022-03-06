#include <stdio.h>


using namespace std;
int father[20 +1][250000 +1];
void precalc(int n){

  int i,j;

  for(j=1;j<20;j++){

    for(i=1;i<=n;i++){

      father[j][i]=father[j-1][father[j-1][i]];

    }

  }

}



int answer(int nod,int x){

  int j;

  for(j=0;(1<<j)<=x;j++){

    if(((1<<j)&x)!=0)

      nod=father[j][nod];

  }

  return nod;

}



int main()

{

  FILE *fin,*fout;

  fin=fopen("stramosi.in","r");

  fout=fopen("stramosi.out","w");

  int n,m,i,j,x,y;

  fscanf(fin,"%d%d",&n,&m);

  for(i=1;i<=n;i++){

    fscanf(fin,"%d",&father[0][i]);

  }



  precalc(n);

  for(i=1;i<=m;i++){

    fscanf(fin,"%d%d",&x,&y);

    fprintf(fout,"%d\n",answer(x,y));

  }

  fclose(fin);

  fclose(fout);

  return 0;

}
