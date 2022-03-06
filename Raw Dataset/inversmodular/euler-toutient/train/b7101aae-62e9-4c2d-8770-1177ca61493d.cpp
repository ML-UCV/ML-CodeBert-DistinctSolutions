#include <fstream>


using namespace std;

ifstream cin ("inversmodular.in");

ofstream cout ("inversmodular.out");



long long mod;

long long ridput(long long b, long long e)

{

    long long r = 1;

    while (e)

    {

        if (e % 2)

            r = (r * b) % mod;

        b = (b * b) % mod;

        e /= 2;

    }

    return r;

}

long long phi(long long n)

{

    long long r = n, f = 2;

    while (f * f <= n && n != 1)

    {

        if (!(n % f))

        {

            r = r * (f - 1) / f;

            while (!(n % f))

                n /= f;

        }

        f++;

    }

    if (n != 1)

        r = r * (n - 1) / n;

    return r;

}

int main()

{

    long long a, b;

    cin >> a >> b;

    mod = b;

    cout << ridput(a, phi(b) - 1);

    return 0;

}
