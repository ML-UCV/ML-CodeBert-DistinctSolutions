#include <iostream>
#include <fstream>


int main()

{

    std::ifstream fisier_in("cmmdc.in");

    std::ofstream fisier_out("cmmdc.out");

    long a,b, cmmdc;

    fisier_in>>a;

    fisier_in>>b;

    fisier_in.close();

    if(b > a)

    {

        while(a!=0)

        {

            int temp = a;

            a = b % a;

            b = temp;

        }

        if(b == 1) cmmdc = 0;

        else cmmdc = b;

    }

    else{

        while(b != 0){

            int temp = b;

            b = a % b;

            a = temp;

        }

        if(a == 1) cmmdc = 0;

        else cmmdc = a;

    }

    fisier_out<<cmmdc;

    fisier_out.close();

    return 0;

}
