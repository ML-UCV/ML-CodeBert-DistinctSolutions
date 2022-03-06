#include<stdio.h>
#include<string.h>
struct nod{

long int info;

nod *next;

};

nod *prima[30],*ultima[30],*primb[30],*ultimb[30],*pa,*pb;

long int la,lb,i,fra[30],frb[30],slot,p[50002],q[50002],sol;

char a[50002],b[50002],*aa,*bb;

void punea(long int ii,long int jj);

void puneb(long int ii,long int jj);

void mergesort(long int ll,long int rr);

void merge(long int p1,long int p2,long int p3);

int main()

{

 FILE *f,*g;f=fopen("swap.in","r");g=fopen("swap.out","w");

 aa=&a[0];bb=&b[0];

 fscanf(f,"%s",aa);fscanf(f,"%s",bb);la=strlen(aa);lb=strlen(b);

 if(la!=lb){fprintf(g,"-1\n");fcloseall();return 0;}

 for(i=0;i<la;i++){slot=(long int)(a[i]-'a');fra[slot]++;punea(slot,i+1);}

 for(i=0;i<lb;i++){slot=(long int)(b[i]-'a');frb[slot]++;puneb(slot,i+1);}

 for(i=0;i<30;i++) if(fra[i]!=frb[i]) {fprintf(g,"-1\n");fcloseall();return 0;}

 for(i=0;i<30;i++) if(fra[i]) {pa=prima[i];pb=primb[i];while(pa){ p[pa->info]=pb->info;pa=pa->next;pb=pb->next;}}

 mergesort(1,la);

 fprintf(g,"%ld\n",sol);

 fcloseall();

 return 0;

}

void punea(long int ii,long int jj)

{

 nod *ploc;

 ploc=new nod;

 ploc->info=jj;

 ploc->next=0;

 if(!prima[ii]){prima[ii]=ploc;ultima[ii]=ploc;return;}

 ultima[ii]->next=ploc;ultima[ii]=ploc;

}

void puneb(long int ii,long int jj)

{

 nod *ploc;

 ploc=new nod;

 ploc->info=jj;

 ploc->next=0;

 if(!primb[ii]){primb[ii]=ploc;ultimb[ii]=ploc;return;}

 ultimb[ii]->next=ploc;ultimb[ii]=ploc;

}

void mergesort(long int ll,long int rr)

{ long int mm,aux;

 if(rr==ll) return;

 if(rr==ll+1)

  { if(p[ll]>p[rr]) {sol++;aux=p[ll];p[ll]=p[rr];p[rr]=aux;}

    return;

  }

 mm=(ll+rr)/2;

 mergesort(ll,mm);

 mergesort(mm+1,rr);

 merge(ll,mm,rr);

}

void merge(long int p1,long int p2,long int p3)

{ long int ii,pp,pp1,pp2,ramase;

 for(ii=p1;ii<=p3;ii++)q[ii]=p[ii];

 pp=p1;pp1=p1;pp2=p2+1;ramase=p2-p1+1;

 while(pp1<=p2&&pp2<=p3)

 { if(q[pp1]<q[pp2]) { p[pp]=q[pp1];ramase--;pp1++;}

   else { p[pp]=q[pp2];sol+=ramase; pp2++;}

   pp++;

 }

 while(pp1<=p2){ p[pp]=q[pp1];pp1++;pp++;}

 while(pp2<=p3){ p[pp]=q[pp2];pp2++;pp++;}

}
