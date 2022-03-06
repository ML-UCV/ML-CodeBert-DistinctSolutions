#include<fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

void invmod(long long &x,long long &y,int a,int b){

    if(b==0)

        x=1,y=0;

    else{

        invmod(x,y,b,a%b);

        long long c=x;

        x=y;

        y=c-y*(a/b);

    }

}

int main(){

    long long a,b,x=0,y=0;

    fin>>a>>b;

    invmod(x,y,a,b);

    if(x<=0){

        x=b+x%b;

    }

    fout<<x;



}
