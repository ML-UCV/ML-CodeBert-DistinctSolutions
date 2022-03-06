#include <bits/stdc++.h>
using namespace std;

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");

int cmmdc(int a, int b){

while (b){

    int r=a%b;

    a=b;

    b=r;

}

if (a==1) return 0;

return a;



}

int main()

{

    int a, b;

    in>>a>>b;

out<<cmmdc(a,b);

}
