#include <bits/stdc++.h>



typedef long long ll;



const ll mod=1e9+7;



const int dx[] = {0, 1, 0, -1};

const int dy[] = {1, 0, -1, 0};
using namespace std;



ll t;



int euclid(int a, int b) {

 if (!b)return a;

 else return euclid(b,a%b);

}



int main() {

ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

 ifstream cin("cmmdc.in");

 ofstream cout("cmmdc.out");

 ll a,b;

 cin >> a >> b;

 if (euclid(a,b)==1) {

  cout << "0\n";

 }

 else cout << euclid(a,b)<< '\n';



}
