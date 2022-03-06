#include <bits/stdc++.h>
using namespace std;

ifstream f ("inversmodular.in");

ofstream g ("inversmodular.out");

void euclid(int a , int b ,int & x ,int & y)

{

    if(b == 0)

    {

        x = 1, y = 1;

    }

    else

    {

        int x1 , y1;

        euclid(b , a % b , x1 , y1);

        x = y1;

        y = x1 - a / b * y1;

    }

}



int main()

{

    int A,N;

    f>>A>>N;

    int X , Y;

    euclid(A, N , X ,Y);

    while(X < 0)

        X += N;

    g << X;

    return 0;

}
