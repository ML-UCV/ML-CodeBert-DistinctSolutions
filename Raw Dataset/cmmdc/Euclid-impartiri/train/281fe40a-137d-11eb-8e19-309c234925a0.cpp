#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main()

{

    long long a, b, r;

    fin >> a >> b;

    while(b != 0)

    {

        r = a % b;

        a = b;

        b = r;

    }

    if(a == 1) fout << 0;

    else fout << a;

}
