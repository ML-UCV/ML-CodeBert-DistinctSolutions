#include <iostream>
#include <fstream>


using namespace std;



int main()

{

    ifstream in("cmmdc.in");

    ofstream out("cmmdc.out");



    int a,b,r;

    in >> a >> b ;

    while(b!=0)

    {

        r=a%b;

        a=b;

        b=r;

    }

    if(a>1) out << a ;

    else out << 0 ;

    in.close();

    out.close();

    return 0;

}
