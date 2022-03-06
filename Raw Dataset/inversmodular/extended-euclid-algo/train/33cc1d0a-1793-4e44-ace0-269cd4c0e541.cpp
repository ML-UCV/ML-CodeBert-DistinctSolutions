#include <iostream>
#include <fstream>

using namespace std;

void gcd(long long &x,long long &y,int a,int b){

    if(b==0){

        x=1;
        y=0;
        return;
    }
    gcd(x,y,b,a%b);
    long long aux = x;
    x = y;
    y = aux - y*(a/b);
}

int main()
{
    int a,n;
    long long inv = 0,ins;
    ifstream f("inversmodular.in");
    ofstream g("inversmodular.out");
    f>>a>>n;
    gcd(inv,ins,a,n);
    if(inv<=0)
        inv = n + inv%n;
    g<<inv;
    return 0;
}
