#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;



char a[50111],b[50111];

int q,nr[111],nr2[111],*l[111],S,sol,v[50111],A[50111 * 4],i,n,poz[50111];



void query(int nod,int p,int u,int a,int b){

  int mij=(p+u)>>1;



  if(a<=p && u<=b){

    S+=A[nod];

    return;

  }



  if(a<= mij)

    query(nod<<1,p,mij,a,b);

  if(b > mij)

    query((nod<<1)+1,mij+1,u,a,b);



}





void update(int nod,int p,int u,int poz,int val){

  int mij=(p+u)>>1;



  if(p == u){

    A[nod] = val;

    return ;

  }



  if(poz<=mij)

    update(nod<<1,p,mij,poz,val);

  else

    update((nod<<1)+1,mij+1,u,poz,val);





  A[nod] = A[nod<<1]+A[(nod<<1)+1];

}





void afis(){



  FILE *g=fopen("swap.out","w");

  fprintf(g,"%d",sol);

  fclose(g);



}



int main(){



  FILE *f=fopen("swap.in","r");

  a[0]=b[0]=' ';

  fscanf(f,"%s",a+1);

  fscanf(f,"%s",b+1);



  n=strlen(a);



  if(strlen(a) != strlen(b)){

    sol=-1;

    afis();

    return 0;

  }



  n--;



  for(i=1;i<=n;i++)

    nr[a[i]-96]++;



  for(i=1;i<=n;i++)

    nr2[b[i]-96]++;





  for(i=0;i<=28;i++)

    if(nr[i] != nr2[i]){

      sol=-1;

      afis();

      return 0;

    }





  for(i=0;i<=28;i++){

  l[i]=new int [nr[i]+5];

  l[i][0]=0;

  nr[i]=0;

  }



  for(i=1;i<=n;i++){

  q=a[i]-96;

  l[q][++l[q][0]] = i;

  }



  for(i=1;i<=n;i++){

  q=b[i] - 96;

  v[i] = l[q][++nr[q]];

  }



fclose(f);



  for(i=1;i<=n;i++)

    poz[v[i]] = i;



  for(i=1;i<=n;i++)

    if(v[i] == 1)

      update(1,1,n,i,0);

    else

      update(1,1,n,i,1);



  query(1,1,n,1,poz[1]);

  sol=S;



  for(i=2;i<=n;i++){

    update(1,1,n,poz[i-1],0);

    update(1,1,n,poz[i],0);

    S=0;

    query(1,1,n,1,poz[i]);

    sol+=S;

  }



afis();



return 0;

}
