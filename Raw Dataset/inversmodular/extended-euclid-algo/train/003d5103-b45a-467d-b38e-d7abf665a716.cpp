#include <bits/stdc++.h>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



void exte(int a, int b, int& m, int& n){

    if(!b){

        m=1;

        n=0;

        return;

    }

    int M,N;

    exte(b,a%b,M,N);

    m=N;

    n=M-N*(a/b);



}



int main()

{

    int a,n,x,y;

    fin>>a>>n;

    exte(a,n,x,y);

    while(x<0)

        x+=n;

    fout<<x;

    return 0;

}
