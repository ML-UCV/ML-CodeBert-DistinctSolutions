#include<stdio.h>
#include<string.h>






int main(){

freopen("swap.in","r",stdin);

freopen("swap.out","w",stdout);

char si[50000 +1],sf[50000 +1];

int i,j,k,k2,f[26],f1[26],l,ok,pi,pf,n0,

ud,poz[26]={0},a[26][50000/4],p,uc[26]={0};

long long nr;

scanf("%s%s",si,sf);

l=strlen(si);

for(i=0;i<26;i++) f[i]=f1[i]=0;

for(i=0;si[i];++i){

 a[si[i]-'a'][f[si[i]-'a']]=i;

 f[si[i]-'a']++;

 f1[sf[i]-'a']++;

 }

ok=1;

for(i=0;i<26&&ok;++i)

 ok=f[i]==f1[i];

if(!ok) {nr=-1;goto finish;}

nr=0;

pi=0;pf=l-1;ud=0;

for(i=0;i<l-1;++i){

 p=poz[sf[i]-'a'];

 j=a[sf[i]-'a'][p];

 n0=0;

 if(j)

  for(k=0;k<26;++k)

  if(poz[k])

   if(a[k][poz[k]-1]<j) n0+=poz[k];

   else {

    while(uc[k]&&a[k][uc[k]]>=j) uc[k]--;



    for(k2=uc[k];a[k][k2]<j;++k2);



    uc[k]=k2;

    n0+=uc[k];



    }

 nr+=j-n0;

 si[j]=32;

 poz[sf[i]-'a']++;

 }

finish:

printf("%lld",nr);

return 0;

}
