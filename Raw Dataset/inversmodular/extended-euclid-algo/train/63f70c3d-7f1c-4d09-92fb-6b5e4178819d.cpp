#include <fstream>
using namespace std;
ifstream cin("inversmodular.in");
ofstream cout("inversmodular.out");
long gcd(long a, long b, long &x, long &y){
 if (!b){
  x=1;
  y=0;
  return a;
 }
 else{
  long d, x0, y0;
  d=gcd(b, a%b, x0, y0);
  x=y0;
  y=x0-(a/b)*y0;
  return d;
 }
}
int main()
{
 long a, n, x, y;
 cin>>a>>n;
 gcd(a, n, x, y);
 while (x<0){
  x=x+n;
 }
 cout<<x;
 cin.close();
 cout.close();
}
