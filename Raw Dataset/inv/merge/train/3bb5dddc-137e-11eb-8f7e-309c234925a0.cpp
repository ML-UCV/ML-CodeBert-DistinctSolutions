#include <iostream>
#include <fstream>


const int MAXN = 1e5 + 1,MOD = 9917;



using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



int n,v[MAXN],a[MAXN],b[MAXN];

long long inv = 0;



void combina(int l,int r){

    int mid = (l + r) / 2;

    for(int i = l; i <= mid; i++)

        a[i] = v[i];

    for(int i = mid + 1; i <= r; i++)

        b[i] = v[i];

    int i = l;

    int j = mid + 1;

    int index = l;

    while(i <= mid && j <= r){

        if(a[i] <= b[j]){

            v[index++] = a[i];

            i++;

        }else{

            inv += 1ll * (mid - i + 1);

            inv %= MOD;

            v[index++] = b[j];

            j++;

        }

    }

    while(i <= mid)

        v[index++] = a[i++];

    while(j <= mid)

        v[index++] = b[j++];



}

void divide(int l = 1,int r = n){

    int mid = (l + r) / 2;

    if(l == r)

        return;

    divide(l,mid);

    divide(mid + 1,r);

    combina(l,r);

}





int main()

{

    in>>n;

    for(int i = 1; i <= n; i++)

        in>>v[i];

    divide();

    out<<inv;

    return 0;

}
