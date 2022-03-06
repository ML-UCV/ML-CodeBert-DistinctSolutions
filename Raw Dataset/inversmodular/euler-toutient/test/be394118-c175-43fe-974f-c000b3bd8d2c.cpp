#include<cstdio>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>


using namespace std;


using namespace std;

class InvMod {
private:

    int A, N;
    long long p[25];

    long long phi(int x) {
        int c=x;
        long long d=x;
        for (int i = 2; i * i <= c; i++)
            if (x % i == 0) {
                while(c%i==0)c/=i;
                d=(d/i)*(i-1);
            }
        if (c != 1) d = d / c * (c - 1);
        return d;
    }

    void lgpowx(long long px) {
        long long q = log2(px) + 1;

        p[0] = A;
        for (int i = 1; i <= q; i++)
            p[i] = (p[i - 1] * p[i - 1]) % N;
    }

    long long lgpow(int n, long long px) {
        long long ans = 1;
        int k = 0;
        lgpowx(px);
        while (px) {
            if (px & 1)
                ans = ans * p[k] % N;
            ++k;
            px = px >> 1;
        }
        return ans;
    }


public:
    void invMod_main() {
        freopen("inversmodular.in", "r", stdin);
        freopen("inversmodular.out", "w", stdout);

        scanf("%d %d", &A, &N);

        printf("%lld", lgpow(A, phi(N) - 1));

    }


} invMod;

int main() {
    invMod.invMod_main();
    return 0;
}
