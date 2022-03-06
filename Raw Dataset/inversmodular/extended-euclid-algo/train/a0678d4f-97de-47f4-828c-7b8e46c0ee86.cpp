#include<cstdio>
int n;
int mod(long long a, int m)
{
    return (a + m) % m;

}
void euclid_extins(int a, int b, int &d, long long &x, long long &y)
{
    if(b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    long long xprim = 0, yprim = 0, q = a / b;
    euclid_extins(b, a % b, d, xprim, yprim);
    x = yprim , n;
    y = xprim - 1LL * yprim * q , n;
}


int main()
{
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);
    int tests, a, b, c, d;
    long long rez1 , rez2;
    rez1 = rez2 = 0;
    scanf("%d%d", &a,&n);
    euclid_extins(a, n, d, rez1, rez2);
    printf("%d" , mod(rez1 , n));
return 0;
}
