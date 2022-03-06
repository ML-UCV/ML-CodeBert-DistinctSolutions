#include <fstream>


std::ifstream cin("cmmdc.in");

std::ofstream cout("cmmdc.out");



long long cmmdc(long long a, long long b){

    if(b == 0)

        return a;

    return cmmdc(b, a % b);

}



int main()

{

    long long a{}, b{};

    cin >> a >> b;

    long long c = cmmdc(a, b);

    if(c == 1)

        cout << 0;

    else cout << c;

}
