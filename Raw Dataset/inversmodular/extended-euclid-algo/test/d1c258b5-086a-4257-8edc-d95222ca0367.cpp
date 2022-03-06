#include <iostream>
#include <cstdio>

using namespace std;

pair<long long, long long> euclidex(int a, int b){
    if(b==0)
        return {1ll,0};
    auto p = euclidex(b,a%b);
    return {p.second, p.first-(a/b)*p.second};
}

int main()
{
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);

    int a,n;
    scanf("%d%d", &a, &n);
    auto p = euclidex(n,a);

    while(p.second < 0)
        p.second += n;

    cout<<p.second;

    return 0;
}
