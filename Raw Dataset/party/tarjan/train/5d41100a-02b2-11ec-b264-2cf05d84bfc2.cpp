#include <bits/stdc++.h>
#include <cstdlib>


using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



const int NMax = 1005;



int A[NMax];

int B[NMax];

int C[NMax];

int ans[NMax];



inline bool check(const int &x) {



    if(C[x] == 0) return ans[A[x]] || ans[B[x]];

    if(C[x] == 1) return ans[A[x]] || !ans[B[x]];

    if(C[x] == 2) return !ans[A[x]] || ans[B[x]];

    if(C[x] == 3) return (ans[A[x]] + ans[B[x]]) != 2;

    return false;



}



int main() {



    ios::sync_with_stdio();

    fin.tie(NULL);



    int n, m;

    fin >> n >> m;



    for(int i = 1; i <= m; i++) fin >> A[i] >> B[i] >> C[i];



    for(int i = 1; i <= n; i++) ans[i] = true;



    for(int i = 1; i <= m; i++) {



        if(check(i) == false) {

            int ran = rand() % 2;

            if(ran == 1) {

                ans[B[i]] = !ans[B[i]];

            } else {

                ans[A[i]] = !ans[A[i]];

            }



            i = 0;

        }

    }



    int no = 0;

    for(int i = 1; i <= n; i++) {

        if(ans[i] == true) no++;

    }



    fout << no << "\n";



    for(int i = 1; i <= n; i++) {

        if(ans[i] == true) fout << i << "\n";

    }



    return 0;

}
