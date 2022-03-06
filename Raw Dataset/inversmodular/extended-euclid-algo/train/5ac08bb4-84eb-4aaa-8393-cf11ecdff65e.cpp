#include <iostream>
#include <fstream>
using namespace std;

ifstream f ("inversmodular.in");

ofstream g ("inversmodular.out");

void euclid_extins(long long a,long long b,long long &x,long long &y)

{

    if (b == 0)

    {

        x = 1;

        y = 0;

        return;

    }

    long long fost_x,fost_y;

    euclid_extins(b,a%b,fost_x,fost_y);

    x = fost_y;

    y = fost_x + (-a/b)*fost_y;

    return;

}

int main()

{

    long long nr,mod,x,y;

    f >> nr>> mod;

    euclid_extins(nr,mod,x,y);

    long long invers_modular = (x + mod) % mod;

    g << invers_modular;





}
