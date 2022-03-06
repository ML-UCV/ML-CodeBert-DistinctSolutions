#include<fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long a,b,x,y;



long long euclid(long long a,long long b,long long &x,long long &y){

    if(b==0){

        x=1;

        y=0;

        return a;

    }

    else{

        long long X,Y,r=euclid(b,a%b,X,Y);

        x=Y;

        y=X-Y*(a/b);

        return r;

    }

}



int main() {

    fin>>a>>b;

    euclid(a,b,x,y);

    fout<<(b+x%b)%b;

    return 0;

}
