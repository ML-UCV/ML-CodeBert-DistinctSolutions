#include <bits/stdc++.h>




using namespace std;







long long euclid(long long a, long long b, long long &x, long long &y){

 if(b==0){

  x=1;

  y=0;

  return a;

 }else{

  long long x0,y0,s=euclid(b,a%b,x0,y0);

  x=y0;

  y=x0-y0*(a/b);

  return s;

 }

}



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int main(){

 long long a,n,x,y;

 fin>>a>>n;

 euclid(n,a,x,y);

 while(y<0)y+=n;

 fout<<y;

 return 0;

}
