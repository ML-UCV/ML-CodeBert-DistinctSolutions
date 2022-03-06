#include <iostream>
#include <fstream>


using namespace std;

ifstream i("cmmdc.in");

ofstream o("cmmdc.out");



int main()

{

    int a, b;

    i>> a >> b;

    while(b > 0)

    {

        int rest = a%b;

        a = b;

        b = rest;



    }

    if (a==1)

    {

        o<< 0;

    } else

    {

        o<< a;

    }

    return 0;

}
