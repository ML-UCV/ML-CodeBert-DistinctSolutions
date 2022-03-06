#include <fstream>
#include <cstring>




using namespace std;



ifstream f("strmatch.in");



ofstream g("strmatch.out");







char a[2000002],b[2000002];



int n,m,p[2000002],sol[1003],nr;
void prefix(char s[],int n){



 p[1]=0;



 int k=0;



 for(int i=2;i<=n;i++){



  while(k && s[i]!=s[k+1])



    k=p[k];



  if(s[i]==s[k+1])



    k++;



  p[i]=k;



 }



}







void ad(char a[],int n){



 for(int i=n;i>0;i--)a[i]=a[i-1];



 a[0]=' ';



}







void kmp(char a[],int n,char b[],int m){



 if(n>m)return;



  if(n==m){if(strcmp(a,b)==0){g<<"1\n";return;}



   else return;}



 ad(a,n);



 ad(b,m);



 prefix(a,n);



 int k=0;



 for(int i=1;i<=m;i++){



  while(k && a[k+1]!=b[i])



   k=p[k];



   if(a[k+1]==b[i])k++;



   if(k==n){



   k=p[n];



   ++nr;



   if(nr<=1000)



   sol[nr]=i-n;



    }



  }



}
int main(){



 f.getline(a,2000001);



 f.getline(b,2000001);



 kmp(a,strlen(a),b,strlen(b));



 g<<nr<<'\n';



 if(nr>1000)nr=1000;



 for(int i=1;i<=nr;i++)



    g<<sol[i]<<' ';



}
