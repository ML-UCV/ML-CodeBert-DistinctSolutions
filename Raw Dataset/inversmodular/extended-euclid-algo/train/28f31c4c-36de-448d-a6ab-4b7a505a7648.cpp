#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



typedef long long lint;

typedef pair<lint,lint> gcdres;

gcdres gcd(lint x, lint y){

 if(y == 0){

  return {1, 0};

 }else{

  gcdres res = gcd(y, x%y);

  return {res.second, res.first - res.second*(x/y)};

 }

}



lint invmod(lint a, lint n){

 return (n*100+gcd(a, n).first) % n;

}



lint a, n;



int main(){

 fin >> a >> n;

 fout << invmod(a, n);

 return 0;

}
