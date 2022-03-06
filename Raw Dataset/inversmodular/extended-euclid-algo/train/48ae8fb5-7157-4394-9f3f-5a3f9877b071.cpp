#include <fstream>
#include <iostream>

using namespace std;

template <class T>
pair<T, T> gcd_ext(T a, T b, T c) {
 if (b == 0) {
  if (c % a == 0)
   return make_pair(c/a, 0);
  else
   return make_pair(0, 0);
 }

 auto p = gcd_ext(b, a % b, c);
 return make_pair(p.second, p.first - (a/b) * p.second);
}

int main(int argc, char const *argv[])
{
 ifstream fin("inversmodular.in");
 ofstream fout("inversmodular.out");

 long int A, N; fin >> A >> N;

 auto p = gcd_ext<long int>(A, N, 1);
 long int x = p.first;
 x %= N;
 if (x < 0) x += N;

 fout << x << endl;

 return 0;
}
