#include <bits/stdc++.h>
using namespace std;



int n, m;

int inv(int a, int b){

    return (a > 1 ? b - 1LL*inv(b%a, a)*b/a : 1);

}



int main(){

    ifstream cin ("inversmodular.in");

    ofstream cout ("inversmodular.out");

    cin >> n >> m;

    cout << inv(n, m);

    return 0;

}
