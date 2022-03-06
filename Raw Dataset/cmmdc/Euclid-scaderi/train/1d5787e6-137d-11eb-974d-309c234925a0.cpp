#include <fstream>
std::ifstream in ("cmmdc.in"); std::ofstream out ("cmmdc.out");



int main (){

    std::ios::sync_with_stdio(false);

    int a,b;

    in>>a>>b;

    while(a!=b){

        if(a>b) a=a-b;

        else b=b-a;

    }

    if(a==1) out<<0;

    else out<<a;

}
