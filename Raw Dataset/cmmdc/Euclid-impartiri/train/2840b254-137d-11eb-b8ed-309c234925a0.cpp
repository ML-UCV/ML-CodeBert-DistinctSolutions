#include <fstream>


using namespace std;



ifstream in("cmmdc.in");

ofstream out("cmmdc.out");



int a, b;



int cmmdc(int a, int b) {

 if (b == 0) return a;

 return cmmdc(b, a % b);

}



int main() {

 in >> a >> b;

 int ans = (cmmdc(a, b) == 1) ? 0 : cmmdc(a, b);

 out << ans;

 return 0;

}
