#include <cstdio>
#include <iostream>


using namespace std;



int a, n;



pair<int, int> eu_ex(int x, int y)

{

    if(y == 0)

        return {1, 0};

    auto p=eu_ex(y, x%y);

    return {p.second, p.first-(x/y)*p.second};

}



int main()

{

    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);



    scanf("%d %d", &a, &n);



    int inv=eu_ex(a, n).first;

    if(inv<0)

        inv+=n;

    printf("%d", inv);



    return 0;

}
