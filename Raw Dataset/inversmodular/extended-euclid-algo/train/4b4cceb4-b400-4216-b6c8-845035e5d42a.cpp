#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("inversmodular.in");
ofstream fout("inversmodular.out");

int x, MOD, temp, ans;

int gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x0, y0;
    int d = gcd(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a/b) * y0;
    return d;
}

int main(){
    fin >> x >> MOD;
    gcd(x, MOD, ans, temp);
    while(ans < 0)
        ans += MOD;
    fout << ans;

    return 0;
}
