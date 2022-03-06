#include <iostream>
#include <fstream>
using namespace std;

int a,b,cmmdc;



int CMMDC(int a, int b){



    while(a!=b){

      if(a>b){

        a=a-b;

      }

      if(b>a){

        b=b-a;

      }

    }

    if(a == 1 ){

        return 0;

    }else{

        return a;

    }

}



int main()

{

    ifstream f("cmmdc.in");

    ofstream g("cmmdc.out");

    f>>a>>b;

    g<<CMMDC(a,b);



    return 0;

}
