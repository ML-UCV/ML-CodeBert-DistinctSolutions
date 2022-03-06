#include <fstream>



using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



int a, n;



int exp(int N, int p) {

 int r = 1;

 while (p) {

  if (p % 2 == 1)r = (1LL * N * r) % n;

  N =(1LL * N * N) % n;

  p /= 2;

 }

 return r;

}



int phi(int n) {

    int result = n;



    for (int p = 2; p * p <= n; ++p) {





        if (n % p == 0) {

            while (n % p == 0)

                n /= p;

            result -= result / p;

        }

    }

    if (n > 1)

        result -= result / n;

    return result;

}



int main() {

 ios_base::sync_with_stdio(false);

 in.tie(NULL), out.tie(NULL);

 in >> a >> n;

 out << exp(a, phi(n) - 1) % n;



}
