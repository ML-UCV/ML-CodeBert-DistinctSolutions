#include <bits/stdc++.h>
using namespace std;

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");



int rest, nr1, nr2;



void cmmddc(int &a,int &b) {

    rest=1;

    while (rest!=0) {

        rest=a%b;

        a=b;

        b=rest;

    }

}

int main()

{

    f >> nr1 >> nr2;

    cmmddc(nr1,nr2);

    if (nr1==1) {

        g << 0;

    }

    else {

        g << nr1;

    }



    return 0;

}
