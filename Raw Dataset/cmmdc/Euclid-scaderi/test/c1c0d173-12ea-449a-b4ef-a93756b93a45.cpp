#include <fstream>


using namespace std;

ifstream cin("cmmdc.in");

ofstream cout("cmmdc.out");



int cmmdc(int a, int b)

{

    while(a!=b)

    {

        if (a>b)

            a-=b;

        else

            b-=a;

    }

    if (a==1 && b==1)

        return 0;

    return a;

}

int main()

{

    int a, b;

    cin >> a >> b;

    cout << cmmdc(a,b);

    return 0;

}
