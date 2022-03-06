#include <stdio.h>
#include <string.h>


using namespace std;
char a[2000000 +1],b[2000000 +1];

int v[2000000 +1];



int deletecif(int cif,int pow){

  return cif*pow;

}



int main()

{

  FILE *fin,*fout;

  fin=fopen("strmatch.in","r");

  fout=fopen("strmatch.out","w");



  int i,j,nra,sizea,sirurimatch,nrb,inceput,sfarsit,pow,sizeb,sizev,nrb2,nra2,pow2;



  fscanf(fin,"%s",a);

  fscanf(fin,"%s",b);



  sizea=strlen(a);

  nra=0;

  nra2=0;

  i=0;



  while(a[i]!='\0'){

    nra=((nra*128)%666013 +a[i]%666013)%666013;

    nra2=((nra2*128)%666019 +a[i]%666019)%666019;

    i++;

  }



  nrb=0;

  nrb2=0;

  sizeb=0;

  j=0;



  while(sizeb<sizea){

    nrb=((nrb*128)%666013 +b[j]%666013)%666013;

    nrb2=((nrb2*128)%666019 +b[j]%666019)%666019;

    sizeb++;

    j++;

  }



  pow=1;

  pow2=1;

  for(i=1;i<=sizea-1;i++){

    pow=(pow*128)%666013;

    pow2=(pow2*128)%666019;

  }



  sirurimatch=0;

  inceput=0;

  sfarsit=sizea;

  sizev=0;



  while(b[j]!='\0'){

    if(nra==nrb&&nra2==nrb2){

      sirurimatch++;

      v[sizev++]=inceput;

    }

    nrb=(nrb%666013 -(deletecif(b[inceput],pow)%666013)+666013)%666013;

    nrb2=(nrb2%666019 -(deletecif(b[inceput],pow2)%666019)+666019)%666019;

    inceput++;

    nrb=((nrb*128)%666013 +b[j]%666013)%666013;

    nrb2=((nrb2*128)%666019 +b[j]%666019)%666019;

    sfarsit++;

    j++;

  }

  if(nra==nrb&&nra2==nrb2){

      sirurimatch++;

      v[sizev++]=inceput;

    }



  fprintf(fout,"%d\n",sirurimatch);

  for(i=0;i<sizev&&i<1000;i++){

    fprintf(fout,"%d ",v[i]);

  }



  fclose(fin);

  fclose(fout);

  return 0;

}
