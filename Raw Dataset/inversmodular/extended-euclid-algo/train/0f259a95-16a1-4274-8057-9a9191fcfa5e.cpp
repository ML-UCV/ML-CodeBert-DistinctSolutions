#include <cstdio>
#include <algorithm>


using namespace std;



int a, n;



pair <int, int> euclid(int a, int b)

{

    if(b == 0)

        return {1, 0};

    auto p=euclid(b, a%b);

    return {p.second, p.first-(a/b)*p.second};

}





int main()

{



    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);





    scanf("%d %d", &a, &n);

    auto invers=euclid(a, n);

    int inv=invers.first;

    while(inv<0)

        inv+=n;

    printf("%d", inv);

    return 0;

}
