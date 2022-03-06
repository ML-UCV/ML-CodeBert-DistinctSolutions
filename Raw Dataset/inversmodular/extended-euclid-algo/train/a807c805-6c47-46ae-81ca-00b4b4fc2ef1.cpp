#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



class Elem

{

public:

    int d, x, y;

    Elem(){};

    Elem(int dd, int xx, int yy)

    {

        d = dd;

        x = xx;

        y = yy;

    }

};



Elem euclid(int a, int b)

{

    if(b == 0)

    {

        Elem e = Elem(a, 1, 0);

        return e;

    }

    Elem d = euclid(b, a%b);

    Elem rez = Elem(d.d, d.y, d.x - (a/b)*d.y);

    return rez;

}



int main()

{

    int a, n;

    fin >> a >> n;

    Elem rez = euclid(a, n);

    rez.x %= n;

    while(rez.x < 0)

        rez.x += n;

    fout << rez.x;

    return 0;

}
