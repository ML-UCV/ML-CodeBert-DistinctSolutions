#include <bits/stdc++.h>
using namespace std;

int merge(int v[], int temp[], int st, int mij, int dr){
    int i = st;
    int j = mij;
    int k = st;
    int count = 0;
    while((i <= mij - 1) && (j <= dr)){
        if(v[i] <= v[j])
            temp[k++] = v[i++];
        else {
            temp[k++] = v[j++];
            count += (mij - i);
            count = count % 9917;
        }
    }
    while(i <= mij - 1)
        temp[k++] = v[i++];
    while (j <= dr)
        temp[k++] = v[j++];
    for(int l = st; l <= dr; l++)
        v[l] = temp[l];
    return count;
}

int nr(int v[], int temp[], int st, int dr){
    int mij = 0;
    int count = 0;
    if (dr > st){
        mij = (dr+st)/2;
        count += nr(v, temp, st, mij);
        count += nr(v, temp, mij + 1, dr);
        count += merge(v, temp, st, mij + 1, dr);
    }
    return count;
}

int mergesort(int v[], int n) {
    int temp[100001];
    return nr(v, temp, 0, n-1);
}


int main() {
    freopen("inv.in", "r", stdin);
    freopen("inv.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int S[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> S[i];
    int raspuns = mergesort(S,n);
    cout << raspuns % 9917;
    return 0;
}
