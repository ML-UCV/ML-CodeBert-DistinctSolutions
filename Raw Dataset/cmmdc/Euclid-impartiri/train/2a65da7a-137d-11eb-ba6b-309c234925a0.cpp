#include <iostream>
#include <fstream>
using namespace std;



int GCD(int A, int B)

{

    if(!B)

        return A;

    return GCD(B, A%B);

}



int main()

{

    ifstream in("cmmdc.in");

    ofstream out("cmmdc.out");

    int a,b;

    in>>a>>b;

    if(GCD(a, b) == 1) out<<"0";

    else {

    while(a!=b){

        if(a>b) a-=b;

        else b-=a;

    }

    out<<a;}

    return 0;

}
