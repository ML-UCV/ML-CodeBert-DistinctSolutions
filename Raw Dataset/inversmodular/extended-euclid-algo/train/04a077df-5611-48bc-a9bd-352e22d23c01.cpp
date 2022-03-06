#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long inv_mod(long long a, long long b, long long &x, long long &y){

    if (b==0){

        x=1;

        y=0;

        return a;

    }

    long long val = inv_mod(b,a%b,x,y);

    long long aux=x;

    x=y;

    y=aux-y*(a/b);

}

long long a,n,x,y;

int main()

{

    fin >> a >> n;

    inv_mod(a,n,x,y);

    fout << (x+n)%n;

    return 0;

}
