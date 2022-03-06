#include <iostream>
#include <fstream>
using namespace std;



int main()

{

    ifstream xin("cmmdc.in");

    ofstream xout("cmmdc.out");

    int a,b,rest;

    xin>>a>>b;

    while(b){

        rest=a%b;

        a=b;

        b=rest;

    }

    if(a==1){

        xout<<0;

    }else{

     xout<<a;

    }



    return 0;

}
