#include<fstream>#include <stdio.h>#include <cstring>
using namespace std;

long n,m,i,j,r[50001],k,v[50001],x[30],y[30],a[30][50001],b[30][50001];

long long l;

char s1[50001],s2[50001],c;



void merge(long r[50001],long p,long q,long long *l)

{long i,j,k,m=(p+q)/2;

if(p==q)

        return;

merge(r,p,m,l);

merge(r,m+1,q,l);

for(i=k=p,j=m+1;i<=m||j<=q;)

if(j>q||(i<=m&&r[i]<r[j]))

        v[k++]=r[i++];

else

        {(*l)+=m-i+1;

        v[k++]=r[j++];}

for(i=p;i<=q;i++)

        r[i]=v[i];}



int main()

{ifstream f("swap.in");

ofstream g("swap.out");

f>>s1;

f>>s2;

n=strlen(s1);

for(i=0;i<n;i++)

       {x[s1[i]-'a']++;

       a[s1[i]-'a'][x[s1[i]-'a']]=i;}

for(j=0;j<n;j++)

       {y[s2[j]-'a']++;

       b[s2[j]-'a'][y[s2[j]-'a']]=j;}

for(c='a';c<='z';c++)

if(x[c-'a']==y[c-'a'])

       {for(i=1;i<=x[c-'a'];i++)

              r[a[c-'a'][i]]=b[c-'a'][i];}

else

       k=1;

if(!k)

       merge(r,0,n-1,&l),g<<l;

else

       g<<"-1";

return 0;}
