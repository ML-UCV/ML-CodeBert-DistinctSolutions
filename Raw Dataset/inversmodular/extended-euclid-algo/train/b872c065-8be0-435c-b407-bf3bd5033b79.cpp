#include <fstream>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



void EuclidE(int a,int b,int &x,int &y,int &d)

{

    if(b==0){x=1;y=0;d=a;}

    else{int x0,y0;

         EuclidE(b,a%b,x0,y0,d);

         x=y0; y=x0-a/b*y0;

        }

}



int a,b,c,d,x,y,t,k,n;

int main()

{

    fin>>a>>n;

    EuclidE(n,a,x,y,d);

    while(y<1)y+=n;

    fout<<y;



    fin.close(); fout.close();

    return 0;

}
