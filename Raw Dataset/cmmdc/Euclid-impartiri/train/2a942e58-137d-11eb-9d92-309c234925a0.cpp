#include <fstream>


using namespace std;

ifstream cin ("cmmdc.in");

ofstream cout ("cmmdc.out");

int a, b, r;

int main()

{

    cin >> a >> b;

    while (b!=0)

    {

        r=a%b;

        a=b;

        b=r;

    }

    if (a==1)

    {

        cout << 0;

    }

    else

    {

        cout << a;

    }

    return 0;

}
