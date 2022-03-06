#include <fstream>




using ll = long long;

std::ifstream fin("inversmodular.in");
std::ofstream fout("inversmodular.out");

int a, n;

void ecl(ll &x, ll &y, int a, int b) {
  if (!b) {
    x = 1, y = 0;
  } else {
    ecl(x, y, b, a % b);
    ll aux = x;
    x = y;
    y = aux - y * (a / b);
  }
}

int main() {
  ll inv = 0, ins;
  fin >> a >> n;
  ecl(inv, ins, a, n);
  if (inv <= 0) {
    inv = n + inv % n;
  }
  fout << inv;
  return 0;
}
