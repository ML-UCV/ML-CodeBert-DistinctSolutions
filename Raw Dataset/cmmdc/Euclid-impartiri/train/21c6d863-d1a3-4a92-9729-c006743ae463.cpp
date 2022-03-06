#include <iostream>
#include <fstream>
using namespace std;



ifstream in("cmmdc.in");

ofstream out ("cmmdc.out");



long long cmmdc(long long a, long long b){

    if(b==0) return a;

    else cmmdc(b,a%b);

}



int main()

{

    long long a,b;

    in>>a>>b;

    if(cmmdc(a,b)==1) out<<0;

    else out<<cmmdc(a,b);

}
