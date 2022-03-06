#include <fstream>
#include <iostream>
using namespace std;





int main()

{

    ifstream fin("cmmdc.in", ios::in);

    ofstream fout("cmmdc.out", ios::out);

    long a, b,r;

    fin >> a >> b;

    r = a % b;

    while (r != 0)

    {



        a = b;

        b = r;

        r = a % b;

    }

    if (b == 1)

        b = 0;

    fout << b;

}
