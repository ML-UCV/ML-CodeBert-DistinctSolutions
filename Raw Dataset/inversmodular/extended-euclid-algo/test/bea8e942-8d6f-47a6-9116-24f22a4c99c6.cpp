#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int n, a, inv, y;



void euclid_extins(int a, int b, int &x, int &y)

{

    int x0, y0;



    if(!b)

    {

        x = 1;

        y = 0;

    }

    else

    {

        euclid_extins(b, a % b, x0, y0);

        x = y0;

        y = x0 - a / b * y0;

    }



}



int main()

{

    f >> a >> n;

    f.close();



    euclid_extins(a, n, inv, y);



    if(inv < 0)

        inv += n;

    inv %= n;



    g << inv << '\n';

    g.close();



    return 0;

}
