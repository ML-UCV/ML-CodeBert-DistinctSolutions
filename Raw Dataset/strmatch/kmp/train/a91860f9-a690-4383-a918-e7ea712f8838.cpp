#include <iostream> 
#include <fstream>
#include <vector>
#include <cstring>



using namespace std;






ifstream in("strmatch.in");
ofstream out("strmatch.out");

char A[2000005], B[2000005];
int pi[2000005], v[1004], nr, a, b;

void kmp1(){
    int k = 0;
    for(int i = 1; i <= b; ++i){
        while(k && A[k + 1] != B[i])
            k = pi[k];
        if(A[k + 1] == B[i])
            ++k;
        if(k == a){
            ++nr;
            if(nr <= 1000)
                v[nr] = i;
        }
    }

}

void kmp(){
    int k = 0;
    for(int i = 2; i <= a; ++i){
        while(k && A[k + 1] != A[i])
            k = pi[k];
        if( A[k + 1] == A[i])
            ++k;
        pi[i] = k;
    }
}

int main(){
    in >> (A+1);
    in >> (B+1);
    a = strlen(A+1);
    b = strlen(B+1);

    kmp();
    kmp1();

    out << nr << '\n';
    if(nr>1000) nr=1000;
    for(int i = 1; i <= nr; ++i)
        out << v[i] - a << ' ';
    return 0;


}
