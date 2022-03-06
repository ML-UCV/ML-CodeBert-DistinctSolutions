#include <fstream>


using namespace std;



ifstream in("cmmdc.in");

ofstream out("cmmdc.out");





int main(){

    long long a,b;

    in >> a >> b;

    while (b != 0)

    {

        int rest = a % b;

        a = b;

        b = rest;

    }

    if(a==1)

        out << 0;

    else

        out << a;

    return 0;

}
