#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



void euclid_e(int a,int b,int& x,int& y,int& d){

 if(b==0) {

  d=a;

  x=1;

  y=0;

  return;

 }

 int xx,yy,q=a/b;

 euclid_e(b,a%b,xx,yy,d);

 x=yy;

 y=xx-yy*q;

}



int main(){

  int a,n,x,y,d;

  FILE *fin,*fout;

  fin=fopen("inversmodular.in","r");

  fout=fopen("inversmodular.out","w");

  fscanf(fin,"%d%d",&a,&n);



  euclid_e(a,n,x,y,d);

  x%=n;

  if(x<0){

    x+=n;

  }



  fprintf(fout,"%d",x);



  fclose(fin);

  fclose(fout);

  return 0;

}
