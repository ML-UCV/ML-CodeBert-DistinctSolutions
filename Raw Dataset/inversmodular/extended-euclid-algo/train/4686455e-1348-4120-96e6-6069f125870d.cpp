#include <bits/stdc++.h>



using namespace std;

void cmmdc(long long &x, long long &y, int a, int b)
{
    if (!b)
    {
        x = 1;
        y = 0;
    }
    else
    {
        cmmdc(x, y, b, a % b);
        long long aux = x;
        x = y;
        y = aux - y * (a / b);
    }
}

int a, n, x, y;
long long inv, ins;
int main()
{
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);

    scanf("%d %d", &a, &n);
    cmmdc(inv, ins, a, n);

    if (inv <= 0)
    {
        inv = n + inv % n;
    }

    printf("%d", inv);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
