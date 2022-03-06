#include <fstream>
#include <queue>

using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

const int sigma= 26;
const int nmax= 50000;

char a[nmax+2], b[nmax+2];
int lc[sigma];

queue <int> q[sigma];
int t[nmax+1];

void bt_upd(int x, int n){
    for (; x<=n; x= 2*x-(x&(x-1))){
        ++t[x];
    }
}

int bt_que(int x){
    int sol= 0;
    for (; x>0; x&= (x-1)){
        sol+= t[x];
    }
    return sol;
}

int main(){
    fin.getline(a, nmax+2);
    fin.getline(b, nmax+2);
    int n;
    for (n= 0; n<=nmax&& a[n]>='a'&& a[n]<='z'; ++n){
        ++lc[a[n]-'a']; --lc[b[n]-'a'];
    }
    for (int i= 0; i<sigma; ++i){
        if (lc[i]!=0){
            fout<<"-1\n";
            return 0;
        }
    }

    for (int i= 1; i<=n; ++i){
        q[b[i-1]-'a'].push(i);

    }
    int sol= 0;
    for (int i= 1; i<=n; ++i){
        int x= q[a[i-1]-'a'].front();
        q[a[i-1]-'a'].pop();
        sol+= x-bt_que(x)-1;
        bt_upd(x, n);
    }
    fout<<sol<<"\n";

    return 0;
}
