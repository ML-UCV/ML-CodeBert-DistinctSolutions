#include <fstream>




using namespace std;



int CMMDC(int a, int b) {

    if (b == 0) {

        if (a == 1)

            return 0;

        return a;

    }

    return CMMDC(b, a % b);

}



int main(void) {

    ifstream in;

    ofstream out;

    in.open ("cmmdc.in");

    out.open ("cmmdc.out");

    in.is_open();

    int a, b;

    in>>a>>b;

    out<<CMMDC(a,b)<<"\n";

    in.close();

    out.close();

    return 0;



}
