#include <fstream>
using namespace std;

int a, b;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int main()

{

 f >> a >> b;

 while (b) { int r = a % b; a = b; b = r; }

 if (a == 1) g << 0;

 else g << a;

 f.close(); g.close();

}
