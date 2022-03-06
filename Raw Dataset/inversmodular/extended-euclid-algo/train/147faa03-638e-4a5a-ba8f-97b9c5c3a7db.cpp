#include <bits/stdc++.h>
using namespace std;
long long w, z;
int p, n;
void cmmdc(int a,int b,long long &x,long long &y)
{
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        long long x0, y0;
        cmmdc(b, a%b, x0, y0);
        x = y0;
        y = x0 - a/b*y0;
    }
}
int main() {
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);

    scanf("%d%d", &p, &n);
    cmmdc(p, n, w, z);

    if (w <= 0)
        w = n + w%n;

    printf("%lld", w);
    return 0;
}
