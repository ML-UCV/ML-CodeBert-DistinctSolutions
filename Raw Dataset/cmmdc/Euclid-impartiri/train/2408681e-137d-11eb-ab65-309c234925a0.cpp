#include <cstdio>


int cmmdc(int a, int b) {

    if(b == 0)

        return a;

    return cmmdc(b, a % b);

}



int main() {

    int a, b;

    freopen("cmmdc.in", "r", stdin);

    freopen("cmmdc.out", "w", stdout);

    scanf("%d%d", &a, &b);

    if(cmmdc(a, b) > 1)

        printf("%d", cmmdc(a, b));

    else

        printf("0");

}
