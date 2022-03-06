#include <bits/stdc++.h>

using namespace std;

ifstream in;
ofstream out;


void euclid(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        int x0, y0;
        euclid(b, a%b, x0, y0);
        x = y0;
        y = x0 - (a/b) * y0;
    }
}

int n,p;

int main() {

    in.open("inversmodular.in");
    out.open("inversmodular.out");

    in>>n>>p;
    int x,y;
    euclid(n, p, x , y);
    if(x>0)
        out<<x;
    else
        out<<p+x;

    return 0;
}
