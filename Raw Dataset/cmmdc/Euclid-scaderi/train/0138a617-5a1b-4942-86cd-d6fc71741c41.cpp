#include <iostream>
#include <fstream>


using namespace std;

int main() {

    fstream citirein("cmmdc.in",ios::in);

    ofstream output("cmmdc.out",ios::out);

    int a,b;

    citirein>>a>>b;

    citirein.close();

    while(a!=b)

    {

        if(a>b)

        a=a-b;

        else

        b=b-a;

    }

    if(a==1)

    a=0;

    output<<a;

    output.close();

    return 0;

}
