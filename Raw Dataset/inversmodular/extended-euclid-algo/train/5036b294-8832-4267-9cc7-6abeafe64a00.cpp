#include<iostream>
#include<fstream>


using namespace std;



int a,n;



void euclid_extins(long long &x,long long &y,int a,int b)

{

    if(!b)

        x = 1,y = 0;

    else

    {

        euclid_extins( x, y, b, a%b);

        long long aux = x;

        x = y;

        y = aux - y *(a / b);

    }

}

int main()

{

    ifstream cin("inversmodular.in");

    ofstream cout("inversmodular.out");

    long long inv = 0,ins;

    cin>>a>>n;

    euclid_extins(inv,ins,a,n);

    if(inv <= 0)

        inv = n +inv % n;

    cout<<inv;

    return 0;

}
