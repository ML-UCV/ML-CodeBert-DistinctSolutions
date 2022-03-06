#include <fstream>
#include <vector>




using namespace std;





char const in_file[] = "inversmodular.in";

char const out_file[] = "inversmodular.out";





ifstream Read(in_file);

ofstream Write(out_file);





void GCD(

    uint32_t const first,

    uint32_t const second,

    int64_t &x,

    int64_t &y

) {

    if (second == 0) {

        x = 1;

        y = 0;

        return;

    }



    int64_t x0;

    int64_t y0;

    GCD(second, first % second, x0, y0);



    x = y0;

    y = x0 - (first / second) * y0;

}





int main() {

    uint32_t a;

    uint32_t n;



    Read >> a;

    Read >> n;



    int64_t x;

    int64_t y;

    GCD(a, n, x, y);



    x = x % n + (x < 0 ? n : 0);



    Write << x;



    Read.close();

    Write.close();



    return 0;

}
