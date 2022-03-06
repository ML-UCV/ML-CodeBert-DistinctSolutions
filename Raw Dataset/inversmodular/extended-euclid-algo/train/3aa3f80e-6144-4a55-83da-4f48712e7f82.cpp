#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



void euclid(int a, int b, int &c, int &x, int &y)

{

    if(b == 0){

        c = a;

        x = 1;

        y = 0;

    }

    else{

        int x0, y0;

        euclid(b, a%b, c, x0, y0);

        x = y0;

        y = x0 - (a/b)*y0;

    }

}



int main()

{

    int a, n, c, x, y;

    fin >> a >> n;

    euclid(a, n, c, x, y);



    while(x < 0) x += n;



    fout << x;



    return 0;

}
