#include <fstream>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



int a, b, c, x, y, k;



int euclid (int a, int b, int &x, int &y){

    int xa, ya, d;

    if (b == 0){

        y = 0, x = 1;

        return a;

    }

    else{

        d = euclid(b, a%b, xa, ya);

        x = ya;

        y = xa - a/b*ya;

        return d;

    }

}



int main(){

    fin>>a>>b;

    k = euclid(a, b, x, y);

    x%=b;

    if(x<0){

        x+=b;

    }

    fout<<x;

}
