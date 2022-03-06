#include<stdio.h>
#include<vector>
#include<string.h>


using namespace std;



int ai[131072],poz,nr,start,finish;



void update(int nod,int st,int dr)

{

 int div;



 if(st==dr)

 {

  ai[nod]=1;

  return;

 }

 div=(st+dr)/2;



 if(poz<=div)

  update(2*nod+1,st,div);

 else

  update(2*nod+2,div+1,dr);

 ai[nod]=ai[2*nod+1]+ai[2*nod+2];

}



void query(int nod,int st,int dr)

{

 int div;



 if(start<=st && dr<=finish)

 {

  nr+=ai[nod];

  return;

 }



 div=(st+dr)/2;

 if(start<=div)

  query(2*nod+1,st,div);

 if(finish>div)

  query(2*nod+2,div+1,dr);

}



int main()

{

 char s[50001],s1[50001],*p,c;

 int i,pos,l=0,nrmin=0,ind[26],pos1;

 vector<int> v[26];



 memset(ai,0,131072*sizeof(int));

 FILE *f=fopen("swap.in","r");

 fscanf(f,"%s\n",s);

 fscanf(f,"%s\n",s1);

 fclose(f);



 pos=0;

 p=s;

 while(*p!='\0')

 {

  v[*p-'a'].push_back(l);

  l++;

  p++;

 }



 for(i=0;i<26;i++)

  ind[i]=0;

 for(pos=0;pos<l;pos++)

 {

  c=s1[pos];

  if(ind[c-'a']>(int) v[c-'a'].size()-1)

  {

   nrmin=-1;

   break;

  }

  pos1=v[c-'a'][ind[c-'a']];

  ind[c-'a']++;

  nr=0;

  start=pos1+1;

  finish=l-1;

  query(0,0,l-1);

  nrmin+=pos1+nr-pos;

  poz=pos1;

  update(0,0,l-1);

 }

 f=fopen("swap.out","w");

 fprintf(f,"%i\n",nrmin);

 fclose(f);

 return 0;

}
