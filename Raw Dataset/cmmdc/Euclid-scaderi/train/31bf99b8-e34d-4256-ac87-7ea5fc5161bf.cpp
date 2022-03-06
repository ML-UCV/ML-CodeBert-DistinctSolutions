#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int cmmdc(int n,int n2){

    while(n!=n2){

        if(n>n2){

            n=n-n2;

        }else{

            n2=n2-n;

        }

    }

    return n;

}
int main(){

    int n,n2;

    fin>>n>>n2;

    int sol=cmmdc(n,n2);

    if(sol==1){

        sol=0;

    }

    fout<<sol<<"\n";

    return 0;

}
