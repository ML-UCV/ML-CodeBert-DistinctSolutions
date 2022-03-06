#include <stdio.h>
#include <algorithm>






int v[30000 +1],aint[30000*4+1],v2[30000 +1];



void update(int nod,int st,int dr,int poz,int val){

  if(st==dr){

    aint[nod]=val;

  }

  else{

    int mij=(st+dr)/2;

    if(poz<=mij){

      update(2*nod,st,mij,poz,val);

    }

    else if(poz>mij){

      update(2*nod+1,mij+1,dr,poz,val);

    }

    aint[nod]=aint[2*nod]+aint[2*nod+1];

  }

}



int query(int nod,int st,int dr,int poz){

  if(st==dr){

    return st;

  }

  else{

    int mij=(st+dr)/2;

    if(poz<=aint[2*nod]){

      return query(2*nod,st,mij,poz);

    }

    else if(poz>aint[2*nod]){

      return query(2*nod+1,mij+1,dr,poz-aint[2*nod]);

    }

  }

}



int main()

{

  FILE *fin,*fout;

  fin=fopen("schi.in","r");

  fout=fopen("schi.out","w");



  int n,i,pozint;

  fscanf(fin,"%d",&n);

  for(i=1;i<=n;i++){

    fscanf(fin,"%d",&v[i]);

    update(1,1,n,i,1);

  }

  for(i=n;i>=1;i--){

    pozint=query(1,1,n,v[i]);

    update(1,1,n,pozint,0);

    v2[pozint]=i;

  }

  for(i=1;i<=n;i++){

    fprintf(fout,"%d\n",v2[i]);

  }



  fclose(fin);

  fclose(fout);

  return 0;

}
