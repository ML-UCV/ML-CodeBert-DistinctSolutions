#include <fstream>


using namespace std;



ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");



int a, n;



void citire()

{

    cin >> a >> n;

}



void invers(long long &x, long long &y, int a, int b)

{

    if(!b)

        x = 1, y = 0;

    else

    {

        invers(x, y, b, a % b);

        long long aux = x;

        x = y;

        y = aux - y * (a / b);

    }

}



void print(long long x)

{

    if (x <= 0)

       x = n + x % n;

    cout << x;

}



int main()

{

    long long x = 0, y;

    citire();

    invers(x,y,a,n);

    print(x);

    return 0;

}
