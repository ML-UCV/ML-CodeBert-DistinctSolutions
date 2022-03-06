#include <stdio.h>
using namespace std;

int main(){

  FILE *fin, *fout;

  int a, b, r;

  fin=fopen("cmmdc.in", "r");

  fout=fopen("cmmdc.out", "w");

  fscanf(fin, "%d%d", &a, &b);

  while(b>0){

    r=a%b;

    a=b;

    b=r;

  }

  if(a==1)

    a=0;

  fprintf(fout, "%d\n", a);

  fclose(fin);

  fclose(fout);

  return 0;

}
