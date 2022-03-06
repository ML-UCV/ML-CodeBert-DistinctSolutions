#include <fstream>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int a,b,c,n,t,x,y,d;

int euextins(int a, int b, int &x, int &y) {

    if (b == 0) {

        x = 1;

        y = 0;

        return a;

    }

    else {

        int xa, ya;

        int r = euextins(b, a%b, xa, ya);

        x = ya;

        y = xa - ya*(a/b);

        return r;



    }



}



int main() {

    fin>>a>>n;

    c=euextins(a,n,x,y);

    x%=n;

    if(x<0){

        x+=n;



    }





    fout<<x;
    return 0;



}
