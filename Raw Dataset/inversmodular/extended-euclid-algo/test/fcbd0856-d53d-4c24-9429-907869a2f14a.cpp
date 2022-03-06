#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long dx[] = {0, 1, 0, -1};

const long long dy[] = {1, 0, -1, 0};



const ll inf = 0x3f3f3f3f3f3f3f;



const long long N = 2e5 + 11;



long long a,b;



long long gcd(long long a,long long b,long long &x, long long &y){



    if(!b){

        x = 1;

        y = 0;

        return b;

    }



    long long x0,y0,d;



    d = gcd(b, a%b, x0, y0);



    x = y0;

    y = x0 - y0*(a/b);



    return d;

}





int32_t main(){

ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);



ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");



    cin >> a >> b;



    long long x,y;

    long long dd = gcd(a,b,x,y);



    while(x<0)x+=b;



    return cout<<x,0;





return 0;

}
