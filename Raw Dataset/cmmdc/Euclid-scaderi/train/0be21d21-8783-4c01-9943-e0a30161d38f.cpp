#include <iostream>
#include <fstream>


using namespace std;



ifstream in ("cmmdc.in");

ofstream out ("cmmdc.out");





int main()

{

    unsigned int a,b;

    in >> a >> b;

    while(a!=b){

    if(a > b){

        a = a - b;

    }

    else if(b > a){

        b = b - a;

    }

    }

    if(a == 1){

        out << 0;

    }

    else{

        out << a;

    }

}
