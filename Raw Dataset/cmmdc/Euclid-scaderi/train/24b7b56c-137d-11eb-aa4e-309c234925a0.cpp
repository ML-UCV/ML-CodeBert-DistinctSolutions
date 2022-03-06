#include <iostream>
#include <fstream>


using namespace std;



int main()

{ double a,b;



    std::ifstream file1;

    std::ofstream file2;

    file1.open("cmmdc.in");

    file1>>a;

    file1>>b;



    while(a!=b)

    {

        if(a>b)

            a=a-b;

        else

            b=b-a;

    }







    file2.open("cmmdc.out");

    if (a==1)

        file2<<0;

    else

        file2<<a;



    return 0;



}
