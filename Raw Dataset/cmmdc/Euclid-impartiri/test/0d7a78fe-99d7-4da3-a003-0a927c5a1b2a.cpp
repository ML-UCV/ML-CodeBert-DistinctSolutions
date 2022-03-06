#include <stdio.h>


using namespace std;



int cmmdc(int a, int b){

  int r;



  while(b>0){

    r=a%b;

    a=b;

    b=r;

  }



  return a;

}



int solve(int n){

  int r;



  if(n==1)

    r=0;

  else

    r=n;



  return r;

}

int main(){

  FILE *fin, *fout;



  fin=fopen("cmmdc.in", "r");

  fout=fopen("cmmdc.out", "w");



  int a, b;



  fscanf(fin, "%d%d", &a, &b);



  fprintf(fout, "%d\n", solve(cmmdc(a, b)));



  fclose(fin);

  fclose(fout);



  return 0;

}
