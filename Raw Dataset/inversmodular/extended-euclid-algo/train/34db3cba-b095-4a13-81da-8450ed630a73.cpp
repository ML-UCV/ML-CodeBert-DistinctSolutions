#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");
typedef long long ll;
void euclid (ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        euclid(b, a%b, x, y);
        ll aux=x;
        x=y;
        y=aux-(a/b)*y;
    }
}
int main()
{
    int A, N;
    fin>>A>>N;
    ll sol1{}, sol2{};

    euclid(A, N, sol1, sol2);

    if(sol1<=0)
        sol1 = N + sol1%N;

    fout<<sol1;
    return 0;
}
