#include<cstdio>
#include<cstring>
int n,p[26][50001],s[50001],v[50001],i,j,k,nr;

char a[50001],b[50001];

void add(int x){

 k=1;

 while(!(x&k)) k<<=1;

 for(j=x;j<=n;){

  v[j]++;

  while(!(j&k)) k<<=1;

  j=j+k;}

}



int get(int x){

 k=1;

 while(!(x&k))k<<=1;

 int s=0;

 for(j=x;j>=1;){

  s=s+v[j];

  while(!(j&k)) k<<=1;

  j=j-k;}

 return s;}



int main()

{

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);

 scanf(" %s %s ",a,b);

 n=strlen(a);

 if(n!=strlen(b)) {printf("-1");fclose(stdout);return 0;}

 for(i=0;i<n;i++)

  p[a[i]-'a'][++p[a[i]-'a'][0]]=i+1;

 for(i=0;i<26;i++) p[i][0]=0;

 for(i=0;i<n;i++)

  if(!p[b[i]-'a'][++p[b[i]-'a'][0]]) {printf("-1");fclose(stdout);return 0;}

  else s[p[b[i]-'a'][p[b[i]-'a'][0]]]=i+1;

 for(i=1;i<=n;i++){

  add(s[i]);

  nr+=s[i]-get(s[i]);}

 printf("%d",nr);

 fclose(stdout);

 return 0;}
