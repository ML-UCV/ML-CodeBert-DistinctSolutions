#include <iostream>
#include<fstream>
using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int cmmdc(int a, int b)

{

    if(a==0)

        return b;

    return cmmdc(b%a,a);

}



int main()

{



    int a,b;

    fin>>a>>b;

    if(cmmdc(a,b)==1){

        fout<<0;

    }else{

    fout<<cmmdc(a,b);

    }

    fin.close();

    fout.close();

    return 0;

}
