#include <fstream>
using namespace std;



ifstream cin("cmmdc.in");

ofstream cout("cmmdc.out");



int main () {

  int a, b;

  cin >> a >> b;

  while (a != b) {

    if (a > b) a -= b;

    else if (a < b) b -= a;

  }

  if (a == 1) {

    cout << 0;

    return 0;

  }

  cout << a;

  return 0;

}
