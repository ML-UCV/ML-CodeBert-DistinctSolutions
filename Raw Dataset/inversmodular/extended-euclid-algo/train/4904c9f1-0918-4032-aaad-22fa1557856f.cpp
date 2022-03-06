#include <fstream>




using namespace std;



ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");



int a,n;



void invmod(long long &x,long long &y,int a,int b){

    if (!b){

        x=1; y=0;

    }

    else{

        invmod(x,y,b,a%b);

        long long aux=x;

        x=y;

        y=aux-(a/b)*y;

    }



}



int main()

{

    ios_base::sync_with_stdio(false);;

    cin.tie(0);

    cout.tie(0);

    long long invm,aj;

    cin>>a>>n;

    invmod (invm,aj,a,n);

    if (invm<0) invm=n+invm%n;

    cout<<invm;

    return 0;

}
