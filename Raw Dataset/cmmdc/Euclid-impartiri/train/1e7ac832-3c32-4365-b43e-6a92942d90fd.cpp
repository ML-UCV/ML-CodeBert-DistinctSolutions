#include <fstream>


using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int cmmdc(int a, int b)

{

    if(b==0)

        return a;

    if(b==1)

        return 0;

    return cmmdc(b,a%b);

}



int main()

{

    int a,b;

    f>>a>>b;

    g<<cmmdc(a,b);

}
