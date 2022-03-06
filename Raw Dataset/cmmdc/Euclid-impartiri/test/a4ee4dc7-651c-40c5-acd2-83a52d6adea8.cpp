#include<fstream>
using namespace std;



ifstream cin ("cmmdc.in");

ofstream cout("cmmdc.out");



int cmmdc(int a, int b)

{

    if (b == 0)

        return a;

    else

        return cmmdc(b, a%b);

}



int main()

{

    int a, b;

    cin >> a >> b;

    if (cmmdc(a, b) == 1)

        cout << "0";

    else

        cout << cmmdc(a, b);



}
