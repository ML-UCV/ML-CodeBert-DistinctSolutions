#include <iostream>
#include <fstream>

using namespace std;

int buildPhi(int n) {
    int answer = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            answer = answer / i * (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        answer = answer / n * (n - 1);
    }
    return answer;
}

int power(int a, int b, int MOD) {
    if (b == 0) return 1;
    if (b % 2 == 0) return power(static_cast<int>(1LL * a * a % MOD), b / 2, MOD);
    return static_cast<int>(1LL * a * power(a, b - 1, MOD) % MOD);
}

int main() {
    ifstream f("inversmodular.in");
    ofstream g("inversmodular.out");
    int n, MOD;
    f >> n >> MOD;
    g << power(n, buildPhi(MOD) - 1, MOD);
    return 0;
}
