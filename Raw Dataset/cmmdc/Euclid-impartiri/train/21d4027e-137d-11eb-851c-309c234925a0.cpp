#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    if (!b)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    freopen("cmmdc.in","r",stdin);
    freopen("cmmdc.out","w",stdout);
    int a,b;
    cin >> a >> b;
    if (cmmdc(a,b)==1)
        cout << "0";
        else cout << cmmdc(a,b);
    return 0;
}
