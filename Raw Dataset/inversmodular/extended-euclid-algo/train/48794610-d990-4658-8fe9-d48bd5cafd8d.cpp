#include <fstream>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int a, n;





pair<long long, long long> euclid_ext(int x, int y)

{

    if(y == 0)

    {

        return {1, 0};

    }

    pair<long long, long long> p = euclid_ext(y, x%y);

    return {p.second, p.first-(x/y)*p.second};

}





int main()

{

    f>>a>>n;

    pair<long long, long long> rez = euclid_ext(a, n);

    while(rez.first < 0)

        rez.first += n;

    g<<rez.first;





    return 0;

}
