#include <fstream>
using namespace std;

ifstream in("inversmodular.in");
ofstream out("inversmodular.out");

pair <int, int> euclid(int x, int y) {
    if (y == 0) return {1, 0};
    auto p = euclid(y, x % y);
    return {p.second, p.first - 1ll * (x / y) * p.second};
}

int main() {
    int a, n;

    in >> a >> n;

    auto q = euclid(a, n);
    while (q.first < 0)
        q.first += n;

    out << q.first;

    return 0;
}
