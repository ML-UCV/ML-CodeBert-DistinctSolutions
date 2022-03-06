#include <bits/stdc++.h>
using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");

int main() {
    int a,b;
    f>>a>>b;
    while(b!=0){
        int c=a%b;
        a=b;
        b=c;
    }
    if(a==1)
        g<<0;
    else g<<a;
}
