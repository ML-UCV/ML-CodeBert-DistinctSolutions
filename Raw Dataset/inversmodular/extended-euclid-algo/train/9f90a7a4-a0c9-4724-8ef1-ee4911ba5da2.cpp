#include <fstream>

using namespace std;

ifstream f("inversmodular.in");
ofstream g("inversmodular.out");

long long a, MOD;

pair<long, long> cmmdc(long a, long b)
{
    if(b == 0)
        return {1, 0};
    auto p = cmmdc(b, a%b);
    return {p.second, (p.first - ((a/b) * p.second)%MOD + MOD)%MOD};
}

int main() {
    f>>a>>MOD;
    auto p = cmmdc(a, MOD);
    g<<p.first;
    return 0;
}
