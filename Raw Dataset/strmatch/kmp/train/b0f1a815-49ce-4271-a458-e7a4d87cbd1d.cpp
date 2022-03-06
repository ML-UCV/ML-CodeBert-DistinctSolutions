#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("strmatch.in");
ofstream cout("strmatch.out");

char a[2000001], b[2000001];
int prefix[2000001], n, m;
int poz[1001], k;

void crp(){
 int i, j=0;
 prefix[1]=0;
 for (i=2;i<=n;i++){
  while (j>0&&a[j+1]!=a[i])
   j=prefix[j];
  if (a[j+1]==a[i])
   ++j;
  prefix[i]=j;
 }
}

void kmp(){
 int i, j=0;
 for (i=1;i<=m;i++){
  while (j>0&&a[j+1]!=b[i])
   j=prefix[j];
  if (a[j+1]==b[i])
   ++j;
  if (j==n){
   ++k;
   if (k<=1000) poz[k]=i-j;
   j=prefix[j];
  }
 }
 cout<<k<<endl;
 k=min(k, 1000);
 for (i=1;i<=k;i++)
  cout<<poz[i]<<" ";
}

int main()
{
 cin>>(a+1);
 cin.get();
 cin>>(b+1);
 a[0]=b[0]=' ';
 int i;
 n=strlen(a)-1, m=strlen(b)-1;
 crp();
 kmp();
 cin.close();
 cout.close();
 return 0;
}
