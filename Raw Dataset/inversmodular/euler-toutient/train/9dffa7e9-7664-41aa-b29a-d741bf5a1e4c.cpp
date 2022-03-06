#include <bits/stdc++.h>
using namespace std;

ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");

long long N, M, ans = 1, Phii;

long long Phi (long long A){

 long long ret = A;

 for (long long i = 2; i * i <= A; i ++){

  if (!(A % i)){

   while (A % i == 0)A /= i;

   ret = (ret / i) * (i - 1);

  }

 }

    if (A != 1)ret = ret / A * (A - 1);

 return ret;

}

int main (){

    fin >> N >> M;

    Phii = Phi (M) - 1;

    for (long long pw = 1; pw <= Phii; pw <<= 1){

   if (pw & Phii)ans = (ans * N) % M;

    N = (N * N) % M;

 }

 fout << ans;

 return 0;

}
