#include <bits/stdc++.h>
using namespace std;
int n;
long long indicator, invers, a;
void desc(int nr)
{
    indicator = nr;
    for (int i=2;i*i<=nr;i++){
        if (nr%i==0){
            while(nr%i==0){
                nr/=i;
            }
            indicator /= i;
            indicator *= i-1;
        }
    }
    if (nr>1){
        indicator /= nr;
        indicator *= nr-1;
    }
}
long long euler()
{
    long long inv = 1;
    indicator--;
    while(indicator > 0){
        if (indicator%2==1){
            inv = (inv * a)%n;
        }
        a = (a * a)%n;
        indicator /=2;
    }
    return inv;
}
int main() {
    freopen("inversmodular.in", "r", stdin);
    freopen("inversmodular.out", "w", stdout);

    scanf("%lld%d", &a, &n);
    desc(n);
    invers = euler();
    printf("%lld", invers%n);
    return 0;
}
