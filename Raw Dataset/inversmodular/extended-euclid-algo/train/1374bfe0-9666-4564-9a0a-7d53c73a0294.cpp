#include <bits/stdc++.h>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int x,y;

int a,n;



void euclid_extins(int a, int b) {

    if (b!=0) {

        euclid_extins(b,a%b);

    }

    if (b==0) {

        x = 1;

        y = 0;

    }

    else {

        int aux = x;

        x = y;

        y = aux - (a/b)*y;

    }

}



int main()

{

    f >> a >> n;

    euclid_extins(a,n);

    if (x<1) {

        int need = x-1;

        need = -need;

        if (need%n==0) {

            x += need;

        }

        else {

            need /= n;

            need++;

            x += need*n;

        }

    }

    g << x;

    return 0;

}
