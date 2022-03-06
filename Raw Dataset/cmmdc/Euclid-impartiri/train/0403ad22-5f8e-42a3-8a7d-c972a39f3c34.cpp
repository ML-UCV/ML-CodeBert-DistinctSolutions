#include <fstream>
using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main() {

    int a, b;

    fin >> a >> b;

    int r;

    while(a % b) {

        r = a % b;

        a = b;

        b = r;

    }

    if(b > 1)

        fout << b;

    else

        fout << 0;



    fin.close();

    fout.close();

    return 0;

}
