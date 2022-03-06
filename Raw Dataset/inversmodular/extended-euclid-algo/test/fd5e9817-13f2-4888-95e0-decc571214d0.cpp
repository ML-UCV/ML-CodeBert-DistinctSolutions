#include <cstdio>
#include <algorithm>
using namespace std;



pair <int, int> euclid(int x, int y){

    if(y==0)

        return {1, 0};

    auto p=euclid(y,x%y);

    return {p.second, p.first - (x/y)*p.second };

}

int a, n, x, y;

int main()

{

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    scanf("%d %d", &a, &n);

    auto Q=euclid(a,n);

    while(Q.first<0)

        Q.first+=n;

    printf("%d",Q.first);

    return 0;

}
