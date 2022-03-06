#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



void invrs(long long int &x, long long int &y, int a, int b){

    if(!b)

        x=1,y=0;

    else{

        invrs(x,y,b,a%b);

        swap(x,y);

        y=y-x*(a/b);

    }



}



int main(){

    long long int inv=0,ins;

    int a,b;

    f>>a>>b;

    invrs(inv,ins,a,b);



    if(inv<=0)

        inv = b+inv%b;



    g<<inv;



return 0;

}
