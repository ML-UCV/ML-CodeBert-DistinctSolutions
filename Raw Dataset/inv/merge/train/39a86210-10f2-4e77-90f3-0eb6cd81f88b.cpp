#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using namespace std;


const ll MOD = 9917;
const int INF = INT_MAX;
const int maxN = 100005;

ll n, a[maxN], poz[maxN];

ll swaps = 0;



void interclasare(ll a[], ll left, ll mid, ll right){

    ll i = left;

    ll j = mid + 1;

    ll index = left;



    while (i <= mid && j <= right){

        if (a[i] <= a[j]){

            poz[index] = a[i];

            index++; i++;

        }

        else{

            poz[index] = a[j];

            index++; j++;

            swaps = (swaps + (mid - i + 1)) % MOD;

        }

    }



    while(i <= mid){

        poz[index] = a[i];

        index++; i++;

    }



    while(j <= right){

        poz[index] = a[j];

        index++; j++;

    }



    for (ll i = left; i <= right; i++)

        a[i] = poz[i];

}



void mergesort(ll a[], ll left, ll right){

    if (left < right){

        ll mid = left + (right - left) / 2;

        mergesort(a, left, mid);

        mergesort(a, mid + 1, right);

        interclasare(a, left, mid, right);

    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("inv.in");
    ofstream cout("inv.out");


    cin >> n;

    for (ll i = 0; i < n; i++){

        cin >> a[i];

    }



    mergesort(a, 0LL, n - 1);

    cout << swaps % MOD;

    return 0;
}
