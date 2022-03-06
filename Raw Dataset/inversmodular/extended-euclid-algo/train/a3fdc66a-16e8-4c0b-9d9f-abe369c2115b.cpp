#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long n,m,x,y;

long long euclid(long long a, long long b, long long &x, long long &y){

    if(b==0){

        x=1;

        y=0;

        return a;

    }

    long long x1,y1;

    long long d=euclid(b,a%b,x1,y1);

    x=y1;

    y=x1-(a/b)*y1;

    return d;

}

int main(){

    fin>>n>>m;

    euclid(n,m,x,y);

    x%=m;

    if(x<0)

        x+=m;

    fout<<x;

    return 0;

}
