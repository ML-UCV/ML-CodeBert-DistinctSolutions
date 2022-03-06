#include <iostream>
#include <fstream>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



typedef long long ll;



ll modulo;



ll cmmdc(ll a, ll b, ll &x, ll &y){

  if(b == 0){

    x = 1;

    y = 0;

    return a;

  }else{

    ll ans = cmmdc(b, a % b, x, y);

    ll xPrim = x, yPrim = y;

    x = yPrim % modulo;

    y = (xPrim - (a / b) * yPrim) % modulo;

    return ans;

  }

}



int main()

{

  ll n, m, x, y, ans;

  in >> n >> m;

  modulo = m;

  ans = cmmdc(n, m, x, y);

  x = x % m;

  if(x < 0)

    x += m;

  out << x;

  return 0;

}
