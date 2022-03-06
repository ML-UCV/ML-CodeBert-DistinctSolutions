#include <cstdio>
#include <iostream>

using namespace std;

pair<long long, long long> euclid_extins(int a, int b) {
    if (!b)
        return {1, 0};
    pair<long long, long long> rez = euclid_extins(b, a % b);
    return {rez.second, rez.first - (a / b) * rez.second};
}

int main() {
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);
    int a, n;
    scanf("%d %d", &a, &n);
    int rez = euclid_extins(a, n).first % n;
    while (rez < 0)
        rez += n;
    printf("%d", rez);
    return 0;
}
