#include <iostream>
#include <fstream>


using namespace std;

ifstream f("inversmodular.in");
ofstream g("inversmodular.out");

int a,n,d,x,y;

void euclid(int a,int b,int& d,int& x,int& y){
    if(b==0){
        d=a;
        x=1;
        y=0;
        return;
    }else{
        int x0,y0;
        euclid(b,a%b,d,x0,y0);
        x=y0;
        y=x0-(a/b)*y0;
    }
}

int main(){
    f>>a>>n;
    euclid(a,n,d,x,y);
    while(x<0){
        x+=n;
    }
    x=x%n;
    g<<x;
    f.close();
    g.close();
}
