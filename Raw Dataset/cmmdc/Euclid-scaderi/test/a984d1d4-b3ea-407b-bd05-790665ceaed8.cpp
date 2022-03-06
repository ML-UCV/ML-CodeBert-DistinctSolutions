#include<fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int cmmdc(int a, int b)

{



 while (a != b )

 {

  if (a > b) a = a - b;

  else b = b - a;



 }

 return a;

}

int main()

{

 int a, b;

 f >> a >> b;

 if (cmmdc(a, b) == 1) g << 0;

 else g << cmmdc(a, b);



 f.close();

 g.close();

}
