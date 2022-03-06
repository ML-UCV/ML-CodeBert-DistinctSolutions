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



const int N = 2e6;

const int MOD1 = 666013;

const int MOD2 = 269696969;

const int BASE = 67;



char A[5 + N], B[5 + N];

bool sol[5 + N];



int main() {

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

    long long lenA, lenB, hashA1, hashA2, hashB1, hashB2, pow1, pow2;

    fgets(A, 3 + N, stdin);

    fgets(B, 3 + N, stdin);

    lenA = strlen(A) - 1;

    lenB = strlen(B) - 1;



    if(lenA > lenB) {

        printf("0\n");

        return 0;

    }



    hashA1 = hashA2 = 0;

    pow1 = pow2 = 1;



    for(int i = 0; i < lenA; i++) {

        hashA1 = (hashA1 * BASE + A[i]) % MOD1;

        hashA2 = (hashA2 * BASE + A[i]) % MOD2;

        if(i > 0) {

            pow1 = (pow1 * BASE) % MOD1;

            pow2 = (pow2 * BASE) % MOD2;

        }

    }



    hashB1 = hashB2 = 0;

    for(int i = 0; i < lenA; i++) {

        hashB1 = (hashB1 * BASE + B[i]) % MOD1;

        hashB2 = (hashB2 * BASE + B[i]) % MOD2;

    }

    int k = 0;



    if(hashA1 == hashB1 && hashA2 == hashB2) {

        sol[0] = true;

        k++;

    }

    for(int i = lenA; i < lenB; i++) {

        hashB1 = ((hashB1 - (B[i - lenA] * pow1) % MOD1 + MOD1) * BASE + B[i]) % MOD1;

        hashB2 = ((hashB2 - (B[i - lenA] * pow2) % MOD2 + MOD2) * BASE + B[i]) % MOD2;



        if(hashA1 == hashB1 && hashA2 == hashB2) {

            k++;

            sol[i - lenA + 1] = true;

        }

    }



    printf("%d\n", k);

    k = 0;

    for(long long i = 0; i < lenB && k < 1000; i++) {

        if(sol[i] == true) {

            k++;

            printf("%lld ", i);

        }

    }

    printf("\n");

    return 0;

}
