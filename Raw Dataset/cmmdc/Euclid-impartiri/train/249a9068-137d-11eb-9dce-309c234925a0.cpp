#include <iostream>
#include <fstream>


using namespace std;



int main()

{

    ifstream fin("cmmdc.in");

    ofstream fout("cmmdc.out");



    int x, y, r;



    fin>>x>>y;



    while(y != 0)

    {

        r=x % y;

        x = y;

        y = r;

    }



    if(x != 1)

        fout<<x;

        else fout<<0;

    return 0;

}
