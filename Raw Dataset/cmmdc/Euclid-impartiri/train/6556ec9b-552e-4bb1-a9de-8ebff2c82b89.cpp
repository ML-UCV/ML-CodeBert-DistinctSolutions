#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b){
 if(!b) return a;
 return cmmdc(b, a%b);
}
int main()
{
 ifstream in("cmmdc.in");
 ofstream out("cmmdc.out");
 int a, b;
 in>>a>>b;
 int gcd = cmmdc(a, b);
 if(gcd==1)
  out<<0;
 else
  out<<cmmdc(a, b);

}
