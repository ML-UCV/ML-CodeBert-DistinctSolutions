#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



struct valori

{

    int d;

    int x0;

    int y0;

};



int a, x, b, y, c;



valori f(int a, int b)

{

    if (b==0)

    {

        return {a,1,0};

    }

    valori d=f(b, a%b);

    valori fun;

    fun.x0=d.y0;

    fun.y0=d.x0-(a/b)*d.y0;

    fun.d=d.d;

    return fun;

}







int main()

{



    fin >> a >> b;

    valori r=f(a,b);

    int af=r.x0;

    if (af>b)

        af%=b;

    else while (af<0)

        af+=b;

    fout << af;

    return 0;

}
