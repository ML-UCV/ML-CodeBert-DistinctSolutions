#include <iostream>
#include <fstream>


using namespace std;



typedef pair<int, int> pr;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");





pr ee(int a, int b) {



    if(b == 0) {

        return {1, 0};

    }

    pr r = ee(b, a % b);

    return {r.second, r.first - (a / b) * r.second};

}





int im(int x, int n)

{

    int r = ee(x, n).first;

    if(r < 0) {

        r = n + (r % n);

    }

    return r;

}



int main()

{

    int x = 0, n = 0;



    f >> x >> n;



    g << im(x, n);



    f.close();

    g.close();

    return 0;

}
