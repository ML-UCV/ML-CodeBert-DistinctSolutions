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

    auto p=euclid(a,n);

    while(p.first<0)

        p.first+=n;

    printf("%d",p.first);

    return 0;

}
