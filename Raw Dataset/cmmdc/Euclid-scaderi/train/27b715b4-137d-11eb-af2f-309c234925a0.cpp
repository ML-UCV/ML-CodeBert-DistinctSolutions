#include <iostream>
#include <fstream>


using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a, b;

int cmmdc (int a, int b)

{

    if (a==b)

        if (a==1)

            return 0;

        else

            return a;

    else

        if (a>b)

        return cmmdc(a-b,b);

    else

        return cmmdc(a,b-a);

}

int main()

{

    f >> a >> b;

    g << cmmdc(a,b);



    f.close();

    g.close();



    return 0;

}
