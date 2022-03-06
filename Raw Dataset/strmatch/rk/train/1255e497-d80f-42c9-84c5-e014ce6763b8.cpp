#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>




const int MOD1 = 1e9 + 7;

const int MOD2 = 666013;

const int baza = 74;



using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



long long amod1,amod2,bmod1,bmod2;

int n,m;

long long pown_MOD1,pown_MOD2;

int ans[2000005];



int asci(char c){

    return (int)c + 1;

}

string str(int nr){

    string ans;

    while(nr){

        ans += (nr % baza + 'A' - 1);

        nr /= baza;

    }

    reverse(ans.begin(),ans.end());

    return ans;

}



int main()

{

    string a,b;

    in>>a>>b;

    if(a.size() > b.size())

        swap(a,b);

    int n = a.size();

    int m = b.size();

    pown_MOD1 = pown_MOD2 = 1;

    for(int i = 1; i <= n - 1; i++){

        pown_MOD1 = pown_MOD1 * baza % MOD1;

        pown_MOD2 = pown_MOD2 * baza % MOD2;

    }

    for(int i = 0; i < n; i++){

        amod1 = (amod1 * baza + asci(a[i])) % MOD1;

        amod2 = (amod2 * baza + asci(a[i])) % MOD2;

    }

    for(int i = 0; i < n; i++){

        bmod1 = (bmod1 * baza + asci(b[i])) % MOD1;

        bmod2 = (bmod2 * baza + asci(b[i])) % MOD2;

    }

    int index = 0;

    if(amod1 == bmod1 && amod2 == bmod2)

        ans[++index] = 0;

    for(int i = n; i < m; ++i){

        bmod1 = ((bmod1 - asci(b[i - n]) * pown_MOD1) * baza + asci(b[i])) % MOD1;

        bmod1 = (bmod1 + MOD1) % MOD1;

        bmod2 = ((bmod2 - asci(b[i - n]) * pown_MOD2) * baza + asci(b[i])) % MOD2;

        bmod2 = (bmod2 + MOD2) % MOD2;

        if(amod1 == bmod1 && amod2 == bmod2)

            ans[++index] = i - n + 1;

    }



    out<<index<<"\n";

    for(int i = 1; i <= min(index,1000); i++)

        out<<ans[i]<<" ";



    return 0;

}
