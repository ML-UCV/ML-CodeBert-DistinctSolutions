#include <stdio.h>






char a[50002],b[50002];

int lita[27][50002],litb[27][50002];

int P[50002],B[50002];

int N,nr,ok;



void merge(int l,int r){

 int m=l+(r-l)/2,aux;

 if( l==r ) return;

 if( l==r-1 ){

  if( P[l]>P[r] ) ++nr, aux=P[l],P[l]=P[r],P[r]=aux;

  return;

 }



 merge(l,m);

 merge(m+1,r);



 int i,j;

 B[0]=0;

 for(i=l,j=m+1; i<=m && j<=r; )

  if( P[i] <= P[j] ) B[++B[0]]=P[i++];

  else B[++B[0]]=P[j++], nr+=m-i+1;

 for(; i<=m; ++i) B[++B[0]]=P[i];

 for(; j<=r; ++j) B[++B[0]]=P[j];



 for(i=l;i<=r;++i) P[i]=B[i-l+1];



}



void precal_p(){

 int i,j;

 for(i=0;i<27;++i)

  if( lita[i][0] != litb[i][0] ){

   ok=0; return;

  }

  else

  for(j=1;j<=lita[i][0];++j)

   P[lita[i][j]]=litb[i][j];

}



int main(){

 int i;

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);

 scanf("%s%s",a+1,b+1);

 for(i=1; a[i]!='\0' && a[i]!='\n'; ) ++i;

 N=i-1;



 for(i=1;i<=N;++i){

  lita[a[i]-'a'][++lita[a[i]-'a'][0]]=i;

  litb[b[i]-'a'][++litb[b[i]-'a'][0]]=i;

 }



 ok=1;

 precal_p();

 if( ok ) merge(1,N);

 else nr=-1;



 printf("%d\n",nr);

 fclose(stdin); fclose(stdout);

 return 0;

}
