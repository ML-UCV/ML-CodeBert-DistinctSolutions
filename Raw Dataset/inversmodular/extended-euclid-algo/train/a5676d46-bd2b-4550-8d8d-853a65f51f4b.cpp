#include <fstream>
#include <bitset>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long a, b, c, d, x, y,t;

long long euclid(long long a, long long b, long long &x, long long &y)

{

    if(b==0)

    {

        x=1,y=0;

        return a;

    }

    long long d,xa,ya;

    d=euclid(b, a%b, xa, ya);

    x=ya,y=xa-a/b*ya;

    return d;

}





int main()

{

    fin>>a>>b;

    d=euclid(a, b, x, y);

    if(x<=0) x+=b;

    fout<<x;

    return 0;

}
