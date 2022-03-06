#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void Euclid(int a,int b, int &d,int &x,int &y)

{

    if(b==0) {d=a,x=1,y=0;}

    else {

        int x0,y0;

        Euclid(b,a%b,d,x0,y0);

        x=y0;

        y=x0-(a/b)*y0;

    }

}



int InversModular(int A,int N)

{

    int d,x,y;

    Euclid(A,N,d,x,y);

    if(x<0) x+=N;

    return x;

}



int main()

{

    int A,N;

    fin>>A>>N;

    fout<<InversModular(A,N);

    fin.close();

    fout.close();

    return 0;

}
