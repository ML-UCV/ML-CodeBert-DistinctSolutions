#include<fstream>

using namespace std;
long long a,b,x,y;

ifstream cin("inversmodular.in");
ofstream cout("inversmodular.out");

void gcd_extended(long long a, long long b, long long&x, long long&y){
 if(!b)
   x=1, y=0;
 else{
   long long x0, y0;
   gcd_extended(b, a%b, x0, y0);
   x=y0;
   y=x0-(a/b)*y0;
 }
}

int main(){
cin>>a>>b;
gcd_extended(a,b,x,y);
while(x<0)
  x+=b;
cout<<x;
  return 0;
}
