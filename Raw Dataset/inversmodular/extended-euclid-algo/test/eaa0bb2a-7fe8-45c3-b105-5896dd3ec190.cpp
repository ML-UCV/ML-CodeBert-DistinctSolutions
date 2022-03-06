#include <bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



int a, n;

int x, y, x00, y00;



void cmmdc(int a, int b);



int main()

{



    fin >> a >> n;



    cmmdc(n, a);



    while(y < 0) y += n;



    fout << y;



    return 0;

}



void cmmdc(int a, int b){

    if(!b){

        x = 1;

        y = 0;

        return;

    }

    else{

        cmmdc(b, a % b);

        x00 = y;

        y00 = x - y * (a / b);

        x = x00; y = y00;

    }

}
