#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int main()

{

    int a,b,c;

    int o = 0;

    f>>a>>b;

    if(a>b){

        c=a;

        a=b;

        b=c;

    }

    for(int i=1; i<=a ; i++){

        if(a%i==0 && b%i==0 ){

            o=i;

        }

    }

    if(o==1){

        o=0;

    }

    g<<o;

    return 0;

}
