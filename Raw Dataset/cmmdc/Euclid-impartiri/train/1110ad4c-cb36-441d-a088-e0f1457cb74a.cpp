#include <fstream>


std::ifstream fin ("cmmdc.in");

std::ofstream fout ("cmmdc.out");



int main()

{



    int a{};

    int b{};



    fin >> a >> b;



    int r{};



    while (b)

    {

        r = a%b;

        a = b;

        b=r;

    }



    if (a>1)

        fout << a;



    else

        fout << b;





    return 0;



}
