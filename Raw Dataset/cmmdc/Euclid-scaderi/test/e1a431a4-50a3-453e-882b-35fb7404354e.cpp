#include <iostream>
#include <fstream>
using namespace std;

int cmmd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    if (a == 1) {
        return 0;
    }
    return a;
}
int main() {
    ifstream f("cmmdc.in");
    ofstream g("cmmdc.out");
    int a, b;
    f >> a, f >> b;
    g << cmmd(a, b);
}
