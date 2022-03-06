#include <iostream>
#include <fstream>
using namespace std;



int cmmdc ( int a , int b)

{

    while(a!=b)

    {

        if(a > b)

            a-=b;

        else

            b-=a;

    }

    if(a != 1)

        return a;

    else

        return 0;

}



int main()

{

    fstream cit ("cmmdc.in");

    ofstream afis ("cmmdc.out");



    int a, b;



    cit >> a >> b;



    afis<<cmmdc(a,b);



    return 0;

}
