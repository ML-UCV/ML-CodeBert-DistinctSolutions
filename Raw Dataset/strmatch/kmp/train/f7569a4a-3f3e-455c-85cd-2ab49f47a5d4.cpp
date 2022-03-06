#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;



const int INF = 2e9;

const int N = 2e6;



char A[5 + N], B[5 + N], s[5 + 2 * N];

int pi[5 + 2 * N];



vector <int> sol;



int main() {

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

    int lenA, lenB, cnt(0);

    fgets(A, 3 + N, stdin);

    fgets(B, 3 + N, stdin);



    lenA = strlen(A) - 1;

    lenB = strlen(B) - 1;

    for(int i = 0; i < lenA; i++)

        s[i] = A[i];

    s[lenA] = '#';

    for(int i = 0; i < lenB; i++)

        s[i + lenA + 1] = B[i];



    for(int i = 1; i < lenA + lenB + 1; i++) {

        int k = pi[i - 1];

        while(k > 0 && s[i] != s[k])

            k = pi[k - 1];



        if(s[i] == s[k]) k++;

        pi[i] = k;

    }



    for(int i = 0; i < lenA + lenB + 1; i++) {

        if(pi[i] == lenA) {

            if(sol.size() < 1000) {

                sol.push_back(i - lenA + 1);



            }

            cnt++;

        }

    }



    printf("%d\n", cnt);

    for(auto it : sol) printf("%d ", it - lenA - 1);

    return 0;

}
