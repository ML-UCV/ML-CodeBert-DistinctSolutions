#include <iostream>
#include <fstream>
using namespace std;



void adunare() {

    ifstream in;

    in.open("adunare.in", ios::in);

    int a, b;

    in >> a >> b;

    in.close();

    ofstream out;

    out.open("adunare.out", ios::out);

    if (a + b < 2000000) {

        out << a + b;

    }

    out.close();

}

int main()

{

    ifstream in;

    int a, b , i;

    in.open("cmmdc.in", ios::in);

    in >> a >> b;

    in.close();

    if (a > b) {

        i = a;

        while (a != 0) {

            if (i == 1) {

                i = 0;

                break;

            }

            if (a % i == 0 && b % i == 0) {

                break;

            }

            i--;

        }

    }else {

        i = b;

        while (b != 0) {

            if (i == 1) {

                i = 0;

                break;

            }

            if (b % i == 0 && a % i == 0) {

                break;

            }

            i--;

        }

    }

    ofstream out;

    out.open("cmmdc.out", ios::out);

    if (i < 30001) {

        out << i;

    }

    out.close();



}
