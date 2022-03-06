#include <iostream>
#include <fstream>


using namespace std;



int main()

{

    fstream fin("cmmdc.in", ios::in);

    fstream fout("cmmdc.out", ios::out);

    int a, b, rest;

    fin >> a;

    fin >> b;

    while (b > 0)

    {

        rest = a % b;

        a = b;

        if (rest==0)

            if (b == 1)

                fout << 0;

            else

                fout << b;

        b = rest;

    }

    return 0;

}
