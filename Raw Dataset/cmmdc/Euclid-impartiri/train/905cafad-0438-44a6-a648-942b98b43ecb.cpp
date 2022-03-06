#include <fstream>


using namespace std;

ifstream cin("cmmdc.in");

ofstream cout("cmmdc.out");



int main()

{

    unsigned long long a, b, r;

    cin >> a;

    cin >> b;

    while(b)

    {

        r = a % b;

        a = b;

        b = r;

    }

    if(a!=1)cout << a;

    else cout<<0;

    return 0;

}
