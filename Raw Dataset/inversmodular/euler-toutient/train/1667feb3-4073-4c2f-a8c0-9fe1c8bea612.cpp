#include <fstream>


int n, m;



int prod(int a, int b) { return (1ll * a * b) % m; }



int putlog(int n, int k) {

    if (k == 0) return 1;

    int x = putlog(n, k / 2);

    if (k % 2 == 0) return prod(x, x);

    return prod(prod(x, x), n);

}



int phi(int x) {

    int ph = x;

    for(int i=2;i*i<=x;i++)

        if (!(x % i)) {

            while (!(x % i)) x /= i;

            ph = ph / i * (i - 1);

        }

    if (x - 1) ph = ph / x * (x - 1);

    return ph;

}



int main() {

    std::ifstream fin("inversmodular.in");

    std::ofstream fout("inversmodular.out");

    fin >> n >> m;

    fout << putlog(n, phi(m) - 1);

}
