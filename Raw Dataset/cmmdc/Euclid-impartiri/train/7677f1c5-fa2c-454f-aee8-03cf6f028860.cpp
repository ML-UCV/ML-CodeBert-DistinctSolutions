#include <iostream>
#include <fstream>


using namespace std;



ifstream in("cmmdc.in");

ofstream out("cmmdc.out");



int cmmdc(int a, int b)

{

    int aux;

    while(b)

    {

        aux=b;

        b=a%b;

        a=aux;

    }

    if(a==1) return 0;

    return a;

}



int main()

{

    int a, b;

    in>>a>>b;

    out<<cmmdc(a, b);

    return 0;

}
