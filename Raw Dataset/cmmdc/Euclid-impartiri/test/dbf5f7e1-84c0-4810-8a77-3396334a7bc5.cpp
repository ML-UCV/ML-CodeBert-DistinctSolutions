#include <fstream>

using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

int main()
{
    int a , b ;
    fin >> a >> b ;
    while ( b != 0 )
    {
        int rest = a % b ;
        a = b ;
        b = rest ;
    }
    if ( a == 1 ) fout << "0" ;
    else fout << a ;
    return 0;
}
