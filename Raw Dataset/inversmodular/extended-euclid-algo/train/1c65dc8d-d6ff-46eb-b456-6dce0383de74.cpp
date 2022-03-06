#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int a, n, x, y;

pair<int, int> p;



pair <int, int> euclid(int x, int y){

    if(y==0)

        return {1, 0};

    p=euclid(y,x%y);

    return {p.second, p.first - (x/y)*p.second };

}



int main()

{

    f>>a>>n;



    p=euclid(a,n);



    while(p.first<0)

        p.first+=n;



    g<<p.first;

    return 0;

}
