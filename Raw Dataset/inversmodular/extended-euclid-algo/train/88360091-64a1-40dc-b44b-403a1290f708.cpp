#include <iostream>
#include <fstream>

using namespace std;

ifstream in("inversmodular.in");
ofstream out("inversmodular.out");

typedef long long ll;

int a, mod;

void inv_mod(ll &inv, ll &ins, int a, int b) {
  if(b == 0) {
    inv = 1;
    ins = 0;
  } else {
    inv_mod(inv, ins, b, a % b);
    swap(inv, ins);
    ins -= inv * (a / b);
  }
}

int main()
{
  in >> a >> mod;

  ll inv = 0, ins;
  inv_mod(inv, ins, a, mod);

  if(inv <= 0)
    inv = (inv + mod) % mod;

  out << inv << '\n';

  in.close();
  out.close();
  return 0;
}
