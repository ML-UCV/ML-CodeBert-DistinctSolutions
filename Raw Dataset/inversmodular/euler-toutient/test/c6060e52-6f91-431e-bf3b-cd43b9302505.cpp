#include <fstream>

using namespace std;
ifstream fin ("inversmodular.in");
ofstream fout ("inversmodular.out");

long long putere_log (long long a,long long n,long long modulol)
{
 if(n==0)
  return 1;
 else
 {
  if(n%2==1)
   return ((a%modulol)*((putere_log((a%modulol)*(a%modulol)%modulol,n/2,modulol)%modulol)))%modulol;
  else
   return (putere_log(((a%modulol)*(a%modulol))%modulol,n/2,modulol))%modulol;
 }
}
long long phi_de_n (long long n)
{
 long long phin=1,d=2,contorcrt;
 while(n>1)
 {
  if(n%d==0)
  {
   contorcrt=0;
   while(n%d==0)
    n/=d,contorcrt++;
   phin=phin*(d-1)*putere_log(d,contorcrt-1,1000000007);
  }
  d++;
  if(d*d>n)
   d=n;
 }
 return phin;
}
long long invers_modular(long long a,long long n)
{

 return putere_log(a,phi_de_n(n)-1,n);

}
int main ()
{
 long long a,n;
 fin>>a>>n;
 fout<<invers_modular(a,n);
 return 0;
}
