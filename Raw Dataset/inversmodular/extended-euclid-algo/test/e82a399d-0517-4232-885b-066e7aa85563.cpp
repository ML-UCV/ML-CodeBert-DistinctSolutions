#include <bits/stdc++.h>
using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout("inversmodular.out");

void euclidex(int a, int b,int &x, int &y){

    if(b==0){

        y=0;

        x=1;

    }

    else{

        int xx,yy;

        euclidex(b,a%b,xx,yy);

        x=yy;

        y=xx-(a/b)*yy;

    }

}

int a,b,x,y;

int main(){

    fin>>a>>b;

    euclidex(b,a,x,y);

    while(y<0)

        y+=b;



    fout<<y;

    return 0;

}
