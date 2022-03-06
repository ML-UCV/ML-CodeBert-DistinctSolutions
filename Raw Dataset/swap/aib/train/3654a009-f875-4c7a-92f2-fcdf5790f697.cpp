#include<fstream>
#include<cstring>
using namespace std;

int n,perm[50100],lit[50100][30],nr[2][30],v[50100],aib[150000];

char A[50100],B[50100];

long long sol;



inline void Aduna(int poz,int val)

{

 while(poz<=n)

 {

  aib[poz]+=val;

  poz+=(poz & -poz);

 }

}



inline int Suma(int poz)

{

 int sum=0;

 while(poz)

 {

  sum+=aib[poz];

  poz-=(poz & -poz);

 }

 return sum;

}



int main()

{

 int i;

 ifstream fin("swap.in");

 fin>>(A+1);

 fin>>(B+1);

 fin.close();



 n=strlen(A+1);

 for(i=1;i<=n;i++)

 {

  v[i]=++nr[0][A[i]-'a'];

  lit[++nr[1][B[i]-'a']][B[i]-'a']=i;

 }

 for(i=0;i<30;i++)

 {

  if(nr[0][i]!=nr[1][i])

   sol=-1;

 }

 if(sol==0)

 {

  for(i=1;i<=n;i++)

   perm[i]=lit[v[i]][A[i]-'a'];

  Aduna(perm[1],1);

  for(i=2;i<=n;i++)

  {

   sol+=(i-1-Suma(perm[i]));

   Aduna(perm[i],1);

  }

 }



 ofstream fout("swap.out");

 fout<<sol<<"\n";

 fout.close();

 return 0;

}
