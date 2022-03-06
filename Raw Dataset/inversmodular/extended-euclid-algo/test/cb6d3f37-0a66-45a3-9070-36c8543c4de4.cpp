#include <bits/stdc++.h>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



void euclid(int a, int b, int & x, int & y){

    if(!b){

        x = y = 1;

    }

    else{

        int x1, y1;

        euclid(b, a % b, x1, y1);

        x = y1;

        y = x1 - a / b * y1;

    }

}



int main(){

    int a, n, x, y;

    in>>a>>n;

    euclid(a, n, x, y);

    while(x < 0)

        x += n;

    out<<x;

}
