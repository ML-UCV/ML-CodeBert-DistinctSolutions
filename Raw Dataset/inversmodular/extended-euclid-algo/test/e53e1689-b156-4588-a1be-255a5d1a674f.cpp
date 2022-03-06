#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



void EuclidExtins(int a, int b, int d, int &x, int &y){

    if(b == 0){

        x = 1;

        y = 0;

        d = a;

    }

    else{

        int x0, y0;

        EuclidExtins(b, a%b, d, x0, y0);

        x = y0;

        y = x0 - y0 * (a/b);

    }

}



int main(){

    int A,N,d,x,y; f>>A>>N;

    EuclidExtins(A,N,d,x,y);

    while(x < 0) x += N;

    g<<x;

}
