#include <fstream>
#include <cmath>


int mic(int x, int y)

{

    for (int temp = y; temp >= 2; temp--)

        if ((x % temp == 0) && (y % temp == 0))

            return temp;

    return 0;

}



main()

{

    std::ifstream fin("cmmdc.in", std::ios::in);

    unsigned short int a, b;

    fin >> a >> b;

    fin.close();

    std::ofstream fout("cmmdc.out", std::ios::out);

    fout << mic(std::max(a,b),std::min(a,b));

    fout.close();

}
