#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int main()

{ long long a, b, r=0;

    fin >> a >> b;



    while(b)

    { r = a%b;

      a = b;

      b = r;



    }



    if( a == 1 )

       fout << 0;

    else

       fout << a;

    return 0;

}
