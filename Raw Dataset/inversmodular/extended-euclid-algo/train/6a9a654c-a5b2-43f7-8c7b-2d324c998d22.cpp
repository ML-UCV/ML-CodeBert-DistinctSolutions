#include <fstream>
using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout("inversmodular.out");



int A,N,x,y;



void cmmdc(int a, int b, int &x, int &y) {

 if (b==0){

  x=1;

  y=0;

 }

 else{

  int x0,y0;

  cmmdc(b,a%b,x0,y0);

  x=y0;

  y=x0-(a/b)*y0;

 }

}



int main() {

 fin>>A>>N;

    cmmdc(A,N,x,y);

    x%=N;

    if (x<0)

        x+=N;

    fout<<x;

 fin.close();

 fout.close();

 return 0;

}
