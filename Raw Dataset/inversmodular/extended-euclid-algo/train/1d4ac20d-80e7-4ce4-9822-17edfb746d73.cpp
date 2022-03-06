#include <cstdio>
#include <algorithm>


using namespace std;



pair<long long, long long> euclid(int x, int y)

{

    if(y==0)

        return {1, 0};

    auto p=euclid(y, x%y);

    return {p.second, p.first-(x/y)*p.second};

}



int x, n;



int main()

{

    freopen("inversmodular.in", "r", stdin);

    freopen("inversmodular.out", "w", stdout);

    scanf("%d %d", &x, &n);

    auto invers=euclid(x, n);

    int y=invers.first;

    while(y<0)

        y+=n;

    printf("%d", y);



    return 0;

}
