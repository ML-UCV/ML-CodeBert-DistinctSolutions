#include <iostream>
#include <fstream>


using namespace std;

ifstream f ("cmmdc.in");

ofstream g ("cmmdc.out");



unsigned long int cmmdc (unsigned long int a , unsigned long int b)

{

    while(a!=b)

        if(a>b)

            a=a-b;

       else

        b=b-a;

    if(a==1)

        return 0;

    return a;

}



unsigned int a,b ;

int main()

{

    f>>a>>b;

    g<<cmmdc(a,b);



    return 0;

}
