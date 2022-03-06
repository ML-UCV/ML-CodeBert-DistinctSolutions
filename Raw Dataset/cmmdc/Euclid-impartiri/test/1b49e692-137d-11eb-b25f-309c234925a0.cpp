#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int cmmdc(int a, int b)

{

    int r = a % b;

    while (r != 0)

    {

        a = b;

        b = r;

        r = a % b;

    }

    return b;

}



int main()

{

    int a, b;

    fin >> a >> b;

    if (cmmdc(a,b) == 1)

        fout << '0';

    else

        fout << cmmdc(a, b);

    return 0;

}
