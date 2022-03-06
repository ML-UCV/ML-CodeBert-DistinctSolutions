#include<fstream>
#include<string.h>


using namespace std;





ifstream f("swap.in");

ofstream g("swap.out");

long nr[50100],NR[50100],i,n,num,P[50100],B[50100],a[50100][30],A[50100];

char s[50100],t[50100];

void merge (int st,int dr ) {



 if(st==dr)

  return ;

 int m=(st+dr)>>1;



 int i,j,p;

 merge(st,m);

 merge(m+1,dr);

 i=st;j=m+1;p=0;

 while(i<=m || j<=dr ){

  if((P[j]<P[i] && j<=dr )|| i>m){

   B[st+p++]=P[j++];

   num+=m-i+1;

  }

  else

   B[st+p++]=P[i++];

 }

 for(int u=st;u<=dr;++u){

  P[u]=B[u];

  B[u]=0;

 }

}

int main (){

 f>>(s+1);

 f.get();f>>(t+1);

 f.get();

 n=strlen(s+1);

 for(i=1;i<=n;++i){

  a[++nr[s[i]-96]][s[i]-96]=i;



 }



 for(i=1;i<=n;i++){



  P[a[++NR[t[i]-96]][t[i]-96]]=i;



 }

 for(i=0;i<=26;i++)

  if(NR[i]!=nr[i]){

   g<<-1<<"\n";



   return 0;

  }

 merge(1,n);

 g<<num<<"\n";

 return 0;

}
