#include <iostream>
#include <fstream>


using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int t, x, y;



int cmmdc(int x, int y)

{

    int r;

    while(y)

    {

        r = x % y;

        x = y;

        y = r;

    }

    return x;

}



int main()

{

    f >> x >> y;

    int t = cmmdc(x, y);



    if(t == 1) g << 0;

    else g << t;

    return 0;

}
