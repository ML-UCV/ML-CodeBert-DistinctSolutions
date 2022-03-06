#include<fstream>
#include<iostream>
using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int gcd(int a, int b)

{

 if (a % b == 0)

  return b;

 gcd(b, a % b);

}



int main()

{

 int a, b;

 f >> a >> b;

 int r = gcd(a, b);

 cout << r;

 g << ((r == 1) ? 0 : r);

 return 0;

}
