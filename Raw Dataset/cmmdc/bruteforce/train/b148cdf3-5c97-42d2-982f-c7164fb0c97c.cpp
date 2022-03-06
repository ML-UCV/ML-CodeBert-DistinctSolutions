#include <iostream>
#include <fstream>


int main() {

    std::ifstream in_file {"cmmdc.in"};

    std::ofstream out_file {"cmmdc.out"};



    if (!in_file || !out_file) {

        std::cerr << "A aparut o problema" << std::endl;

    }



    int a, b, divizor{0};

    in_file >> a >> b;

    if (a >= b)

        divizor = a;

     else

        divizor = b;

    for (int i {divizor}; i > 0; --i) {

        if (i == 1) {

            out_file << "0";

            break;

        } else if (a % i == 0 && b % i == 0) {

            out_file << i;

            break;

        }

    }

    return 0;

}
