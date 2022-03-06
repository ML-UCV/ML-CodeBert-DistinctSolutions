#include <fstream>


using namespace std;



ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");



int cmmdc(int x,int y){

    if(x<y){

        int aux=x;

        x=y;

        y=aux;

    }

    while(y!=0){

        int aux=x%y;

        x=y;

        y=aux;

    }

    return x;

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
