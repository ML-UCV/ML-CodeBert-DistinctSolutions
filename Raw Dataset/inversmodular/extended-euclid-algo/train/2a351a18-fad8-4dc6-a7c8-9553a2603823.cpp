#include <iostream>
#include <fstream>

using namespace std;

void find(long long a, long long b, long long *x, long long *y){
 if(b == 0){
  *x = 1;
  *y = 0;

 } else {
 long long x0, y0;
 find(b, a%b, &x0, &y0);
 *x = y0;
 *y = x0 - (a/b)*y0;
   }

}

int main(){
 ifstream fin("inversmodular.in");
 ofstream fout("inversmodular.out");
    long long A, N;
    fin >> A >> N;
    long long x = 0, y;
    find(A, N, &x, &y);
    if(x<=0){
       x = N + x%N;
    }

    fout << x <<'\n';
    return 0;
}
